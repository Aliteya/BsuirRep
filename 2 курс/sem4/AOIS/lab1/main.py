
def direct_decimal_conv(num: int):
    l = [0 for _ in range(8)]
    if num < 0:
        l[0] = 1
        num *= -1
    i = 7
    while num > 0:
        l[i] = num % 2
        num //= 2
        i -= 1
    return l

def return_decimal_conv(num: int):
    l = direct_decimal_conv(num)
    l = [l[0]] + list(map(lambda x : 0 if x == 1 else 1, l[1:]))
    return l


def additional_decimal_conv(num: int):
    if num > 0:
        l = direct_decimal_conv(num)
    else:
        l = return_decimal_conv(num)
        return direct_plus_plus(l, [0 for _ in range(7)] + [1])

def direct_plus_plus(num1: list, num2: list):
    num = [0 for _ in range(8)]
    if num1[0] == 1:
        num[0] = 1
    else:
        num[0] = 0
    ost =  0 
    for i in range(7, 0 , -1):
        total = num1[i] + num2[i] + ost
        num[i] = total %  2
        ost = total //  2
    return num

def additional_plus_minus(num1: list, num2: list, i: int):
    num = direct_plus_plus(num1, num2)
    num = [i] + num[1:]
    return num

def plus(num1: int, num2: int):
    i, j = 0, 0
    if abs(num1) > abs(num2):
        i = 1
    else: 
        j = 1
    if num1*num2 < 0:
        if num1 < 0:
            return additional_plus_minus(additional_decimal_conv(num1), direct_decimal_conv(num2), i)
        else:
            return additional_plus_minus(direct_decimal_conv(num1), additional_decimal_conv(num2), j)
    else:
        return direct_plus_plus(direct_decimal_conv(num1), direct_decimal_conv(num2))

print(plus(5, -7))
