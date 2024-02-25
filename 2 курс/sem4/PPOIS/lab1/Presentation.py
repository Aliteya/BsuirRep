class Presentation():
    def __init__(self, pres_title="ostis ecosystem", author="Aliteya", content="many slides about the ecosystem"):
        self._pres_title = pres_title
        self._author = author
        self._content = content

    def get_pres_title(self):
        return self._pres_title
    
    def get_author(self):
        return self._author
    
    def get_content(self):
        return self._content

    def list_pages(self):
        print("next page")