# include "ft_printf.h"
int main()
{
	// printf("%d and %.4swow%d\n", 45, "hi",5);
	// ft_printf("%d and %.4swow%d\n", 45, "hi",5);
	ft_printf("%10.2s\n", "toto");
	ft_printf("Magic %s is %5d\n", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	return 0;
}

