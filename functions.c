#include "main.h"

/**
 * look_for_str - fun to printing string
 * @boxs: this the list argment
 *
 * Return: str word printing
 */

int look_for_str(va_list boxs)
{
	int word_write = 0;

	char *str = va_arg(boxs, char *);

	while (*str)
	{
		word_write += printing_words(*str);
		str++;
	}

	return (word_write);
}

/**
 * look_for_char - fun to printing character
 * @boxs: this the list argment
 *
 * Return: char word printing
 */

int look_for_char(va_list boxs)
{
	char single = va_arg(boxs, int);

	return (printing_words(single));
}

/**
 * look_for_percent - fun to printing percent
 * @boxs: this the list argment
 *
 * Return: percent word printing
 */

int look_for_percent(va_list boxs)
{
	(void)boxs;
	return (printing_words('%'));
}

/**
 * look_for_int - fun to printing integer
 * @boxs: this the list argment
 *
 * Return: int word printing
 */

int look_for_int(va_list boxs)
{
	int sum_numbers = va_arg(boxs, int);
	char buffer[1024];
	int all = 0;
	int word_write = 0;

	if (sum_numbers < 0)
	{
		word_write += printing_words('-');

		sum_numbers = -sum_numbers;
	}

	while (sum_numbers > 0)
	{
		buffer[all++] = '0' + (sum_numbers % 10);

		sum_numbers /= 10;
	}

	for (all = all - 1; all >= 0; all--)
	{
		word_write += printing_words(buffer[all]);
	}

	return (word_write);
}
