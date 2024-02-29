from Teacher import Teacher

class Supervisor(Teacher):  
    def __init__(self, name, age, experience, degree, students=None):
        super().__init__(name, age, experience, degree)
        self.students = students if students is not None else []

    def supervis_info(self):
        print(f'name {self.get_name()}, age {self.get_age()}, expirience {self.get_experience()}, degree {self.get_degree()}')

    def checking(self):
        for student in self.students:
            if student.diploma != None and student.diploma.get_checked() != True and student.diploma.get_pages() > 50 and student.diploma.get_count_sources() > 5:
                student.diploma.set_checked_true()

    def print_student_info(self):
        for student in self.students:
            print(f"Student: {student.get_name()}, Diploma Pages: {student.diploma.get_pages()}, Diploma Sources: {student.diploma.get_count_sources()}, Diploma Checked: {student.diploma.get_checked()}")
