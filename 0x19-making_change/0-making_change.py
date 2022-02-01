#!/usr/bin/python3
""" How much change needed ?"""


def makeChange(coins, total):
    """coins: list of coins we have
        total: the total we want to get"""
    x = 0
    y = 0
    if total <= 0:
        return 0
    if not coins or coins is None:
        return -1
    coins.sort(reverse=True)
    i = 0
    while i <= len(coins) - 1:
        if (x + coins[i] <= total):
            x += coins[i]
            y += 1
        else:
            i += 1
    if x == total:
        return(y)
    if x == 0:
        return(-1)
    if x != total:
        return(-1)
    return(-1)
