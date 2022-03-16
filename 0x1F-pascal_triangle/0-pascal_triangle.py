#!/usr/bin/python3
"""
Creating Pascal's triangle
"""


def pascal_triangle(n):
    """Generate pascal Triangle
        @n: Triangle Size"""
    m = []
    c = []
    for i in range(1, n + 1):
        for j in range(i):
            if (j == i - 1 or j == 0):
                c.append(1)
            else:
                c.append(m[i - 2][j - i + 1] + m[i - 2][j - i])
        m.append(c)
        c = []
    return(m)
