#include "main.h"

/**
 * _printf - this is function to printing word
 * @format: format for fun to print
 *
 * Return: return words that is print
 */

int _printf(const char *format, ...)
{
	va_list door;
	int nums_for_print = 0, nums_55 = 0, sum_the_words = 0;
	home_t books[] = {
	{'d', nice_int},
	{'c', nice_char},
	{'s', nice_str},
	{'%', nice_percent},
	{'i', nice_int},
	{0, NULL}};
	va_start(door, format);
	if (!format)
		return (-1);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	for (nums_for_print = 0; format[nums_for_print]; nums_for_print++)
	{
		if (format[nums_for_print] == '%')
		{
			while (format[nums_for_print + 1] == ' ')
			{
				nums_for_print++;
				if (!format[nums_for_print + 1])
					return (-1);
			}
			for (nums_55 = 0; books[nums_55].book; nums_55++)
				if (format[nums_for_print + 1] == books[nums_55].book)
				{
					sum_the_words += books[nums_55].take(door);
					nums_for_print++;
					break;
				}
			if (books[nums_55].book == 0)
				sum_the_words += write(1, &(format[nums_for_print]), 1);
		}
		else
			sum_the_words += printing_words(format[nums_for_print]);
	}
	va_end(door);
	return (sum_the_words);
}
