import psycopg2 as ps
from dotenv import load_dotenv
import os
from model.model_base import *
from view.view_interf import *
from controller.controller_base import *


def load_config():
    load_dotenv()
    host = 'localhost'
    port = os.getenv('BASE_PORT')
    database = 'ppois2base'
    user = 'Aliteya'
    password = os.getenv('BASE_PASSWORD') 
    base = ModelBase(host, port, database, user, password)
    base.create_table()
    
    gui = Interface(base)
    # base2 = ControllerBase(base, gui)
    
    # base2.insert_entry()
    base.close_connection()