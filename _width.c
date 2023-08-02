#include "main.h"
/**
 * _width - Kagiso and Maxwell Calculates the width for printing
 * @format: print the arguments in the formatted field width.
 * @i: variable int.
 * @list: list of arg.
 * Return: return field_width.
 */
int _width(const char *format, int *i, va_list list)
{
	int field_width = 0;
	int k;

	k = *i + 1;
	while (format[k] != '\0')
	{
		if (is_digit(format[k]))
		{
			field_width *= 10;
			field_width += format[k] - '0';
		}
		else if (format[k] == '*')
		{
			k++;
			field_width = va_arg(int, list);
			break;
		}
		else
			break;
	k++;
	}
	*i = k - 1;
	return (field_width);
}
