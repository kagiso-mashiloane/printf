#include "main.h"
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
		if (!in[k])
		{
			x = len[i];
			write(1, &buff, 1);
			counter++;
		}
	i++;
	}
	return (counter);
}
