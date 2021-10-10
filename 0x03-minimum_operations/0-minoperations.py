#!/usr/bin/python3
"""Minimum Operations"""


def minOperations(n):
	"""Calculate please ?"""
	result = 0
	he = 1
	cal = 1
	if type(n) is not int or n < 2:
		return 0
	while (he != n):
		if (n % he == 0):
			cal = he
			he = 2 * he
			result += 2
		else:
			he = he + cal
			result += 1
	return result
