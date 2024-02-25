class Human:
    def __init__(self, name="Aliteya", age=21):
        self._name = name
        self._age = age

    def get_name(self):
        return self._name
    
    def get_age(self):
        return self._age