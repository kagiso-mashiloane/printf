#include "main.h"
/**
 * print_types - by Maxwell and Kagiso Prints an argument based on its type.
 * @buffer: handle array of print
 * @flag: active flag
 * @list :list of arg
 * @fmt: Formatted string in which to print the arguments.
 * @ind: ind.
 * @field_width :the width of the string
 * @precision: Precision specification for the buffer
 * @size: how big it is
 * Return: return 1 or 2;
 */
int print_types(const char *fmt, int *ind, va_list list, char buffer[],
	int field_width, int flag, int size, int precision)
{
	int buff_char = -1;
	int len = 0;
	int k,
	fmt_t _fmt[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (k = 0; _fmt[k].fmt != '\0'; k++)
		if (fmt[*ind] == f_fmt[k].fmt)
			return (_fmt[k].fn(size, field_width, precision, buffer, flags, list));
	if (_fmt[k].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			len += write(1, " ", 1);
		else if (field_width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		len += write(1, &fmt[*ind], 1);
		return (len);
	}
	return (buff_char);
}
