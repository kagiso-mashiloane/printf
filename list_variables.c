#include "main.h"

/*list variables char*/
/**
 * list_variables_char - By Maxwell & Kagiso printing string
 * @buffer: handle array of print
 * @flag: active flag
 * @c: variable char
 * @field_width :the width of the string
 * @precision: Precision specification for the buffer
 * @size: how big it is
 * Return: return char to be printed.
 */
int list_variables_char(char c, char buffer[],
	int field_width, int flag, int size, int precision)
{
	int k = 0;
	char space = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flag & F_ZERO)
		space = '0';
	buffer[k++] = c;
	buffer[k] = '\0';

	if (field_width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		k = 0;
		while (k < field_width - 1)
			buffer[BUFF_SIZE - k - 2] = space;
		k++;
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - k - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - k - 1], field_width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/*variable number*/
/**
 * variable_number - By Maxwell & Kagiso printing string
 * @is_negative: is it?
 * @ind: variable char type.
 * @buffer: handle array of print
 * @flag: active flag
 * @field_width :the width of the string
 * @precision: Precision specification for the buffer
 * @size: how big it is
 * Return:return number of printed char
 */
int variable_number(int is_negative, int ind, char buffer[],
	int field_width, int flag, int size, int precision)
{
	int len = BUFF_SIZE - ind - 1;
	char buff = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		buff = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';
	return (write_num(len, buff, ind, precision, buffer,
		flag, field_width, extra_ch));
}
/**
 * variable_num - By Maxwell & Kagiso write a buffer using a number.
 * @ind: variable char type.
 * @buffer: handle array of print
 * @flag: active flag
 * @len: how long it is
 * @buff: buff char
 * @extra_c: Extra char
 * @field_width :the width of the string
 * @prec: Precision specification for the buffer
 * Return: return number of printed chars.
 */
int variable_num(int ind, char buffer[], int field_width,
	int flag, int prec, int len, char buff, char extra_c)
{
	int k, buff_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 &&
		buffer[ind] == '0' && field_width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = buff = ' ';
	if (prec > 0 && precision < len)
		buff = ' ';
	while (prec > len)
		buffer[--ind] = '0', len++;
	if (extra_c != 0)
		len++;
	if (field_width > len)
	{
		for (k = 1; k < field_width - len + 1; k++)
			buffer[i] = buff;
		if (flag & F_MINUS && buff == ' ')
		{
			if (extra_c)
				buffer[--ind] = extrC;
			return (write(1, &buffer[ind], len) + write(1, &buffer[1], k - 1));
		}
		else if (!(flag & F_MINUS) && buff == ' ')
		{
			if (extra_c)
				buffer[--ind] = extraC;
			return (write(1, &buffer[1], k - 1) + write(1, &buffer[ind], len));
		}
		else if (!(flag & F_MINUS) && buff == '0')
		{
			if (extra_c)
				buffer[--buff_start] = extra_c;
			return (write(1, &buffer[buff_start], k - buff_start) +
			write(1, &buffer[ind], len - (1 - buff_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], len));
}
/*variable unsigned*/
/**
 * variable_unsigned - Writes an unsigned number
 * @ind:  variable char type.
 * @buffer: handle array of print
 * @flag: active flag
 * @is_negative: sum of negative.
 * @field_width :the width of the string
 * @precision: Precision specification for the buffer
 * @size: how big it is
 * Return: Number of written chars.
 */
int variable_unsigned(int is_negative, int ind, char buffer[],
	int field_width, int flag, int size, int precision)
{
	int k = 0;
	int len = BUFF_SIZE - ind - 1;
	char buff = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < len)
		buff = ' ';
	while (precision > len)
	{
		buffer[--ind] = '0';
		len++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		buff = '0';
	if (field_width > len)
	{
		for (k = 0; k < field_width - len; k++)
			buffer[i] = buff;
		buffer[k] = '\0';
		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], len) + write(1, &buffer[0], k));
		}
		else
		{
			return (write(1, &buffer[0], k) + write(1, &buffer[ind], length));
		}
	}
	return (write(1, &buffer[ind], len));
}
/*variable pointer*/
/**
 * variable_pointer -  By Maxwell & Kagiso write a memory address
 * @buffer: handle array of print
 * @ind: variable char type.
 * @len: Length of number
 * @flag: active flag
 * @field_width :the width of the string
 * @buff: Char representing the buffer
 * @extraC: representing extra char
 * @buff_start: index at which padding should start
 * Return:return number of written chars.
 */
int write_pointer(char buffer[], int ind, int len,
	char buff, char extraC, int field_width,
	int flag, int buff_start)
{
	int k;

	if (field_width > len)
	{
		for (k = 3; k < field_width - len + 3; k++)
			buffer[i] = buff;
		buffer[k] = '\0';
		if (flag & F_MINUS && buff == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extraC)
				buffer[--ind] = extraC;
			return (write(1, &buffer[ind], len) + write(1, &buffer[3], i - 3));
		}
		else if (!(flag & F_MINUS) && buff == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extraC)
				buffer[--ind] = extraC;
			return (write(1, &buffer[3], k - 3) + write(1, &buffer[ind], len));
		}
		else if (!(flag & F_MINUS) && buff == '0')
		{
			if (extraC)
				buffer[--buff_start] = extraC;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[buff_start], k - buff_start) +
				write(1, &buffer[ind], len - (1 - buff_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extraC)
		buffer[--ind] = extraC;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}


