# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int ft_strlen(char *str)
{
	int len=0;

	while (*str && str[len])
		len++;
	return (len);
}

char *itoa_base(long long num, int base)
{
	int len=1;
	char *res;
	int minus = 0;

	if (num == 0)
		return ("0");
	if (num < 0)
	{
		len++;
		minus = -1;
		num *= -1;
	}
	long long tempN = num;
	while (0 < (tempN /= base))
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

int ft_printf(const char *input, ...)
{
	va_list	ap;
	va_start(ap, input);
	char* res;

	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (*input == 's')
				write(1, input, 1);
			else if (*input == 'd')
				res = itoa_base((long long)va_arg(ap, int), 10);
			else if (*input == 'x')
				res = itoa_base((long long)va_arg(ap, unsigned int), 16);
			write(1, res, ft_strlen(res));
			if (*input != 's')
				free(res);
		}
		else
			write(1, input, 1);
		input++;
	}
	return (0);
}