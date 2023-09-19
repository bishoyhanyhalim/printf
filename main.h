#ifndef WORD_FILE
#define WORD_FILE

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct home - this for struct for print
 * @book: for printing the home struct
 * @take: this a function for the struct
 *
 */

typedef struct home
{
	char book;
	int (*take)(va_list boxs);
} home_t;


int _printf(const char *format, ...);

int nice_str(va_list boxs);
int nice_int(va_list boxs);
int nice_char(va_list boxs);
int nice_percent(va_list boxs);

int printing_words(char look);


#endif
