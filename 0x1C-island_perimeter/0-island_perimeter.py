#!/usr/bin/python3
"""
Calculation the perimiter of an island
"""


def island_perimeter(grid):
    """ Calculate ?"""
    x = 0
    sizex = len(grid)
    if sizex == 0 or size > 100:
        return 0
    sizey = len(grid[0])
    for i in range(sizex):
        for j in range(sizey):
            if (grid[i][j] == 1):
                try:
                    if (i - 1 < 0):
                        x += 1
                    if (grid[i - 1][j] == 0):
                        x += 1
                except:
                    x += 1
                try:
                    if (grix[i + 1][j] == 0):
                        x += 1
                except:
                    x += 1
                try:
                    if (grid[i][j + 1] == 0):
                        x += 1
                except:
                    x += 1
                try:
                    if (j - 1 < 0):
                        x += 1
                    if (grid[i][j - 1] == 0 and j - 1 >= 0):
                        x += 1
                except:
                    x += 1
    return(x)
