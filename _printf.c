#include "main.h"
void print_buff(char buffer[], int *buff_ind);
/**
 * _printf - Printf by Maxwell & Kagiso
 * @format: string is composed of zero or more directives.
 * Return: number of chars.
 */
int _printf(const char *format, ...)
{
	int i, size, precision, field_width, flag;
	int  printed_chars = 0,  print = 0, buff_ind = 0;
	char buffer[BUFF_SIZE];
	va_list list;

	if (!format)
		return (-1);
	va_start(list, format);
	i = print;
	while (format && format[i] != '\0')
	{
	if (format[i] == '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buff(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			size = get_size(format, &i);
			precision = get_precision(format, &i, list);
			field_width = get_width(format, &i, list);
			flag = get_flags(format, &i);
			print_buff(buffer, &buff_ind);
			++i;
			printf = handle_print(format, &i, list, buffer,
				size, precision, field_width, flag);
			if (print == -1)
				return (-1);
			printed_chars += printf;
		}
		i++;
	}
	va_end(list);
	print_buff(buffer, &buff_ind);
	return (printed_chars);
}
