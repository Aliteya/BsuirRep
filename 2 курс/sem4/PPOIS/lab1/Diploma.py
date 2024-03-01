class Diploma():
    def __init__(self, title="Hello world", pages=30, count_sources=1):
        self._title = title
        self._pages = pages
        self._count_sources = count_sources
        self._checked = False

    def get_title(self)->str:
        return self._title
    
    def get_pages(self)->int:
        return self._pages
    
    def get_count_sources(self)-> int:
        return self._count_sources
    
    def get_checked(self)->bool:
        return self._checked
    
    def set_checked_true(self):
        self._checked = True

    def set_more_pages(self) -> int:
        self._pages += 45
        return self._pages
    
    def set_more_sources(self) -> int:
        self._count_sources += 5
        return self._count_sources
    
    def get_info(self):
        print(f'Title {self._title}, pages {self._pages}, sources {self._count_sources}, ckecked {self._checked}')