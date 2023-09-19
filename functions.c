#include "main.h"

/**
 * nice_str - fun to printing string
 * @boxs: this the list argment str
 *
 * Return: str word printing
 */

int nice_str(va_list boxs)
{
	char *word_print = va_arg(boxs, char *);

	int sum_number;
	int word_write = 0;

	if (word_print == NULL)
	{
		char no_string[] = "(null)";

		for (sum_number = 0; no_string[sum_number]; sum_number++)
		{
			word_write += printing_words(no_string[sum_number]);
		}
	}
	else
	{
		while (*word_print)
		{
			word_write += printing_words(*word_print);
			word_print++;
		}
	}

	return (word_write);
}


/**
 * nice_char - fun to printing character
 * @boxs: this the list argment
 *
 * Return: char word printing
 */

int nice_char(va_list boxs)
{
	char single = va_arg(boxs, int);

	return (printing_words(single));
}

/**
 * nice_percent - fun to printing percent
 * @boxs: this the list argment
 *
 * Return: percent word printing
 */

int nice_percent(va_list boxs)
{
	(void)boxs;
	return (printing_words('%'));
}

/**
 * nice_int - fun to printing integer
 * @boxs: this the list argment
 *
 * Return: int word printing
 */

int nice_int(va_list boxs)
{
	int sum_numbers = va_arg(boxs, int);
	char buffer[1024];
	int all = 0;
	char zero;
	int word_write = 0;
	unsigned int collect_numbers;

	if (sum_numbers == 0)
		word_write += printing_words(zero = sum_numbers + '0');

	if (sum_numbers > 0)
	{
		collect_numbers = sum_numbers;
	}

	if (sum_numbers < 0)
	{
		word_write += printing_words('-');

		collect_numbers = -sum_numbers;
	}
	else
	{
		collect_numbers = sum_numbers;
	}

	while (collect_numbers > 0)
	{
		buffer[all++] = '0' + (collect_numbers % 10);

		collect_numbers /= 10;
	}

	for (all = all - 1; all >= 0; all--)
	{
		word_write += printing_words(buffer[all]);
	}

	return (word_write);
}
