from psycopg2 import *
import psycopg2 as ps
from view.view_interf import *

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

    def loading(self):
        request_to_read_data = "SELECT * FROM TOURNAMENTS"

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
        print(data, type(data)) 
        return data[-1]

    def close_connection(self):
        self._cursor.close()
        self._connection.close()