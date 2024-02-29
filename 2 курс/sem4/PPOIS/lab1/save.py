from pickle import dump

def save_changes(dipl, stud, supervis, t1, t2, t3, comis):
    args = [dipl, stud, supervis, t1, t2, t3, comis]
    with open("info.pickle", "wb") as file:
        for i in args:
            dump(i, file)