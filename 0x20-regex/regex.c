#include "regex.h"

/**
 * regex_match - matching a string and a pattern
 * @str: the string to check
 * @pattern: the pattern to search
 * Return: tru or false
 */
int regex_match(char const *str, char const *pattern)
{
	if (*pattern == '\0' && *str == '\0')
		return (1);
	if (*pattern == '\0' || *str == '\0')
		return (0);
	if (*pattern == '.' && *(pattern + 1) == '*' && *(pattern + 2) == '\0')
		return (1);
	if (*(pattern + 1) == '*')
	{
		if (*(pattern) == '.')
		{
			return (regex_match(str, pattern + 2) || regex_match(str + 1, pattern));
		}
		if (*(pattern) != *str)
		{
			return (regex_match(str, pattern + 2));
		}
		if (*(pattern) == *str && *(str + 1) == *str)
		{
			return (regex_match(str + 1, pattern));
		}
		if (*(str + 1) != *str)
		{
			return (regex_match(str + 1, pattern + 2));
		}
	}
	if (*pattern == *str || *pattern == '.')
	{
		return (regex_match(str + 1, pattern + 1));
	}
	return (0);
}
