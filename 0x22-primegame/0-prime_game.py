#!/usr/bin/python3
"""Creating prime game"""


def checkprime(x):
	"""checking if prime number"""
	for i in range(2, x):
		if x % i == 0:
			return False
	return True


def rm(n, m):
	"""Remove ?"""
	for i in range(len(m)):
		if m[i] % n == 0:
			m[i] = 0


def isWinner(x, nums):
	"""Prime game"""
	if not nums or x < 1:
		return None
	m = 0
	b = 0
	for i in range(x):
		t = 0
		nmb = list(range(1, nums[i] + 1))
		while True:
			c = False
			for k, n in enumerate(nmb):
				if n > 1 and checkprime(n):
					rm(n, nmb)
					c = True
					t += 1
					break
			if c is False:
				break
		if t % 2 != 0:
			m += 1
		else:
			b += 1
	if m < b:
		return "Ben"
	if m > b:
		return "Maria"
	return None
