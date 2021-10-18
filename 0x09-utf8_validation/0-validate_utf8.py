#!/usr/bin/python3
"""Creating a UTF-8 Validator ?"""


def validUTF8(data):
    """ the function"""
    n = 0
    for i in data:
        c = format(i, '#010b')[-8:]
        if n ==0:
            for b in c:
                if b == '0':
                    break
                n += 1
            if n == 0:
                continue
            if n == 1 or n > 4:
                return False
        else:
            if (c[0] != '1' or c[1] != '0'):
                return False
        n = n - 1
    if n == 0:
        return True
    return False
