from psycopg2 import *
import psycopg2 as ps

class ModelBase:
    def __init__(self, host, port, database, user, password):
        if not port or not database or not user or not password:
            print("Ошибка: не все переменные окружения установлены корректно.")
            exit(1)

        try:

            self._connection = ps.connect(
                host=host,
                port=port,
                database=database,
                user=user,
                password=password
            )
            print("Успешное подключение к базе данных PostgreSQL")
            self._cursor = self._connection.cursor()

        except ps.Error as e:
            print(f"base open error: {e}")
    
    def create_table(self):
        tournament_tb = ''' 
            CREATE TABLE IF NOT EXISTS tournaments(
                tournament_name VARCHAR(70),
                date DATE,
                sport_name VARCHAR(20),
                winners_name VARCHAR(40),
                prize_money INT,
                earning INT
            );
        '''

        self._cursor.execute(tournament_tb)
        self._connection.commit()

    def loading(self, offset=0, limit=None):
        if limit is None:
            request_to_read_data = "SELECT * FROM TOURNAMENTS"
        else:
            request_to_read_data = f"SELECT * FROM TOURNAMENTS OFFSET {offset} LIMIT {limit}"

        self._cursor.execute(request_to_read_data)
        data = self._cursor.fetchall()
        return data

    def new_entry(self, entry: tuple):
        tournament_name, date, sport_name, winners_name, prize_money = entry
        earning = 0.6 * prize_money
        request_to_insert_data = '''
        INSERT INTO tournaments (tournament_name, date, sport_name,
          winners_name, prize_money, earning) VALUES (%s,%s,%s,%s,%s,%s)
        '''
        self._cursor.execute(request_to_insert_data, (tournament_name, date, sport_name,
          winners_name, prize_money, earning))
        self._connection.commit()
        
        request_to_read_data = "SELECT * FROM TOURNAMENTS"

        self._cursor.execute(request_to_read_data)
        data = self._cursor.fetchall()
        return data[-1]

    def help_search_by_tournament(self):
        dist_request = "SELECT DISTINCT tournament_name FROM tournaments"
        self._cursor.execute(dist_request)
        data = self._cursor.fetchall()
        return data
    
    def help_search_by_sport(self):
        dist_request = "SELECT DISTINCT sport_name FROM tournaments"
        self._cursor.execute(dist_request)
        data = self._cursor.fetchall()
        return data

    def search(self, num:int, searching="", max_lim=0, min_lim=0):
        request_to_search = "SELECT * FROM tournaments"
        match num:
            case 1:
                request_to_search = f"SELECT * FROM tournaments WHERE tournament_name = '{searching}';"
            case 2: 
                request_to_search = f"SELECT * FROM tournaments WHERE sport_name = '{searching}';"
            case 3:
                request_to_search = f"SELECT * FROM tournaments WHERE earning > {min_lim} AND earning < {max_lim}; "
        self._cursor.execute(request_to_search)
        data = self._cursor.fetchall()
        return data

    def delete(self, num:int, searching="", max_lim=0, min_lim=0):
        request_to_delete = None
        match num:
            case 1:
                request_to_delete = f"DELETE FROM tournaments WHERE tournament_name = '{searching}';"
            case 2: 
                request_to_delete = f"DELETE FROM tournaments WHERE sport_name = '{searching}';"
            case 3:
                request_to_delete = f"DELETE FROM tournaments WHERE earning > {min_lim} AND earning < {max_lim}; "
        if request_to_delete:
            self._cursor.execute(request_to_delete)
            num_deleted = self._cursor.rowcount
            self._connection.commit()
            return num_deleted
        
    def clean_base(self):
        request_clean = "DELETE FROM tournaments"
        self._cursor.execute(request_clean)
        self._connection.commit()


    def close_connection(self):
        self._cursor.close()
        self._connection.close()
