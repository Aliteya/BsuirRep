from tkinter import *
import tkinter as tk
from tkinter import ttk
import tkinter.messagebox as mb
from tkcalendar import DateEntry
from view.search_gui import SearchGUI
from view.delete_gui import DeleteGUI
from model.model_base import ModelBase
from controller.xml_loader import parser
import math

class Interface():
        def __init__(self, model_base:ModelBase):
                self.window = Tk()
                self.window.title("start window")
                self.window.geometry()           

                self.search_window = None
                self.delete_window = None
                
                self.model_base = model_base
                self.parser = None

                self.page_amount = 0
                
                self.page_number = 1
                self.list_on_page = 5

                search_button = tk.Button(text="Поиск", command=self.open_search_gui)
                search_button.grid(row=0, column = 0, pady=20)

                delete_button = tk.Button(text="Удаление", command=self.open_delete_gui)
                delete_button.grid(row= 0, column = 1, pady=20)  

                enabled_button = ttk.Button(text="Включить вид дерева", command=self._tree_view)
                enabled_button.grid(row=0, column=2, pady=20)

                load_xml_button = tk.Button(text="Загрузить xml", command=self._parse_from)
                load_xml_button.grid(row=0, column=3, pady=20)

                save_xml_button = tk.Button(text="Сохранить xml", command=self._save_to)
                save_xml_button.grid(row=0, column=4, pady=20)

                clean_base_button = tk.Button(text="Очистить", command=self._cleaning)
                clean_base_button.grid(row=0, column=5, pady=20)
                
                main_frame = ttk.Labelframe(text="tournaments", borderwidth=1, relief=SOLID, padding=[4, 8])
                
                columns =("tournament_name", "date", "sport_name", "winners_name", "prize_money", "earning")
                self.table = ttk.Treeview(main_frame, columns=columns, show="headings")
                self.table.heading("tournament_name", text="Название турнира")
                self.table.heading(1, text="Дата проведения")
                self.table.heading(2, text="Название вида спорта")
                self.table. heading(3, text="ФИО победителя")
                self.table.heading(4, text="Размер призовых турнира") 
                self.table.heading(5, text="Заработок победителя")
                self.table.grid(row=2, column=0, columnspan=4, pady=20)
                
                main_frame.grid(row=1 , column=0, columnspan=6)
                
                new_entry_frame = ttk.Labelframe(text="add new entry", borderwidth=1, relief=SOLID, padding=[4, 8])
                
                self.tournament_name_label = tk.Label(new_entry_frame, text="Tournament name:")
                self.tournament_name_label.grid(row = 3, column = 0,  pady = 10)
                self.tournament_name = tk.Entry(new_entry_frame)
                self.tournament_name.grid(row = 4, column = 0,  pady = 10)
                self.date_label =  tk.Label(new_entry_frame, text="Date")
                self.date_label.grid(row = 3, column = 1, pady = 10)                
                self.date =  DateEntry(new_entry_frame)
                self.date.grid(row = 4, column = 1, pady = 10)
                self.sport_name_label = tk.Label(new_entry_frame, text="Sport name")
                self.sport_name_label.grid(row = 3, column = 2,  pady = 10)
                self.sport_name = tk.Entry(new_entry_frame)
                self.sport_name.grid(row = 4, column = 2,  pady = 10)
                self.winners_name_label = tk.Label(new_entry_frame, text="Winners name")
                self.winners_name_label.grid(row = 3, column = 3,  pady = 10)
                self.winners_name = tk.Entry(new_entry_frame)
                self.winners_name.grid(row = 4, column = 3,  pady = 10)
                self.prize_money_label = tk.Label(new_entry_frame, text="Prize money")
                self.prize_money_label.grid(row = 3, column = 4,  pady = 10)
                self.prize_money = tk.Entry(new_entry_frame)
                self.prize_money.grid(row = 4, column = 4,  pady = 10)
              
                new_entry_button = tk.Button(new_entry_frame, text="Ввод",  command=self._gui_new_entries)
                new_entry_button.grid(row = 5, column = 3, pady = 20)
                
                new_entry_frame.grid(row=4, column=2, columnspan=7)

                self.total_records = len(self.model_base.loading())
         
                self.page_label = tk.Label(self.window, text=f"Number of page: {self.page_amount}")
                self.page_label.grid(row=2, column=0, pady=10)
                
                self.rec_label= tk.Label(self.window, text=f"Number of records: {self.total_records}")
                self.rec_label.grid(row=2, column=2, pady=10)


                

                self.total_pages = self.calculate_total_pages()
                self.update_page_label() 
                
               
                self.load_page(self.list_on_page)

                first_page_button = tk.Button(self.window, text="First", command=self.first_page)
                first_page_button.grid(row=3, column=0, pady=10)

                last_page_button = tk.Button(self.window, text="Last", command=self.last_page)
                last_page_button.grid(row=3, column=1, pady=10)

                prev_button = tk.Button(self.window, text="Prev", command=self.prev_page)
                prev_button.grid(row=4, column=0, pady=10)

                next_button = tk.Button(self.window, text="Next", command=self.next_page)
                next_button.grid(row=4, column=1, pady=10)


                page_val = [5, 10, 15]
                self.page_var = StringVar(value=page_val[0])
                page_combo = ttk.Combobox(textvariable=self.page_var, values=page_val)
                page_combo.grid(row= 3, column=2)
                page_combo.bind("<<ComboboxSelected>>", self.selected)

                self.window.mainloop()
        
        def selected(self, event):
                self.list_on_page = int(self.page_var.get())
                self.total_pages = self.calculate_total_pages()
                self.load_page(self.list_on_page)

        def _cleaning(self):
                self.model_base.clean_base()
                self.total_pages = self.calculate_total_pages()
                self.update_page_label() 
                self.load_page(self.list_on_page)


        def _parse_from(self):
                window3 = tk.Toplevel()
                window3.title("Choose file")
                file_but1 = tk.Button(window3, text="file1", command=lambda: self.__choose_file(1))
                file_but1.grid(row=0, column=0)
                file_but2 = tk.Button(window3, text="file2", command=lambda: self.__choose_file(2))
                file_but2.grid(row=1, column=0)
                

        def __choose_file(self, file):
                filename = "xml"+str(file)+"_file.xml"
                self.parser = parser(filename)
                data = self.parser.from_xml()
                for i in data:
                        self.model_base.new_entry(i)
                self.total_pages = self.calculate_total_pages()
                self.update_page_label() 
                self.load_page(self.list_on_page)

        def _save_to(self):
                if self.parser is None:
                        mgs = "Parser is not initialized properly"
                        mb.showerror("error", mgs)
                        return
                data = self.model_base.loading()
                if data is None:
                        mgs = "no records"
                        mb.showerror("error", mgs)
                else:    
                        self.parser.to_xml(data)
        
        def _tree_view(self):
                tree_window = tk.Toplevel()
                tree_window.title("TreeView")

                canvas = tk.Canvas(tree_window)
                canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

                scrollbar = ttk.Scrollbar(tree_window, orient=tk.VERTICAL, command=canvas.yview)
                scrollbar.pack(side=tk.RIGHT, fill=tk.Y)

                canvas.configure(yscrollcommand=scrollbar.set)

                frame = ttk.Frame(canvas)
                canvas.create_window((0, 0), window=frame, anchor=tk.NW)

                i, j = 0, 0
                for record in self.model_base.loading():
                        record_frame = ttk.Labelframe(frame, text=f"Tournament: {record[0]}")
                        record_frame.grid(row=i, column=j, padx=10, pady=5)

                        tree = ttk.Treeview(record_frame, columns=("Field", "Value"), show="tree")
                        tree.grid(row=i, column=j)

                        tree.insert("", tk.END, text="Tournament Name", values=(record[0]))
                        tree.insert("", tk.END, text="Date", values=(record[1]))
                        tree.insert("", tk.END, text="Sport Name", values=(record[2]))
                        tree.insert("", tk.END, text="Winner's Name", values=(record[3]))
                        tree.insert("", tk.END, text="Prize Money", values=(record[4]))
                        tree.insert("", tk.END, text="Earning", values=(record[5]))

                        i += 1
                        if i % 10 == 0:
                                j += 1
                                i = 0

                def configure(event):
                        canvas.configure(scrollregion=canvas.bbox("all"))

                frame.bind("<Configure>", configure)

                tree_window.mainloop()

        # def load_base(self):
                # return self.load_page(self.list_on_page)
        def calculate_total_pages(self):
                self.total_records = len(self.model_base.loading())
                return math.ceil(self.total_records / self.list_on_page)

        def update_page_label(self):
                self.page_label.config(text=f"Page {self.page_number}/{self.total_pages}")
                self.rec_label.config(text=f"Records {self.total_records}")

        def first_page(self):
                self.page_number = 1
                self.load_page(self.list_on_page)
                self.update_page_label()

        def last_page(self):
                self.page_number = self.total_pages
                self.load_page(self.list_on_page)
                self.update_page_label()

        def load_page(self, limit):
                self._view_loading((self.page_number - 1) * limit, limit)
                self.update_page_label()

        # def load_page(self, limit):
        #         self._view_loading((self.page_number - 1) * limit ,limit)

        def prev_page(self):
                if self.page_number > 1:
                        self.page_number -= 1
                        self.load_page(self.list_on_page)

        def next_page(self):
                self.page_number += 1
                self.load_page(self.list_on_page)

        def _view_loading(self, offset=0, limit=0):
                for item in self.table.get_children():
                        self.table.delete(item)
                for i in self.model_base.loading(offset, limit):
                        self.table.insert("", tk.END, values=i)

          
        def _gui_new_entries(self):
                if isinstance(self.prize_money.get(), int): 
                        new_entry_data = (self.tournament_name.get(), self.date.get(), self.sport_name.get(), self.winners_name.get(), int(self.prize_money.get()))
                        self.model_base.new_entry(new_entry_data)
                        first_record_index = (self.page_number - 1) * self.list_on_page 
                        if first_record_index <= len(self.model_base.loading()) - 1 < first_record_index + self.list_on_page:
                                self._view_loading(first_record_index, self.list_on_page)
                        self.total_pages = self.calculate_total_pages()
                        self.update_page_label()
                else:
                        msg="prize money must be int() type"
                        mb.showerror("type error", msg) 


        def open_search_gui(self):
                self.search_window = SearchGUI(self.model_base)
               
        def open_delete_gui(self):
                self.delete_window = DeleteGUI(self.model_base, self)
                # self.total_pages = self.calculate_total_pages()
                # self.update_page_label() 
