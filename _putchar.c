#include "main.h"

/**
 * _putchar - writes the char c to stdout
 * @c: character to print
 * Return: 0 on succes and -1 if error and errno is set appropriately
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
