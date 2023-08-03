#include "main.h"
/*print unsigned*/

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
	unsigned long int num = va_arg(list, unsigned long int);
	int buff = BUFF_SIZE - 2;

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

/*print octal*/

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
	unsigned long int len = num;

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

	if (flags & F_HASH && len != 0)
		buffer[buff--] = '0';
	buff++;
	return (write_unsgnd(0, buff, precision, size, buffer, flags, field_width));
}

/*print hexadecimal lower*/

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
	return (print_hexa(list, buffer, 'x',
		precision, size, flag, "0123456789abcdef", field_width));
}

/*print hexadecimal upper*/

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
	return (print_hexa(list, buffer, 'X',
		precision, size, flag, "0123456789abcdef", field_width));
}

/*print hexa*/

/**
 * print_hexa - By Kagiso & Maxwell Prints a hexadecimal number,
 * in lower or upper
 * @buffer: handle array of print
 * @flag: active flag
 * @flag_ch:active flag
 * @list :list of arg
 * @map_to: the array number of values of map
 * @field_width :the width of the string
 * @precision: Precision specification for the buffer
 * @size: how big it is
 * Return:return number of printed string hexadecimal number
 */
int _print_hexa(va_list list, char buffer[], char map_to[],
	int field_width, char flag_ch, int flag, int size, int precision)
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
		buffer[buff--] = map_to[num % 16];
		num /= 16;
	}
	if (flag & F_HASH && init_num != 0)
	{
		buffer[buff--] = flag_ch;
		buffer[buff--] = '0';
	}
	buff++;
	return (write_unsgnd(0, buff, precision, size, buffer, flags, field_width));
}
