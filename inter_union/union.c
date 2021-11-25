#include <unistd.h>

int main(int argc, char *argv[])
{
	char ascii[127] = {0,};
 
	if (argc == 3)
	{
		for (int i=0; argv[1][i]; i++)
		{
			if (ascii[argv[1][i]]++ == 0)
				write(1, &argv[1][i], 1);
		}
		for (int i=0; argv[2][i]; i++)
        {
            if (ascii[argv[2][i]]++ == 0)
				write(1, &argv[2][i], 1);
        }
	}
	write(1, "\n", 1);
	return (0);
}

/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/
