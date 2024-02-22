from random import choice

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