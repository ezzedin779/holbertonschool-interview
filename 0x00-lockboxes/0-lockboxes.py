#!/usr/bin/python3
""" Creating a way to open the lockboxes ?"""


def canUnlockAll(boxes):
    """ function to unlock the boxes ?"""
    length = len(boxes)
    way = []
    no = []
    new = [0]
    for i in range(length):
        way.append(i)
    try:
        for i in range(length -1):
            for j in range(len(boxes[new[i]])):
                new.append(boxes[new[i][j]])
    except:
        return(False)
    for i in new:
        if i not in no:
            no.append(i)
    if (no == way):
        return(True)
    else:
        return(False)
