from tkinter import *
import tkinter as tk
from tkinter import ttk

class DeleteGUI():
    def __init__(self, window2):
        self.window2 = window2
        self.window2.title("delete")
        self.window2.geometry("400x250")

        columns = ("tournament_name", "date", "sport_name", "winners_name", "prize_money", "earning")
        self.search_table = ttk.Treeview(columns=columns, show="headings")
        self.search_table.heading("tournament_name", text="Название турнира")
        self.search_table.heading(1, text="Дата проведения")
        self.search_table.heading(2, text="Название вида спорта")
        self.search_table.heading(3, text="ФИО победителя")
        self.search_table.heading(4, text="Размер призовых турнира") 
        self.search_table.heading(5, text="Заработок победителя")
        self.search_table.grid(row=0, column=0, columnspan=6)
        self.view_loading()

    def view_loading(self, model_base):
        for i in model_base.loading():
                self.search_table.insert("", tk.END, values=i)

