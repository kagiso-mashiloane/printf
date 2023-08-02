#include "main.h"
/**
 * _precision - By Maxwell & Kagiso Calculates the precision for printing
 * @format: print the arguments in a formatted string
 * @i: arguments to be printed.
 * @list:List of arguments to be printed.
 * Return: return precision.
 */
int _precision(const char *format, int *i, va_list list)
{
	int precision = -1;
	int k = *i + 1;

	if (format[k] != '.')
		return (precision);
	precision = 0;
	k += 1;
	while (format[k] != '\0')
	{
		if (is_digit(format[k]))
		{
			precision *= 10;
			precision += format[k] - '0';
		}
		else if (format[k] == '*')
		{
			k++;
			precision = va_arg(int, list);
			break;
		}
		else
			break;
	k++;
	}
	*i = k - 1;
	return (precision);
}
