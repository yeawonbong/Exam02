# include "ft_printf.h"

int ft_strlen(char *str)
{
	int len=0;

	while (*str && str[len])
	{
		len++;
	}
	return (len);
}

int isnum(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

char *pass_num(char *str)
{
	while (isnum(*str))
		str++;
	return (str);
}

int ft_atoi(char *str)
{
	int res=0;

	while (isnum(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

char *ft_itoa_base(int i, int base)
{
	int num = i;
	int len=1;
	char *res;
	int minus = 0;

	if (i == 0)
		return ("0");
	if (i < 0)
		minus = -1;
	while (0 < (i /= base))
		len++;
	if (minus == -1)
		len++;
	res = malloc(len + 1);
	res[len] = 0;
	while (0 <= --len)
	{
		if (len == 0 && minus == -1)
		{
			res[len] = '-';
			break;
		}
		if (num % base < 10)
			res[len] = num % base + '0';
		else
			res[len] = (num % base - 10) + 'a';
		num /= base;
	}
	return (res);
}