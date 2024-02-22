from pickle import load

def load_changes():
    with open("info.pickle", "rb") as file:
        objects_dict = load(file)
    return objects_dict