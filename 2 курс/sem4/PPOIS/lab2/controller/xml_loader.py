import xml.etree.ElementTree as ET
from datetime import datetime

class parser():
    def __init__(self, filename='xml1_file.xml'):   
        self.filename = filename 
        self.tree = ET.parse(self.filename)
        self.root = self.tree.getroot()

    def from_xml(self):
        data = []
        for tournament in self.root.findall('tournament'):
            tournament_name_elem = tournament.find('tournament_name')
            tournament_name = tournament_name_elem.text if tournament_name_elem is not None else ""

            date_elem = tournament.find('date')
            date = date_elem.text if date_elem is not None else ""

            sport_name_elem = tournament.find('sport_name')
            sport_name = sport_name_elem.text if sport_name_elem is not None else ""

            winners_name_elem = tournament.find('winners_name')
            winners_name = winners_name_elem.text if winners_name_elem is not None else ""

            prize_money_elem = tournament.find('prize_money')
            prize_money = int(prize_money_elem.text) if prize_money_elem is not None else 0

            data.append((tournament_name, date, sport_name, winners_name, prize_money))
        return data

    
    def to_xml(self, data):
        self.root = ET.Element("catalog")
        j = 1
        for record in data:
            tournament = ET.SubElement(self.root, "tournament")
            tournament.set("id", str(j))
            j += 1
            tournament_name = ET.SubElement(tournament, "tournament_name")
            tournament_name.text = record[0] 
            date =ET.SubElement(tournament, "date")
            date.text = record[1].strftime('%Y-%m-%d')
            sport_name = ET.SubElement(tournament, "sport_name")
            sport_name.text = record[2] 
            winners_name = ET.SubElement(tournament, "winners_name")
            winners_name.text = record[3] 
            prize_money = ET.SubElement(tournament, "prize_money")
            prize_money.text = str(record[4]) 
        self.tree = ET.ElementTree(self.root)
        self.tree.write(self.filename, encoding='utf-8', xml_declaration=True)

        

