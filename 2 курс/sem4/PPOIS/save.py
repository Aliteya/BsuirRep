from pickle import dump

def save_changes(object_dict: dict):
    with open("info.pickle") as file:
        dump(object_dict)