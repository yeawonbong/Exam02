# include "ft_printf.h"

char	type = 0;
int		width = 0;
int 	precision = -1;

char	*ptr;
char	*out;

char *parse_opt(char *ptr)
{
	if (isnum(*ptr))
	{
		width = ft_atoi(ptr);
		ptr = pass_num(ptr);
	}
	if (*ptr == '.')
	{
		ptr++;
		if (!isnum(*ptr))
			precision = 0;
		else
		{
			precision = ft_atoi(ptr);
			ptr = pass_num(ptr);
		}
	}
	if (!(*ptr == 's' || *ptr == 'd' || *ptr == 'x'))
		return (0);
	else
		type = *ptr;
	return (ptr);
}

char*	print(va_list *ap)
{
	char *out;
	int	len=0;

	if (type == 's')
	{
		out = va_arg(*ap, char*);
		len = ft_strlen(out);
		if (precision != -1 && precision < len)
			len = precision;
		while (len < width--)
			write(1, " ", 1);
	}
	else
	{
		if (type == 'd')
			out = ft_itoa_base(va_arg(*ap, int), 10);
		if (type == 'x')
			out = ft_itoa_base(va_arg(*ap, unsigned int), 16);
		len = ft_strlen(out);
		if (len < precision)
			precision -= len;
		else
			precision = 0;
		while (len + precision < width--)
			write (1, " ", 1);
		while (precision--)
			write(1, "0", 1);
	}
	write(1, out, len);
	if (type != 's')
		free(out);
	type =0;
	width =0;
	precision =-1;
	out = 0;
	return (++ptr);
}

int ft_printf(const char *input, ...)
{
	va_list	ap;
	ptr = (char*)input;
	va_start(ap, input);
	while (*ptr)
	{
		while (*ptr && *ptr != '%')
		{
			write(1, ptr, 1);
			ptr++;
		}
		if (*ptr && *ptr == '%')
		{
			ptr++;
			ptr = parse_opt(ptr);
			ptr = print(&ap);
		}
	}
	return (0);
}