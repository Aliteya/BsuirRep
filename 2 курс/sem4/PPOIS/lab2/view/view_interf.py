from tkinter import *
import tkinter as tk
from tkinter import ttk
from tkcalendar import DateEntry
from view.search_gui import SearchGUI
from view.delete_gui import DeleteGUI
from model.model_base import ModelBase

class Interface():
        def __init__(self, model_base:ModelBase):
                self.window = Tk()
                self.window.title("start window")
                self.window.geometry("800x600")           

                self.search_window = None
                self.delete_window = None
                
                self.model_base = model_base

                search_button = tk.Button(text="Поиск", command=self.open_search_gui)
                search_button.grid(row=0, column = 0, pady=20)
                delete_button = tk.Button(text="Удаление", command=self.open_delete_gui)
                delete_button.grid(row= 0, column = 1, pady=20)  
                
                main_frame = ttk.Labelframe(text="tournaments", borderwidth=1, relief=SOLID, padding=[4, 8])
                
                columns =("tournament_name", "date", "sport_name", "winners_name", "prize_money", "earning")
                self.table = ttk.Treeview(main_frame, columns=columns, show="headings")
                self.table.heading("tournament_name", text="Название турнира")
                self.table.heading(1, text="Дата проведения")
                self.table.heading(2, text="Название вида спорта")
                self.table. heading(3, text="ФИО победителя")
                self.table.heading(4, text="Размер призовых турнира") 
                self.table.heading(5, text="Заработок победителя")
                self.table.grid(row=2, column=0, columnspan=6, pady=20)
                
                main_frame.grid(row=1 , column=0, columnspan=7)
                
                new_entry_frame = ttk.Labelframe(text="add new entry")
                
                self.tournament_name = tk.Entry(new_entry_frame)
                self.tournament_name.grid(row = 4, column = 0,  pady = 20)
                self.date =  DateEntry(new_entry_frame)
                self.date.grid(row = 4, column = 1, pady = 20)
                self.sport_name = tk.Entry(new_entry_frame)
                self.sport_name.grid(row = 4, column = 2,  pady = 20)
                self.winners_name = tk.Entry(new_entry_frame)
                self.winners_name.grid(row = 4, column = 3,  pady = 20)
                self.prize_money = tk.Entry(new_entry_frame)
                self.prize_money.grid(row = 4, column = 4,  pady = 20)
              
                new_entry_button = tk.Button(new_entry_frame, text="Ввод",  command=self._gui_new_entries)
                new_entry_button.grid(row = 5, column = 3, pady = 20)
                
                new_entry_frame.grid(row=3, column=0, columnspan=7)


                self._view_loading()

                self.window.mainloop()
                
                
        def _view_loading(self):
                        for i in self.model_base.loading():
                                self.table.insert("", tk.END, values=i)

          
        def _gui_new_entries(self):
                return self.table.insert("", tk.END, values=self.model_base.new_entry((self.tournament_name.get(), self.date.get(), self.sport_name.get(), self.winners_name.get(), int(self.prize_money.get()))))


        def open_search_gui(self):
                self.search_window = SearchGUI(self.model_base)
               
        def open_delete_gui(self):
                pass
               # self.delete_window = DeleteGUI(tk.Toplevel())
