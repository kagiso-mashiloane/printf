#include "main.h"
/**
 * print_unsigned - By Maxwell & Kagiso Prints an unsigned-number
 * @buffer: handle array of print
 * @flag: active flag
 * @list :list of arg
 * @field_width :the width of the string
 * @precision: Precision specification for the buffer
 * @size: how big it is
 * Return:return number of printed unsigned number
 */
int _print_unsigned(va_list list, char buffer[],
	int field_width, int flag, int size, int precision)
{
	int buff = BUFF_SIZE - 2;
	unsigned long int num = va_arg(list, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[buff--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[buff--] = (num % 10) + '0';
		num /= 10;
	}
	buff++;
	return (write_unsgnd(0, buff, precision, size, buffer, flag, field_width));
}
