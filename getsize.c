#include "main.h"

/**
 * get_size - function that Calculates the size to cast the argument
 * @format: Formatted string to print the arguments
 * @i: Arguments to be printed.
 *
 * Return: Precision.
 */

int get_size(const char *format, int *i)
{
	int ccc_i = *i + 1;
	int size = 0;

	if (format[ccc_i] == 'l')
		size = S_LONG;
	else if (format[ccc_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = ccc_i - 1;
	else
		*i = ccc_i;

	return (size);
}

