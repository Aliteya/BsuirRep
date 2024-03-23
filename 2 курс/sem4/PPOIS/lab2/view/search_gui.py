from tkinter import *
import tkinter as tk
from tkinter import ttk

class SearchGUI():
        def __init__(self, model_base):
                self.window1 = tk.Toplevel()
                self.window1.title("search")
                self.window1.geometry("400x250")

                self.model_base = model_base

                columns = ("tournament_name", "date", "sport_name", "winners_name", "prize_money", "earning")
                self.search_table = ttk.Treeview(self.window1,columns=columns, show="headings")
                self.search_table.heading("tournament_name", text="Название турнира")
                self.search_table.heading(1, text="Дата проведения")
                self.search_table.heading(2, text="Название вида спорта")
                self.search_table.heading(3, text="ФИО победителя")
                self.search_table.heading(4, text="Размер призовых турнира") 
                self.search_table.heading(5, text="Заработок победителя")
                self.search_table.grid(row=0, column=0, columnspan=6)

                self.check = IntVar(value=0)
                but1 = ttk.Radiobutton(self.window1,text="По названию турнира",value=1, variable=self.check,command=self.__create_combo1)
                but1.grid(row=1, column=0)
                but2 = ttk.Radiobutton(self.window1,text="По виду спорта", value=2, variable=self.check, command=self.__create_combo2)
                but2.grid(row=1, column=1)
                but3 = ttk.Radiobutton(self.window1,text="По величине выигрыша", value=3, variable=self.check)
                but3.grid(row=1, column=2)
                self.combobox=None

                but4 = tk.Button(self.window1,text="Искать", command=self.search_command)
                but4.grid(row=3,column=0, pady=5)

                self._view_loading()
                self.window1.mainloop()

        def _view_loading(self, new_model=None):
                for item in self.search_table.get_children():
                        self.search_table.delete(item)

                if new_model is not None:
                        lis_base = new_model
                else:
                        lis_base = self.model_base.loading()

                for i in lis_base:
                        self.search_table.insert("", tk.END, values=i)

        def __create_combo1(self):
                self.combobox = ttk.Combobox(self.window1, values=self.__combo_func1())
                self.combobox.grid(row= 2, column = 0)

        def __combo_func1(self):
                val = []
                for i in self.model_base.help_search_by_tournament():
                        val.append(*i)
                return val
        
        def __create_combo2(self):
                self.combobox = ttk.Combobox(self.window1, values=self.__combo_func2())
                self.combobox.grid(row= 2, column = 1)

        def __combo_func2(self):
                val = []
                for i in self.model_base.help_search_by_sport():
                        val.append(*i)
                return val
        
        def search_command(self):
                new_model = self.model_base.search(num=self.check.get(), searching=self.combobox.get())
                self._view_loading(new_model)
            
                