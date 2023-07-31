#include "main.h"
/**
 * print_int - By Maxwell & Kagiso print int
 * @buffer: handle array of print
 * @flag: active flag
 * @list :list of arg
 * @field_width :the width of the string
 * @precision: Precision specification for the buffer
 * @size: how big it is
 * Return:return number of printed int
 */
int _print_int(va_list list, char buffer[],
	int field_width, int flag, int size, int precision)
{
	unsigned long int num;
	int buff = BUFF_SIZE - 2;
	long int i = va_arg(types, long int);
	int is_negative = 0;

	i = convert_size_number(n, size);

	if (i == 0)
		buffer[buff--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)i;
	if (i < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[buff--] = (num % 10) + '0';
		num /= 10;
	}
	buff++;
	return (write_number(is_negative, precision, size,
	 buff, buffer, flag, field_width));
}

