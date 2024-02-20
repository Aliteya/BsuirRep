from random import choice 

class Human:
    def __init__(self, name="Aliteya", age=21):
        self.name = name
        self.age = age

class Teacher(Human):  
    def __init__(self, name="Onizuka", age=27, experience=5, degree="assistant"): 
        super().__init__(name, age)
        self.experience = experience
        self.degree = degree

    def choose_question(self) -> str:
        vocab: list = [ "say my name", "what do you know about temporal relations?",
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

    def set_more_pages(self) -> int:
        self.pages += 45
        return self.pages
    
    def set_more_sources(self) -> int:
        self.count_sources += 5
        return self.count_sources
    
    def get_info(self):
        print(self.title, self.pages, self.count_sources, self.checked)

class Presentation():
    def __init__(self, pres_title="ostis ecosystem", author="Aliteya", content="many slides about the ecosystem"):
        self.pres_title = pres_title
        self.author = author
        self.content = content

    def list_pages(self):
        print("next page")

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
            self.diploma.set_more_pages()
            self.diploma.set_more_sources()
            return "Yes, I try to correct"
           
    def conducting_defense_rehearsals(self, pres1: Presentation)-> str:
        print(pres1.pres_title, pres1.content, sep="/n")
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
            if student.diploma.checked != True and student.diploma.pages > 50 and student.diploma.count_sources > 5:
                student.diploma.checked = True

    def print_student_info(self):
        for student in self.students:
            print(f"Student: {student.name}, Diploma Pages: {student.diploma.pages}, Diploma Sources: {student.diploma.count_sources}, Diploma Checked: {student.diploma.checked}")

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

main()