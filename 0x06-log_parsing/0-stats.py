#!/usr/bin/python3
"""Doing some manipulation for the input"""


import sys
i = 0
stc = ['200', '301', '400', '401', '403', '404', '405', '500']
l = 0
n = [0, 0, 0, 0, 0, 0, 0, 0]

try:
    for line in sys.stdin:
        piece = line.split()
        if len(piece) > 2:
            if piece[-2] in stc:
                j = stc.index(piece[-2])
                n[j] = n[j] + 1
            i += 1
            l = l + int(piece[-1])
        if i == 10:
            i = 0
            print("File size: {}".format(l))
            for j in range(8):
                if n[j] != 0:
                    print("{}: {}".format(stc[j], n[j]))
except Exception:
    pass
finally:
    print("File size: {}".format(l))
    for j in range(8):
        if n[j] != 0:
            print("{}: {}".format(stc[j], n[j]))
