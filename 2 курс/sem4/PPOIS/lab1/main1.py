from Human import Human
from Teacher import Teacher
from Diploma import Diploma
from Presentation import Presentation
from Student import Student
from Supervisor import Supervisor
from Comission import Comission
from save import save_changes
from load import load_changes


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
    num = bob.answering(q1, q2, q3)
    print(c1.certification_grade(num))
    save_changes(c1, t1, su, dip1)
    print(load_changes())

    
if __name__ == '__main__':
    main()