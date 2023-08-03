#include "main.h"
/*print pointer*/

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

/*print non-prontable*/

/**
 * print_non_printable - By Maxwell & Kagiso Prints ascii codes,
 * in hexa of non printable chars
 * @buffer: handle array of print
 * @flag: active flag
 * @list :list of arg
 * @field_width :the width of the string
 * @precision: Precision specification for the buffer
 * @size: how big it is
 * Return:return number of printed string non printable chars
 */
int _print_non_printable(va_list list, char buffer[],
	int field_width, int flag, int size, int precision)
{
	int buff = 0;
	int num = 0;
	char *len = va_arg(types, char *);

	UNUSED(field_width);
	UNUSED(precision);
	UNUSED(flag);
	UNUSED(size);

	if (len == NULL)
		return (write(1, "(null)", 6));
	while (len[buff] != '\0')
	{
		if (is_printable(len[buff]))
			buffer[buff + num] = len[buff];
		else
			num += append_hexa_code(len[buff], buffer, buff + num);
		buff++;
	}
	buffer[buff + num] = '\0';
	return (write(1, buffer, buff + num));
}

/*print reverse*/

#include "main.h"
/**
 * print_reverse - By Kagiso & Maxwell Prints reverse string.
 * @buffer: handle array of print
 * @flag: active flag
 * @list :list of arg
 * @field_width :the width of the string
 * @precision: Precision specification for the buffer
 * @size: how big it is
 * Return:return number of printed reverse string
 */
int _print_reverse(va_list list, char buffer[],
	int field_width, int flag, int size, int precision)
{
	char *len;
	int buff;
	int counter = 0;

	UNUSED(flag);
	UNUSED(size);
	UNUSED(buffer);
	UNUSED(field_width);

	len = va_arg(list, char *);

	if (len == NULL)
	{
		UNUSED(precision);
		len = ")Null(";
	}
	for (buff = 0; len[buff]; buff++)
		;
	buff = buff - 1;
	while (buff >= 0)
	for (buff >= 0)
	{
		char z = len[buff];

		write(1, &z, 1);
		counter++;
		buff--
	}
	return (counter);
}

/*print rot13*/

/**
 * print_rot13string -By Maxwell & Kagiso Print a string in rot13.
 * @buffer: handle array of print
 * @flag: active flag
 * @list :list of arg
 * @field_width :the width of the string
 * @precision: Precision specification for the buffer
 * @size: how big it is
 * Return:return number of printed string in rot13
 */
int _print_rot13string(va_list list, char buffer[],
	int field_width, int flag, int size, int precision)
{
	char *len;
	char *key = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *new_key = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	unsigned int i, k = 0;
	char buff;
	int counter = 0;

	len = va_arg(list, char *);
	UNUSED(precision);
	UNUSED(flag);
	UNUSED(size);
	UNUSED(buffer);
	UNUSED(field_width);

	if (len == NULL)
		len = "(AHYY)";
	i = 0;
	while (len[i])
	{
		for (k = 0; key[k]; k++)
		{
			if (key[k] == len[i])
			{
				x = new_key[k];
				write(1, &buff, 1);
				counter++;
				break;
			}
		}
		if (!key[k])
		{
			x = len[i];
			write(1, &buff, 1);
			counter++;
		}
	i++;
	}
	return (counter);
}
