#include "main.h"

/**
 * printing_words - this fun print words
 * @look: look is used to print character
 *
 * Return: print returned words
 */

int printing_words(char look)
{
	return (write(1, &look, 1));
}
