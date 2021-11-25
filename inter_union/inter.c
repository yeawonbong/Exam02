#include <unistd.h>

int main(int argc, char *argv[])
{
	char ascii[127] = {0,};
 
	if (argc == 3)
	{
		for (int i=0; argv[2][i]; i++)
			ascii[argv[2][i]] = 1;
		for (int i=0; argv[1][i]; i++)
		{
			if (ascii[argv[1][i]]++ == 1)
				write(1, &argv[1][i], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
