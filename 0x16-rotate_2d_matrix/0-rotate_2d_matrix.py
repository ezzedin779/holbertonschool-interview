#!/usr/bin/python3
"""Rotate the 2d 90 degrees matrix"""


def rotate_2d_matrix(matrix):
    """rotate the matrix"""
    length = len(matrix)
    for i in range (length // 2):
        for j in range(i, length - 1):
            tmp = matrix[i][j]
            matrix[i][j] = matrix[length - 1 - j][i]
            matrix[length - 1 - j][i] = matrix[length - 1 - i][length - 1 - j]
            matrix[length - 1 -i][length - 1 - j] = matrix[j][length - 1 - i]
            matrix[j][length - 1 - i] = tmp
