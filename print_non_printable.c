#include "main.h"
/**
 * print_non_printable - By Maxwell & Kagiso Prints ascii codes,
 * in hexa of non printable chars
 * @buffer: handle array of print
 * @flag: active flag
 * @list :list of arg
 * @field_width :the width of the string
 * @precision: Precision specification for the buffer
 * @size: how big it is
 * Return:return number of printed string non printable chars
 */
int _print_non_printable(va_list list, char buffer[],
	int field_width, int flag, int size, int precision)
{
	int buff = 0;
	int num = 0;
	char *len = va_arg(types, char *);

	UNUSED(field_width);
	UNUSED(precision);
	UNUSED(flag);
	UNUSED(size);

	if (len == NULL)
		return (write(1, "(null)", 6));
	while (len[buff] != '\0')
	{
		if (is_printable(len[buff]))
			buffer[buff + num] = len[buff];
		else
			num += append_hexa_code(len[buff], buffer, buff + num);
		buff++;
	}
	buffer[buff + num] = '\0';
	return (write(1, buffer, buff + num));
}
