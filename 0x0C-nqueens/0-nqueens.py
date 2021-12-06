#!/usr/bin/python3
import sys
"""algorithm for nqueens"""


def insert(n):
    board = []
    for i in range(n):
        r = []
        for j in range(n):
            r.append(0)
        board.append(r)
    return(board)


def displayboard(board, n):
    x = []
    for i in range(n):
        y = []
        for j in range(n):
            if board[i][j] == 1:
                y.append(i)
                y.append(j)
                x.append(y)
    print(x)


def sf(board, r, c, n):
    for i in range(c):
        if board[r][i] == 1:
            return False

    i = r
    j = c
    while j >= 0 and i < n:
        if (board[i][j]):
            return False
        i += 1
        j -= 1
    return True


def nqb(board, c, n):
    if (c == n):
        displayboard(board, n)
        return True


    res = False
    for i in range (n):
        if (sf(board, i, c, n)):
            board[i][c] = 1

            res = nqb(board, c + 1, n) or res

            board[i][c] = 0

    return res


def nq(board, n):
    if (nqb(board, 0, n) is False):
        print("Solution does not exist")
        exit (1)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    try:
        if not type(int(sys.argv[1])) is int:
            print("N must be a number")
            exit(1)
    except:
        print("N must be a number")
        exit(1)

    n = int(sys.argv[1])

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = insert(n)

    nq(board, n)
