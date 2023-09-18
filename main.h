#ifndef _PRINTF_H

#define _PRINTF _H



#include <stdarg.h>

#include <stdio.h>

#include <unistd.h>

#include <limits.h>

#include <stdlib.h>

#define OUTPUT BUF SIZE 1024
#define BUF FLUSH -1


#define NULL STRING "(null)"

#define PARAMS INIT (0, 0, 0, 0, 0, 0, 0, 0, 0, 0)

#define CONVERT LOWERCASE 1
#define CONVERT UNSIGNED 2

/**
 * struct parameters - parameters struct
 * @unsign: flag if unsigned value
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag flag specified
 * @hashtag_flag: on if_flag specified
 * @zero_flag: on if_flag specified
 * @minus_flag: on if_flag specified
 * @width: field width specified
 * @precision: field precision specifieda
 * @h modifier: on if h modifier is specified
 * @l modifier: on if 1 modifier is specifieda
*/
typedef struct parameters
{
unsigned int unsigna		: 1;

unsigned int plus flag		: 1;
unsigned int space flag		: 1;
unsigned int hashtag flag	: 1;
unsigned int zero flag		: 1;
unsigned int minus flag		: 1;

unsigned int width		: 1;
unsigned int precision		:1;

unsigned int h modifiera	: 1;
unsigned int 1 modifier		: 1;

}params_t;

/**

* struct specifier - Struct token
* @specifier: format token
* @f: The function associated
*/

typedef struct specifiera
{
char *specifier;

int (*f) (va_list, params_t *);

} specifier_t;

/* put.c module */

int puts (char *str);

int putchar (int c);

/* print functions.c module */

int print char (va list ap, params t *params);

int print int (va list ap, params t *params);

int print string(va_list ap, params_t *params);

int print percent (va list ap, params t *params);

int printS(va_list ap, params_t *params);

/* number.c module */

char *convert (long int num, int base, int flags, params t *params);
int print_unsigned(va_list ap, params_t *params);
int print address (va list ap, params t *params);

/* specifier.c module */
int (*get specifier(char *s)) (va list ap, params t *params);
int get print func(char *s, va list ap, params t *params);
int get_flag(char *s, params_t *params);
int get modifier(char *s, params t *params);
char *get width(char *s, params_t *params, va_list ap);

/* convert number.c module */

int print hex(va list ap, params t *params);
int print HEX(va list ap, params t *params);
int print binary(va_list ap, params_t *params);
int print octal(va list ap, params t *params);

/* simple printers.c module */

int print from to (char *start, char *stop, char *except);
int print rev(va list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/* print number.c module */
int isdigit (int c);
int strlen(char *s);
int print number (char *str, params t *params);
int print number right shift (char *str, params t *params);
int print number left shift (char *str, params t *params);

/* params.c module */
void init params (params t *params, va list ap);
/* string fields.c modoule */
char *get precision (char *p, params_t *params, va_list ap);

/* prinf.c module */
int printf(const char *format,...);
#endif
