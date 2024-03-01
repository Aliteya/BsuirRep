from Human import Human
from random import choice 

class Teacher(Human):  
    def __init__(self, name="Onizuka", age=27, experience=5, degree="assistant"): 
        super().__init__(name, age)
        self._experience = experience
        self._degree = degree

    def get_name(self):
        return super().get_name()
    
    def get_age(self):
        return super().get_age()

    def get_experience(self)->int:
        return self._experience
    
    def get_degree(self)->str:
        return self._degree

    def choose_question(self) -> str:
        vocab: list = [ "say my name", "what do you know about temporal relations?",
                        "why aren't you a fan yet?", "The universe is infinite?",
                        "when will I become happy?", "Are my eyes glued to you again?",
                        "My Love Mine All Mine?", "where is my mind?", "and listened to the Pacific Ocean and saw cities?"]
        return choice(vocab)