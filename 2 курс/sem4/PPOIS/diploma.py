class Human:
    def __init__(self, name="Aliteya", age=21):
        self.name = name
        self.age = age

from random import choice 

class Teacher(Human):
    def __init__(self, name, age, experience=5, degree="assistant"): 
        super().__init__(name, age)
        self.experience = experience
        self.degree = degree

    def asking() -> str:
        vocab: list = [ "what is my name?", "what do you know about temporal relations?",
                        "why aren't you a fan yet?", "The universe is infinite?",
                        "when will I become happy?", "Are my eyes glued to you again?",
                        "My Love Mine All Mine?", "where is my mind?", "and listened to the Pacific Ocean and saw cities?"]
        return choice(vocab)

class Diploma():
    def __init__(self, title="Hello world", pages=30, count_sources=1):
        self.title = title
        self.pages = pages
        self.count_sources = count_sources
        self.checked = False

class Presentation():
    def __init__(self, pres_title="ostis ecosystem", author="Aliteya", content="many slides about the ecosystem"):
        self.pres_title = pres_title
        self.author = author
        self.content = content

class Student(Human):
    
    def __init__(self, name, age, diploma=None):
        super().__init__(name, age)
        self.diploma = diploma
    
    def preparing_presentation_report(self) -> Presentation:
        pres_title: str = f"genuis title for presentation {self.name}'s "
        author: str = self.name
        content: str = f"some slides about {self.diploma.title}... Diploma is {self.diploma.pages} pages long and has {self.diploma.count_sources} sources"
        return Presentation(pres_title, author, content)

    def reviewing_correcting_report(self) -> str:
        if self.diploma.checked == True:
            return "Okey, my diploma is checked"
        else:
            self.diploma.pages += 45
            self.count_sources += 3
            return "Yes, I try to correct"
           
    def conducting_defense_rehearsals():
        pass
    
    def answering(que1: str, que2: str, que3: str):

        pass
    
class Supervisor(Teacher):  
    def __init__(self, name, age, experience, degree, students=None):
        super().__init__(name, age, experience, degree)
        self.students = students if students is not None else []

    def checking(self):
        for student in self.students:
            if student.diploma.checked != True and student.diploma.pages > 50 and student.diploma.count_sources > 5:
                student.diploma.checked = True

class Comission():
    def __init__(self, teacher1=None, teacher2=None, teacher3=None):
        self.teacher1 = teacher1
        self.teacher2 = teacher2
        self.teacher3 = teacher3

    def commission_asking(self) -> tuple:
        que1: str = self.teacher1.asking()
        que2: str = self.teacher2.asking()
        que3: str = self.teacher3.asking()
        return que1, que2, que3

    def certification_grade():
        pass
    pass



def main():
    dip1 = Diploma()
    bob = Student("bob", 24, dip1) 
    print(bob.preparing_presentation_report())
main()
