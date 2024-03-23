from tkinter import *
import tkinter as tk
from tkinter import ttk
import tkinter.messagebox as mb

class DeleteGUI():
        def __init__(self, model_base, parent):
                self.parent = parent
                self.window2 = tk.Toplevel()
                self.window2.title("delete")
                self.window2.geometry("400x250")

                self.model_base = model_base

                # columns = ("tournament_name", "date", "sport_name", "winners_name", "prize_money", "earning")
                # self.delete_table = ttk.Treeview(self.window2,columns=columns, show="headings")
                # self.delete_table.heading("tournament_name", text="Название турнира")
                # self.delete_table.heading(1, text="Дата проведения")
                # self.delete_table.heading(2, text="Название вида спорта")
                # self.delete_table.heading(3, text="ФИО победителя")
                # self.delete_table.heading(4, text="Размер призовых турнира") 
                # self.delete_table.heading(5, text="Заработок победителя")
                # self.delete_table.grid(row=0, column=0, columnspan=6)

                self.check = IntVar(value=0)
                but1 = ttk.Radiobutton(self.window2,text="По названию турнира",value=1, variable=self.check,command=self.__create_combo1)
                but1.grid(row=1, column=0)
                but2 = ttk.Radiobutton(self.window2,text="По виду спорта", value=2, variable=self.check, command=self.__create_combo2)
                but2.grid(row=1, column=1)
                but3 = ttk.Radiobutton(self.window2,text="По величине выигрыша", value=3, variable=self.check)
                but3.grid(row=1, column=2)
                self.combobox=None

                but4 = tk.Button(self.window2,text="Удалить", command=self.delete_command)
                but4.grid(row=3,column=0, pady=5)

                # self._view_loading()
                self.window2.mainloop()

        # def _view_loading(self, new_model=None):
        #         for item in self.delete_table.get_children():
        #                 self.delete_table.delete(item)

        #         if new_model is not None:
        #                 lis_base = new_model
        #         else:
        #                 lis_base = self.model_base.loading()

        #         for i in lis_base:
        #                 self.delete_table.insert("", tk.END, values=i)

        def __create_combo1(self):
                self.combobox = ttk.Combobox(self.window2, values=self.__combo_func1())
                self.combobox.grid(row= 2, column = 0)

        def __combo_func1(self):
                val = []
                for i in self.model_base.help_search_by_tournament():
                        val.append(*i)
                return val
        
        def __create_combo2(self):
                self.combobox = ttk.Combobox(self.window2, values=self.__combo_func2())
                self.combobox.grid(row= 2, column = 1)

        def __combo_func2(self):
                val = []
                for i in self.model_base.help_search_by_sport():
                        val.append(*i)
                return val
        
        def delete_command(self):
                num_deleted = self.model_base.delete(num=self.check.get(), searching=self.combobox.get())
                if num_deleted > 0:
                        msg = f"{num_deleted} records deleted."
                else:
                        msg = "No records matching the specified criteria were found."
                mb.showinfo("Информация", msg)
                self.parent.load_page()
