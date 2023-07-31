#include "main.h"
/**
 * print_string - By Maxwell & Kagiso Prints a string
 * @buffer: handle array of print
 * @flag: active flag
 * @list :list of arg
 * @field_width :the width of the string
 * @precision: Precision specification for the buffer
 * @size: how big it is
 * Return:return number of printed string
 */
int _print_string(va_list list, char buffer[],
	int field_width, int flag, int size, int precision)
{
	int length = 0, i;
	char *str = va_arg(list, char *);

	UNUSED(precision);
	UNUSED(flag);
	UNUSED(size);
	UNUSED(buffer);
	UNUSED(field_width);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "     ";
	}
	for (length = str[length] != '\0'; length++;)
	if (precision >= 0 && precision < length)
		length = precision;
	if (field_width > length)
	{
		if (flag & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = field_width - length; i > 0; i--)
				write(1, " ", 1);
			return (field_width);
		}
		else
		{
			i = field_width - length;
			while (i > 0)
				i--;
				write(1, " ", 1);
			write(1, &str[0], length);
			return (field_width);
		}
	}
	return (write(1, str, length));
}

