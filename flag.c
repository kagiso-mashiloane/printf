#include "main.h"
/**
 * flag - by Kagiso & Maxwell Calculates active flags
 * @format: print the arg in a formatted string
 * @i: interger.
 * Return: return flag
 */
int flag(const char *format, int *i)
{
	const char buff[] = {'-', '+', '0', '#', ' ', '\0'};
	const int len[] = { F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE,  F_MINUS,  0};
	int k, j;
	int flag = 0;

	j = *i + 1;
	while (format[j] != '\0')
	{
		for (k = 0; buff[k] != '\0'; k++)
			if (format[j] == buff[k])
			{
				flag |= len[k];
				break;
			}
		if (buff[k] == 0)
			break;
	 j++
	}
	*i = j - 1;
	return (flag);
}

