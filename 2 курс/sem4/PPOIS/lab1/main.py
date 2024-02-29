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
    dip1, bob, su, t1, t2, t3, c1 = load_changes()

    dip1 = dip1 or Diploma("Diploma Title", 30, 14)
    bob = bob or Student("Bob", 24, dip1)
    su = su or Supervisor("Supervisor", 35, 5, "PhD", [bob])
    t1 = t1 or Teacher("Teacher 1", 34)
    t2 = t2 or Teacher("Teacher 2", 34)
    t3 = t3 or Teacher("Teacher 3", 34)
    c1 = c1 or Comission(t1, t2, t3)

    while True:
        print("""
        Input number of operation:
        0 - Exit
        1 - Students info
        2 - Supervisor info
        3 - Supervisor's students info
        4 - Diploma info
        5 - Supervisor check diploma
        6 - Student review report
        7 - Student make presentation
        8 - Protection diploma
        9 - Save
        """)
        i = int(input("Choose operation: "))
        match i:
            case 0:
                print("Exiting...")
                break
            case 1:
                su.print_student_info()
            case 2:
                su.supervis_info()
            case 3:
                print("Supervisor's students info:")
                su.print_student_info()
            case 4:
                print("Diploma info:")
                dip1.get_info()
            case 5:
                su.checking()
            case 6:
                print("Student review report:")
                print(bob.reviewing_correcting_report())
            case 7:
                print("Student make presentation:")
                pres = bob.preparing_presentation_report()
                pres.present_info()
            case 8:
                print("Protection diploma:")
                dip1.set_checked_true()
                print("Grade ", c1.certification_grade(bob.answering(*c1.commission_asking())), sep=" ")
            case 9:
                print("Saving data...")
                save_changes(dip1, bob, su, t1, t2, t3, c1)
            case _: 
                print("Input from 0 to 9")

if __name__ == "__main__":
    main()
