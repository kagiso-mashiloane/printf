#include "main.h"
/**
 * print_char - by Maxwell & Kagiso print a char
 * @buffer: handle array of print
 * @flag: active flag
 * @list :list of arg
 * @field_width :the width of the char
 * @precision: Precision specification for the buffer
 * @size: how big it is
 * Return: return number of printed char.
 */
int _print_char(va_list list, char buffer[],
	int field_width, int flag, int precision, int size)
{
	char c = va_arg(list, int);

	return (handle_write_char(c, precision, size, buffer, flag, field_width));
}

