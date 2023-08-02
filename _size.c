#include "main.h"
/**
 * _size -By Kagiso and Maxwell Calculates the size.
 * @format: print the arguments in a formatted string.
 * @i: variable int.
 * Return: return size.
 */
int _size(const char *format, int *i)
{
	int size = 0;
	int k = *i + 1;

	if (format[k] == 'l')
		size = S_LONG;
	else if (format[k] == 'h')
		size = S_SHORT;
	if (size == 0)
		*i = k - 1;
	else
		*i = k;
	return (size);
}
