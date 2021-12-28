#include "holberton.h"

/**
 * length - length of a string
 * @str: the string to get the length
 * Return: LENGTH
 */
int length(char *str)
{
	int res = 0;

	for (; str[res] != '\0'; res++)
	;

	return (res);
}

/**
 * err - basic error to exist with 98
 */
void err(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * converter - string to integer
 * @str: the string to convert
 * Return: array of the string
 */
int *converter(char *str)
{
	int i;
	int y;
	int *num = NULL;
	(void) y;

	if (str[0] == '0')
	{
		_putchar('0');
		_putchar('\n');
		exit(0);
	}
	num = malloc(sizeof(int) * length(str));
	if (num == NULL)
		err();
	for (i = 0; str[i] != '\0'; i++)
	{
		if ((int)str[i] > 58 || (int)str[i] < 48)
			err();
		num[i] = str[i] - '0';
	}
	return (num);
}

/**
 * main - the main prog
 * @argv: the arguments
 * @argc: number of arguments
 * Return: 0 or 98
 */
int main(int argc, char **argv)
{
	int *x = NULL, *y = NULL, *prod = NULL, len_1, len_2;
	int new, carr;
	int i, j, k;
	int b_i = 0, b_j;

	if (argc != 3)
		err();
	x = converter(argv[1]);
	y = converter(argv[2]);
	len_1 = length(argv[1]);
	len_2 = length(argv[2]);
	prod = malloc(sizeof(int) * (len_2 + len_1));
	if (prod == NULL)
		err();
	for (i = len_1 - 1; i >= 0; i--)
	{
		carr = 0;
		b_j = 0;
		for (j = len_2 - 1; j >= 0; j--)
		{
			new = x[i] * y[j] + prod[b_i + b_j] + carr;
			carr = new / 10;
			prod[b_j + b_j] = new % 10;
			b_j++;
		}
		if (carr > 0)
			prod[b_i + b_j] += carr;
		b_i++;
	}
	for (k = len_1 + len_2 - 1; k >= 0; i--)
	{
		if (k == len_1 + len_2 - 1 && prod[k] == 0)
			continue;
		_putchar(prod[k] + '0');
	}
	_putchar('\n');
	free(x);
	free(y);
	free(prod);
	return (0);
}
