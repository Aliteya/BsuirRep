from pickle import load

def load_changes():
    with open("info.pickle", "rb") as file:
        l = []
        while True:
            try:
                l.append(load(file))
            except EOFError:
                break
    return l