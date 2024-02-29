from pickle import load

def load_changes():
    with open("info.pickle", "rb") as file:
        try:
            dip1 = load(file)
            bob = load(file)
            su = load(file)
            t1 = load(file)
            t2 = load(file)
            t3 = load(file)
            c1 = load(file)
            return dip1, bob, su, t1, t2, t3, c1
        except EOFError:
            # Обработка ошибки, если файл не содержит достаточного количества данных
            print("File does not contain enough data.")
            return None, None, None, None, None, None, None