#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int _printf(const char *format, ...);
int (*check_specifier(char*))(va_list);


/*
 * struct func - struct for specifier to printer
 * @t: character to compare
 * @f: function that handles the printing
 */
typedef struct func
{
	char *t;
	int (*f)(va_list);
} func_t;




int print_cent(va_list);
int print_char(va_list);
int print_str(va_list);
#endif
