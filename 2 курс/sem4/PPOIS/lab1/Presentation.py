class Presentation():
    def __init__(self, pres_title="ecosystem", author="Aliteya", content="many slides about the ecosystem"):
        self._pres_title = pres_title
        self._author = author
        self._content = content

    def get_pres_title(self)->str:
        return self._pres_title
    
    def get_author(self)->str:
        return self._author
    
    def get_content(self)->str:
        return self._content
    
    def present_info(self):
        print(f'name {self.get_pres_title()}, author {self.get_author()}, content {self.get_content()}')

    def list_pages(self):
        print("next page")