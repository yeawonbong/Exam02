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

/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "nothing" "This sentence hides nothing" | cat -e
nothig$
$>./inter | cat -e
$
*/