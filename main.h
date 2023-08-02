#ifndef MAIN_H
#define MAIN_H

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define F_MINUS 1
#define F_PLUS 2
#define S_LONG 2
#define S_SHORT 1

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _precision(const char *format, int *i, va_list list);
int _printf(const char *format, ...);
void print_buff(char buffer[], int *buff_ind);
void print_buff(char buffer[], int *buff_ind);
int _size(const char *format, int *i);
int _width(const char *format, int *i, va_list list);
int flag(const char *format, int *i);

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size);
int _print_binary(va_list list, char buffer[],
int field_width, int flag, int size, int precision);
int _print_char(va_list list, char buffer[],
	int field_width, int flag, int precision, int size);
int _print_hexa(va_list list, char buffer[], char map_to[],
	int field_width, char flag_ch, int flag, int size, int precision)
int _print_hexadecimal(va_list list, char buffer[],
	int field_width, int flag, int size, int precision);
int _print_int(va_list list, char buffer[],
	int field_width, int flag, int size, int precision);
int _print_non_printable(va_list list, char buffer[],
	int field_width, int flag, int size, int precision);
int _print_octal(va_list list, char buffer[],
	int field_width, int flag, int size, int precision);
int _print_pointer(va_list list, char buffer[],
	int field_width, int flag, int size, int precision);
int _print_reverse(va_list list, char buffer[],
	int field_width, int flag, int size, int precision);
int _print_rot13string(va_list list, char buffer[],
	int field_width, int flag, int size, int precision);
int _print_percent(va_list list, char buffer[],
	int field_width, int flag, int size, int precision);
int _print_string(va_list list, char buffer[],
	int field_width, int flag, int size, int precision);
int print_types(const char *fmt, int *ind, va_list list, char buffer[],
	int field_width, int flag, int size, int precision);
int _print_unsigned(va_list list, char buffer[],
	int field_width, int flag, int size, int precision);

int is_printable(char c);
int _hexa_code(char ascii_code, char buffer[], int i);
int is_digit(char c);

long int convert_size_num(long int num, int size);
long int con_size_unsgnd(unsigned long int num, int size);

#endif
