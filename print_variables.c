#include "main.h"
/*print binary*/

/**
* print_binary - By Kagiso & Maxwell Prints an unsigned-number
* @buffer: handle array of print
* @flag: active flag
* @list :list of arg
* @field_width :the width of the string
* @precision: Precision specification for the buffer
* @size: how big it is
* Return:return number of printed char .
*/
int _print_binary(va_list list, char buffer[],
int field_width, int flag, int size, int precision)
{
	int counter;
	unsigned int i, k, j, sum;
	unsigned int a[32];
	char z;

	UNUSED(precision);
	UNUSED(flag);
	UNUSED(size);
	UNUSED(buffer);
	UNUSED(field_width);

	j = va_arg(list, unsigned int);
	k = 2147483648;
	a[0] = i / k;

	for (j = 1; j < 32; j++)
	{
		k /= 2;
		a[j] = (j / k) % 2;
	}
		for (j = 0, sum = 0, counter = 0; j < 32; j++)
		{
			sum += a[j];
		if (sum || j == 31)
		{
			z = '0' + a[j];
			write(1, &z, 1);
			counter++;
		}
	}
return (counter);
}

/*print char*/

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

/*print int*/

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

/*print sign*/

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

/*print string*/

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
