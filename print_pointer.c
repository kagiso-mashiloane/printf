#include "main.h"
/**
 * print_pointer -By Maxwell & Kagiso Prints the value,
 *           of a pointer variable
 * @buffer: handle array of print
 * @flag: active flag
 * @list :list of arg
 * @field_width :the width of the string
 * @precision: Precision specification for the buffer
 * @size: how big it is
 * Return:return number of printed string pointer variable
 */
int _print_pointer(va_list list, char buffer[],
	int field_width, int flag, int size, int precision)
{
	int buff = BUFF_SIZE - 2, length = 2, padd_start = 1;
	char len_c = 0, padd = ' ';
	char map_to[] = "0123456789abcdef";
	unsigned long num_addrs;
	void *num = va_arg(list, void *);

	UNUSED(size);
	UNUSED(field_width);
	UNUSED(precision);

	if (num == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';

	num_addrs = (unsigned long)num;

	while (num_addrs > 0)
	{
		buffer[buff--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		len_c = '+', length++;
	else if (flags & F_SPACE)
		len_c = ' ', length++;
	buff++;
	return (write_pointer(buffer, buff, length,
		field_width, len_c, padd_start, flags, padd));
}

