import unittest
from Human import Human
from Teacher import Teacher
from Diploma import Diploma
# from Presentation import Presentation
# from Student import Student
# from Supervisor import Supervisor
# from Comission import Comission
# from save import save_changes
# from load import load_changes

class TestHuman(unittest.TestCase):
    def setUp(self):
        self.human = Human("Alice",  30)

    def test_get_name(self):
        self.assertEqual(self.human.get_name(), "Alice")

    def test_get_age(self):
        self.assertEqual(self.human.get_age(),  30)

class TestTeacher(unittest.TestCase):
    def setUp(self):
        self.teacher = Teacher("John",  35,  10, "PhD")

    def test_get_experience(self):
        self.assertEqual(self.teacher.get_experience(),  10)

    def test_get_degree(self):
        self.assertEqual(self.teacher.get_degree(), "PhD")


class TestDiploma(unittest.TestCase):
    def setUp(self):
        self.diploma = Diploma("Master's in Science",  120,  5)

    def test_get_title(self):
        self.assertEqual(self.diploma.get_title(), "Master's in Science")

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

if __name__ == '__main__':
    unittest.main()