#include "palindrome.h"
/**
 * is_palindrome - Check if this int is palindrome
 * @n: the int to check
 * Return - 0 or 1
 */

int is_palindrome(unsigned long n)
{
	unsigned long r = n, x;

	while (r != 0)
	{
		x = r % 10 + x * 10;
		r = r / 10;
	}
	if (x == n)
		return (1);
	return (0);
}
