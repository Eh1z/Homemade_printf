#include "main.h"



/*
 * check_specifier - check that character is a valid specifier and assigns an appropriate function for its printing.
 *
 * @format: the specifier (char*)
 *
 * Return: pointer to function
 */

int (*check_specifier(char *format))(va_list)
{
	int i;

	func_t my_array[3] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_cent},
		{NULL, NULL}
	};

	for (i = 0; my_array[i].t != NULL; i++)
	{
	if (*(my_array[i].t) == *format)
		{
			return (my_array[i].f);
		}
	}
		return NULL;

	}
};



/* print_char - formats and prints in character data type
 *
 * @args: variadic parameter
 *
 * return: number of characters printed
 */


int print_char(va_list args)
{
	char c = va_arg(args, char);
	int count = 0;

	if (c)
	{
		count = write(1, &c , 1);
		return(count);
	}
	return 0;
}

 /* print_str - formats and prints in string data type
 39  *
 40  * @args: variadic parameter
 41  *
 42  * return: number of characters printed
 43  */
 44
 45
 46 int print_str(va_list args)
 47 {
 48         char s = va_arg(args, char);
 49         int count = 0;
 50
 51         if (s)
 52         {
 53                 count = write(1, &s , 1);
 54                 return(count);
 55         }
 56         return 0;
 57 }


  /* print_cent - formats and prints in percent data type?
 39  *
 40  * @args: variadic parameter
 41  *
 42  * return: number of characters printed
 43  */
 44
 45
 46 int print_cent(va_list args)
 47 {
 48         char % = va_arg(args, char);
 49         int count = 0;
 50
 51         if (%)
 52         {
 53                 count = write(1, &% , 1);
 54                 return(count);
 55         }
 56         return 0;
 57 }





/*
 * _printf - prints a string in a formatted way
 * @format: string to print (char *)
 * @...: variable parameters that are unkown
 *
 * return: number of charcaters printed
 *
 *
 */



int _printf(const char *format, ...)
{
        int i = 0;
        int count = 0;
        int value = 0;
        va_list args;
        va_start(args, format);

        //Prevent parsing of null pointer
        if (format == NULL)
                return (-1);

        //Print each character of string
        while (format[i])
        {
                if (format[i] != '%')
                {
                        value = write(1, &format[i], 1);
                        count = count + value;
                        i++;
                        continue;
                }

                if (format[i] == '%')
                        f = check_specifier(format[i + 1]);
                if (f != NULL)
                {
                        value = f(args);
                        count = count + value;
                        i = i + 2;
                        continue;
                }
                {

                if (format[i + 1] == '\0')
                {
                        break;
                }
                if (format[i + 1] != '\0')
                {
                        value = write(1, &format[i], 1);
                        count = count + value;
                        i++;
                        continue;
                }
        }
        }

        return (count);
};
