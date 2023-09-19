#include "main.h"

/**
 * _printf - fun to printing words
 * @format: this is the format for fun
 *
 * Return: return printing words
 */

int _printf(const char *format, ...)
{
	va_list boxs;
	int number_print = 0, numbers_2 = 0, words_to_print = 0;

	world_t texts[] = {
		{'d', look_for_int},
		{'c', look_for_char},
		{'s', look_for_str},
		{'%', look_for_percent},
		{'i', look_for_int},
		{0, NULL}
	};
	va_start(boxs, format);
	if (!format)
		return (-1);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	for (number_print = 0; format[number_print]; number_print++)
	{
		if (format[number_print] == '%')
		{
			while (format[number_print + 1] == ' ')
			{
				number_print++;
				if (!format[number_print] + 1)
					return (-1);
			}
			for (numbers_2 = 0; texts[numbers_2].book; numbers_2++)
			{
				if (format[number_print + 1] == texts[numbers_2].book)
					words_to_print += texts[numbers_2].take(boxs);
			}
			if (texts[numbers_2].book == '0')
				words_to_print += texts[numbers_2].take(boxs);
			number_print++;
		}
		else
			words_to_print += printing_words(format[number_print]);
	}
	va_end(boxs);
	return (words_to_print);
}
