#include "main.h"

/**
 * printing_words - this fun print words and sting
 * @look: look is used to print character and string
 *
 * Return: print returned words
 */

int printing_words(char look)
{
	return (write(1, &look, 1));
}
