#include "main.h"
/**
 * print_reverse - By Kagiso & Maxwell Prints reverse string.
 * @buffer: handle array of print
 * @flag: active flag
 * @list :list of arg
 * @field_width :the width of the string
 * @precision: Precision specification for the buffer
 * @size: how big it is
 * Return:return number of printed reverse string
 */
int _print_reverse(va_list list, char buffer[],
	int field_width, int flag, int size, int precision)
{
	char *len;
	int buff;
	int counter = 0;

	UNUSED(flag);
	UNUSED(size);
	UNUSED(buffer);
	UNUSED(field_width);

	len = va_arg(list, char *);

	if (len == NULL)
	{
		UNUSED(precision);
		len = ")Null(";
	}
	for (buff = 0; len[buff]; buff++)
		;
	buff = buff - 1;
	while (buff >= 0)
	for (buff >= 0)
	{
		char z = len[buff];

		write(1, &z, 1);
		counter++;
		buff--
	}
	return (counter);
}
