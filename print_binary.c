#include "main.h"
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
char z = '0' + a[j];
write(1, &z, 1);
counter++;
}
}
return (counter);
}
