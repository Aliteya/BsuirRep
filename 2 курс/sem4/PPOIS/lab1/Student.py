from Human import Human
from Presentation import Presentation
from random import choice

class Student(Human):
    def __init__(self, name, age, diploma=None):
        super().__init__(name, age)
        self.diploma = diploma
    


    def student_info(self)->str:
        print(f"Hello my name {self.get_name()}, my diplom named {self.diploma.get_title()}")

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
            ans: bool = choice([True, True, False])
            print(ans)
            if ans == True:
                right_count += 1
        return right_count