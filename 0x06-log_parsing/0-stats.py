#!/usr/bin/python3
"""Compute metrics"""
import sys


i = 0
size = 0
status = []
_sorted = {}

try:
    for line in sys.stdin:
        split = line.split(" ")
        f_size = split[-1]

        size += int(f_size)

        status_code = split[-2]
        status.append(int(status_code))
        status.sort
        dictionary = dict((i, status.count(i))
                            for i in status)
        dictionary_it = dictionary.items()
        _sorted = sorted(dictionary_it)

        i = i + 1
        if (i == 10):
            print("File size: {:d}".format(size))
            for k, v in sorted:
                print("{:d}: {:d}".format(k, v))
            i = 0
except Exception:
    pass

finally:
    print("File size: {:d}".format(size))
    for k, v in sorted:
        print("{:d}: {:d}".format(k, v))
