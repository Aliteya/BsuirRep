from tkinter import *
import tkinter as tk
from tkinter import ttk
from tkcalendar import DateEntry
from model.model_gui_methods import *

class Interface():
        def __init__(self):
                self.window = Tk()
                self.window.title("start window")
                self.window.geometry("400x250")
                
                columns =("tournament_name", "date", "sport_name", "winners_name", "prize_money", "earning")
                self.table = ttk.Treeview(columns=columns, show="headings")
                

        def visual_start(self):
                self.table.heading("tournament_name", text="Название турнира")
                self.table.heading(1, text="Дата проведения")
                self.table.heading(2, text="Название вида спорта")
                self.table. heading(3, text="ФИО победителя")
                self.table.heading(4, text="Размер призовых турнира") 
                self.table.heading(5, text="Заработок победителя")
                self.table.grid(row=0, column=0, columnspan=6, pady=20)

        def view_loading(self, model_base):
                for i in model_base.loading():
                        self.table.insert("", tk.END, values=i)
        
                   
        def gui_new_entries(self, model_base):
                tournament_name = tk.Entry()
                tournament_name.grid(row = 2, column = 0,  pady = 5)
                date =  DateEntry()
                date.grid(row = 2, column = 1, pady = 5)
                sport_name = tk.Entry()
                sport_name.grid(row = 2, column = 2,  pady = 5)
                winners_name = tk.Entry()
                winners_name.grid(row = 2, column = 3,  pady = 5)
                prize_money = tk.Entry()
                prize_money.grid(row = 2, column = 4,  pady = 5)
                new_entry_button = tk.Button(text="Ввод",  command=lambda: self.table.insert("", tk.END, values=model_base.new_entry((tournament_name.get(), date.get(), sport_name.get(), winners_name.get(), int(prize_money.get())))))
                new_entry_button.grid(row = 3, column = 3, pady = 5)
                self.window.mainloop()


        # def close_interface(self):
        #         self.window.mainloop()
