#!/usr/bin/python3
"""Doing some manipulation for the input"""

if __name__ == '__main__':
    import sys

    def _print(stc, fs):
        """printing the needed information"""
        print("File size: {}".format(fs))
        for st, t in sorted(stc.items()):
            if t:
                print("{}: {}".format(st, t))

    stc = {"200": 0,
           "301": 0,
           "400": 0,
           "401": 0,
           "403": 0,
           "404": 0,
           "405": 0,
           "500": 0,
           }
    fs = 0
    li = 0

    try:
        for line in sys.stdin:
            if li != 0 and li % 10 == 0:
                _print(stc, fs)
            li += 1
            info = line.split()
            try:
                st = info[-2]
                if st in stc:
                    stc[st] += 1
                fs += int(info[-1])
            except Exception:
                pass
        _print(stc, fs)
    except KeyboardInterrupt:
        _print(stc, fs)
        raise
