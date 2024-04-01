from tkinter import *
import tkinter as tk
from tkinter import ttk
import tkinter.messagebox as mb

class DeleteGUI():
        def __init__(self, model_base, parent):
                self.parent = parent
                self.window2 = tk.Toplevel()
                self.window2.title("delete")
                self.window2.geometry()

                self.model_base = model_base

                self.check = IntVar(value=0)
                but1 = ttk.Radiobutton(self.window2,text="По названию турнира",value=1, variable=self.check,command=self.__create_combo1)
                but1.grid(row=1, column=0)
                but2 = ttk.Radiobutton(self.window2,text="По виду спорта", value=2, variable=self.check, command=self.__create_combo2)
                but2.grid(row=1, column=1)
                but3 = ttk.Radiobutton(self.window2,text="По величине выигрыша", value=3, variable=self.check, command=self.__combo_func3)
                but3.grid(row=1, column=2)
                self.combobox=None

                self.min_money = IntVar(value=100)
                self.max_money = IntVar(value=100)
                
                but4 = tk.Button(self.window2,text="Удалить", command=self.delete_command)
                but4.grid(row=3,column=0, pady=5)

                self.window2.mainloop()

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
        
        def __combo_func3(self):  
                ttk.Label(self.window2, textvariable=self.min_money).grid(row=2, column=3)
                min_money_scale = ttk.Scale(self.window2, orient=HORIZONTAL, length=200, from_=10, to=700, variable=self.min_money)
                min_money_scale.grid(row=2, column=2)
                
                ttk.Label(self.window2, textvariable=self.max_money).grid(row=3, column=3)
                max_money_scale = ttk.Scale(self.window2, orient=HORIZONTAL, length=200, from_=10, to=700, variable=self.max_money)
                max_money_scale.grid(row=3, column=2)
        
        def delete_command(self):
                if self.combobox is not None:
                        num_deleted = self.model_base.delete(num=self.check.get(), searching=self.combobox.get())
                else:
                        num_deleted = self.model_base.delete(num=self.check.get(), min_lim=self.min_money.get(), max_lim=self.max_money.get())
                if num_deleted > 0:
                        msg = f"{num_deleted} records deleted."
                else:
                        msg = "No records matching the specified criteria were found."
                mb.showinfo("Информация", msg)
                self.parent.total_pages = self.parent.calculate_total_pages()
                self.parent.update_page_label() 
                self.parent.load_page(self.parent.list_on_page)
