from random import choice 
import pickle


class Human:
    def __init__(self, name="Aliteya", age=21):
        self._name = name
        self._age = age

    def get_name(self):
        return self._name
    
    def get_age(self):
        return self._age


class Teacher(Human):  
    def __init__(self, name="Onizuka", age=27, experience=5, degree="assistant"): 
        super().__init__(name, age)
        self._experience = experience
        self._degree = degree

    def get_experience(self):
        return self._experience
    
    def get_degree(self):
        return self._degree

    def choose_question(self) -> str:
        vocab: list = [ "say my name", "what do you know about temporal relations?",
                        "why aren't you a fan yet?", "The universe is infinite?",
                        "when will I become happy?", "Are my eyes glued to you again?",
                        "My Love Mine All Mine?", "where is my mind?", "and listened to the Pacific Ocean and saw cities?"]
        return choice(vocab)

class Diploma():
    def __init__(self, title="Hello world", pages=30, count_sources=1):
        self._title = title
        self._pages = pages
        self._count_sources = count_sources
        self._checked = False

    def get_title(self):
        return self._title
    
    def get_pages(self):
        return self._pages
    
    def get_count_sources(self):
        return self._count_sources
    
    def get_checked(self):
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
        print(self._title, self._pages, self._count_sources, self._checked)

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

class Student(Human):
    def __init__(self, name, age, diploma=None):
        super().__init__(name, age)
        self.diploma = diploma
    
    def preparing_presentation_report(self) -> Presentation:
        pres_title: str = f"genuis title for presentation {self.get_name()}'s "
        author: str = self.get_name()
        content: str = f"some slides about {self.diploma.get_title()}... Diploma is {self.diploma.get_pages()} pages long and has {self.diploma.get_count_sources()} sources"
        return Presentation(pres_title, author, content)

    def reviewing_correcting_report(self) -> str:
        if self.diploma.get_checked() == True:
            return "Okey, my diploma is checked"
        else:
            self.diploma.set_more_pages()
            self.diploma.set_more_sources()
            return "Yes, I try to correct"
           
    def conducting_defense_rehearsals(self, pres1: Presentation)-> str:
        print(pres1.get_pres_title(), pres1.get_content(), sep="/n")
        pres1.list_pages()
        return "That's all"
    
    def answering(self, que1: str, que2: str, que3: str) -> int:
        right_count: int = 0
        print(que1)
        print(que2)
        print(que3)
        for _ in range(3):
            ans: bool = choice([True, False], weight=[20, 10])
            print(ans)
            if ans == True:
                right_count += 1
        return right_count
    
class Supervisor(Teacher):  
    def __init__(self, name, age, experience, degree, students=None):
        super().__init__(name, age, experience, degree)
        self.students = students if students is not None else []

    def checking(self):
        for student in self.students:
            if student.diploma.get_checked() != True and student.diploma.get_pages() > 50 and student.diploma.get_count_sources() > 5:
                student.diploma.set_checked_true()

    def print_student_info(self):
        for student in self.students:
            print(f"Student: {student.get_name()}, Diploma Pages: {student.diploma.get_pages()}, Diploma Sources: {student.diploma.get_count_sources()}, Diploma Checked: {student.diploma.get_checked()}")

class Comission():
    def __init__(self, teacher1=None, teacher2=None, teacher3=None):
        self.teacher1 = teacher1
        self.teacher2 = teacher2
        self.teacher3 = teacher3

    def commission_asking(self) -> tuple:
        que1: str = self.teacher1.choose_question()
        que2: str = self.teacher2.choose_question()
        que3: str = self.teacher3.choose_question()
        return que1, que2, que3

    def certification_grade(self, right_count: int) -> int:
        match right_count:
            case 3:
                return choice([9,10])
            case 2:
                return choice([7,8])
            case 1:
                return choice([5, 6])
            case 0:
                return 4

def main():
    dip1 = Diploma("hi", 45, 4)
    bob = Student("bob", 24, dip1) 
    su = Supervisor("super",35, 5, "docent", [bob])
    su.checking()
    su.print_student_info()
    print(bob.reviewing_correcting_report())
     
    dip1.get_info()
    su.checking()
    su.print_student_info()
    print(bob.reviewing_correcting_report())
    dip1.get_info
    su.checking()
    print(bob.reviewing_correcting_report())
    dip1.get_info()
    t1 = Teacher("t1", 34)
    t2 = Teacher("t2", 34)
    t3 = Teacher("t3", 34)
    c1 = Comission(t1,t2,t3)
    q1, q2, q3 = c1.commission_asking()

if __name__ == '__main__':
    main()