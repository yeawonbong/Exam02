#ifndef FT_PRINTF_H 
#define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int ft_strlen(char *str);
int isnum(char c);
char *pass_num(char *str);
int ft_atoi(char *str);
char *ft_itoa_base(int i, int base);

char *parse_opt(char *opt);
char    *print(va_list *ap);
int ft_printf(const char *input, ...);

#endif