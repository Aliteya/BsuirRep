from pickle import dump

def save_changes(*args):
    with open("info.pickle", "wb") as file:
        for i in args:
            dump(i, file)