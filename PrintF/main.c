#include <stdio.h>
#include "main.h"

/*
 * main - test our files
 * 
 * Return: always 0
 */

int main (void){

	int len1 = 0;
	int len2 = 0;

	write(1, "Standard:\n", 10);
	len1 = printf("Let's try to printf a simple sentence.\n");
	printf("Length: %d\n", len1);

	write(1, "----------\n", 11);

	write(1, "Our Personal Function\n", 22);
	len2 = _printf("Let's try  % to printf a simple sentence.\n");
	printf("Length: %d\n", len2);

	return (0);
}
