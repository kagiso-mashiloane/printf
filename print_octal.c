#include "main.h"
/**
 * print_octal - By Maxwell & Kagiso Print,
 *             an unsigned number in octal notation
 * @buffer: handle array of print
 * @flag: active flag
 * @list :list of arg
 * @field_width :the width of the string
 * @precision: Precision specification for the buffer
 * @size: how big it is
 * Return:return number of printed octal notation
 */
int _print_octal(va_list list, char buffer[],
	int field_width, int flag, int size, int precision)
{
	int buff = BUFF_SIZE - 2;
	unsigned long int num = va_arg(list, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(field_width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[buff--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[buff--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[buff--] = '0';
	buff++;
	return (write_unsgnd(0, buff, precision, size, buffer, flags, field_width));
}
