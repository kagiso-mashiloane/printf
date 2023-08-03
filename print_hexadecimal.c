#include "main.h"
/**
 * print_hexadecimal -By Maxwell & Kagiso Prints,
 *                 an unsigned number in hexadecimal notation
 * @buffer: handle array of print
 * @flag: active flag
 * @list :list of arg
 * @field_width :the width of the string
 * @precision: Precision specification for the buffer
 * @size: how big it is
 * Return:return number of printed hexadecimal notation
 */
int _print_hexadecimal(va_list list, char buffer[],
	int field_width, int flag, int size, int precision)
{
	return (print_hexa(list, "0123456789abcdef", buffer,
		precision, size, flag, 'x', field_width));
}
