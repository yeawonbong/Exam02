
int ft_strlen(char *str)
{
	int len=0;

	while (*str && str[len])
		len++;
	return (len);
}

char *empty_line()
{
	char *ret;

	ret = (char*)malloc(1);
	ret[0] = 0;
	return (ret);
}

char *append(char *str, char c)
{
	int     len = ft_strlen(str);
	char    *ret;

	if (str == 0)
		return (0);
	ret = malloc(len + 2);
	for (int i=0; i < len; i++)
		ret[i] = str[i];	
	ret[len] = c;
	ret[len + 1] = 0;
	return (ret);
}

int get_next_line(char **line)
{
	static char *save;
	char        buf;
	int         rs;
	char        *temp=0;

	while((rs = read(0, &buf, 1) > 0))
	{
		if (save == 0)
			save = empty_line();
		if (buf == '\n')
		{
			*line = save;
			save = 0;
			return (1);
		}
		temp = save;
		save = append(temp, buf);
		free(temp);
	}
	if (rs == 0)
	{
		if (save == 0)
			*line = empty_line();
		else
			*line = save;
		save = 0;
		return(0);
	}
	if (rs < 0 && save != 0)
	{
		free(save);
		save = 0;
	}
	return (-1);
}