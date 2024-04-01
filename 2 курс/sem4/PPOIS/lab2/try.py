# class Interface():
#     def __init__(self, model_base: ModelBase):
#         # Other initialization code
        
#         # Add page number labels
#         self.page_label = tk.Label(self.window, text="")
#         self.page_label.grid(row=3, column=3, pady=10)

#         # Add buttons for first and last page
#         first_page_button = tk.Button(self.window, text="First", command=self.first_page)
#         first_page_button.grid(row=3, column=4, pady=10)

#         last_page_button = tk.Button(self.window, text="Last", command=self.last_page)
#         last_page_button.grid(row=3, column=5, pady=10)

#         # Initialize page number
#         self.total_pages = self.calculate_total_pages()
#         self.update_page_label()

    # def calculate_total_pages(self):
    #     total_records = len(self.model_base.loading())
    #     return math.ceil(total_records / self.list_on_page)

    # def update_page_label(self):
    #     self.page_label.config(text=f"Page {self.page_number}/{self.total_pages}")

    # def first_page(self):
    #     self.page_number = 1
    #     self.load_page(self.list_on_page)
    #     self.update_page_label()

    # def last_page(self):
    #     self.page_number = self.total_pages
    #     self.load_page(self.list_on_page)
    #     self.update_page_label()

    # def load_page(self, limit):
    #     self._view_loading((self.page_number - 1) * limit, limit)
    #     self.update_page_label()
