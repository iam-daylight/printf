#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - function for printf
 * @format: format
 * Return: characters
 */
int _printf(const char *format, ...)
{
	int a, printed = 0, printed_chars = 0;
	int flag, width, precision, space, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[buff_ind++] = format[a];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flag = get_flag(format, &a);
			width = get_width(format, &a, list);
			precision = get_precision(format, &a, list);
			space = get_space(format, &a);
			++a;
			printed = handle_print(format, &a, list, buffer,
				flag, width, precision, space);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
