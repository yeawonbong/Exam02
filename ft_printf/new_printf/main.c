#include <stdio.h>

int ft_printf(const char *input, ...);

int main(void)
{
	printf("hex: %d, %x\n", -4200, -4200);
	ft_printf("hex: %d, %x\n", -4200, -4200);
	while (1){}
}
