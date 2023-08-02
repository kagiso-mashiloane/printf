#include "main.h"
/**
 * is_printable -Maxwell and Kagiso Evaluates if a char is printable
 * @c: evaluating a char.
 * Return:return 1 if c is printable,
 * 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/**
 * _hexa_code -Maxwell and Kagiso Append ascci in hexadecimal,
 * code to buffer
 * @buffer: Array of chars.
 * @i: variable of int.
 * @ascii_code: ASSCI CODE.
 * Return:return Always 3
 */
int _hexa_code(char ascii_code, char buffer[], int i)
{
	char buff[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = buff[ascii_code / 16];
	buffer[i] = buff[ascii_code % 16];
	return (3);
}

/**
 * is_digit -Maxwell & Kagiso Verifies if a char is a digit.
 * @c: verifies char.
 * Return: return 1 if c is a digit,
 * 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * convert_size_num - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: the number type to be casted.
 * Return: return value of num
 */
long int convert_size_num(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}

/**
 * con_size_unsgnd -Maxwell and Kagiso Casts a number to the specified size
 * @num: Number to be casted.
 * @size: the number type to be casted.
 * Return: return the value of num
 */
long int con_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}

