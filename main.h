#ifndef WORD_FILE
#define WORD_FILE

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct world - this for struct for print
 * @book: for printing the world
 * @take: this a fun for the struct
 *
 */

typedef struct world
{
	char book;
	int (*take)(va_list boxs);
} world_t;


int _printf(const char *format, ...);

int look_for_str(va_list boxs);
int look_for_int(va_list boxs);
int look_for_char(va_list boxs);
int look_for_percent(va_list boxs);

int printing_words(char look);


#endif
