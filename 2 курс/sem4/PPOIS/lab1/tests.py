import unittest
from Human import Human
from Teacher import Teacher
from Diploma import Diploma
from Presentation import Presentation
from Student import Student
from Supervisor import Supervisor
from Comission import Comission
from save import save_changes
from load import load_changes

class TestHuman(unittest.TestCase):
    def setUp(self):
        self.human = Human("Alice",  30)

    def test_get_name(self):
        self.assertEqual(self.human.get_name(), "Alice")

    def test_get_age(self):
        self.assertEqual(self.human.get_age(),  30)

class TestTeacher(unittest.TestCase):
    def setUp(self):
        self.teacher = Teacher("John",  35,  10, "assistant")

    def test_get_experience(self):
        self.assertEqual(self.teacher.get_experience(),  10)

    def test_get_degree(self):
        self.assertEqual(self.teacher.get_degree(), "assistant")


class TestDiploma(unittest.TestCase):
    def setUp(self):
        self.diploma = Diploma("hello world",  120,  5)

    def test_get_title(self):
        self.assertEqual(self.diploma.get_title(), "hello world")

    def test_get_pages(self):
        self.assertEqual(self.diploma.get_pages(),  120)

    def test_get_count_sources(self):
        self.assertEqual(self.diploma.get_count_sources(),  5)

    def test_set_checked_true(self):
        self.diploma.set_checked_true()
        self.assertTrue(self.diploma.get_checked())

    def test_set_more_pages(self):
        pages_before = self.diploma.get_pages()
        self.diploma.set_more_pages()
        self.assertEqual(self.diploma.get_pages(), pages_before +  45)

    def test_set_more_sources(self):
        sources_before = self.diploma.get_count_sources()
        self.diploma.set_more_sources()
        self.assertEqual(self.diploma.get_count_sources(), sources_before +  5)

class TestComission(unittest.TestCase):
    def setUp(self):
        self.teacher1 = Teacher()
        self.teacher2 = Teacher()
        self.teacher3 = Teacher()
        self.comission = Comission(self.teacher1, self.teacher2, self.teacher3)

    def test_commission_asking(self):
        questions = self.comission.commission_asking()
        self.assertEqual(len(questions),  3)
        self.assertIsInstance(questions[0], str)
        self.assertIsInstance(questions[1], str)
        self.assertIsInstance(questions[2], str)

class TestSupervisor(unittest.TestCase):
    def test_checking(self):
        diploma1 = Diploma("hi", 60,  10)
        student1 = Student("Aliteya", 19, diploma1)

        supervisor = Supervisor("Ceresa",  30,  5, "assistant", [student1])
        supervisor.checking()

        self.assertTrue(student1.diploma.get_checked())

class TestStudent(unittest.TestCase):
    def setUp(self): 
        self.human = Human("Aliteya",  20)
        self.presentation = Presentation("Presentation Title", "Aliteya", "Content")
        self.diploma = Diploma(60,  10)
        self.student = Student("Aliteya",  20, self.diploma)

    def test_preparing_presentation_report(self):
        pres = self.student.preparing_presentation_report()
        self.assertIsInstance(pres, Presentation)
        self.assertEqual(pres.get_pres_title(), "genuis title for presentation Aliteya's ")

    def test_reviewing_correcting_report(self):
        result = self.student.reviewing_correcting_report()
        self.assertEqual(result, "Yes, I try to correct")

    def test_conducting_defense_rehearsals(self):
        result = self.student.conducting_defense_rehearsals(self.presentation)
        self.assertEqual(result, "That's all")

    def test_answering(self):
        result = self.student.answering("Question  1", "Question  2", "Question  3")
        self.assertIsInstance(result, int)
        self.assertTrue(0 <= result <=  3)

class TestPresentation(unittest.TestCase):
    def setUp(self):
        self.pres = Presentation("Presentation Title", "Aliteya", "Content")

    def test_get_pres_title(self):
        self.assertEqual(self.pres.get_pres_title(), "Presentation Title")

    def test_get_author(self):
        self.assertEqual(self.pres.get_author(), "Aliteya")

    def test_get_content(self):
        self.assertEqual(self.pres.get_content(), "Content")

if __name__ == '__main__':
    unittest.main()