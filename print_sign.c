#include "main.h"
/**
 * print_percent - By Maxwell & Kagiso Prints a percent sign
 * @buffer: handle array of print
 * @flag: active flag
 * @list :list of arg
 * @field_width :the width of the string
 * @precision: Precision specification for the buffer
 * @size: how big it is
 * Return:return number of printed sign
 */
int _print_percent(va_list list, char buffer[],
        int field_width, int flag, int size, int precision)
{
	UNUSED(list);
	UNUSED(precision);
        UNUSED(flag);
        UNUSED(size);
        UNUSED(buffer);
        UNUSED(field_width);
	return (write(1, "%%", 1));
}
