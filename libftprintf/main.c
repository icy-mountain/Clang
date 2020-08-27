#include <stdio.h>
#include "include/libftprintf.h"

int		main(void){
	int lib;
	int ft;
	// long unsigned int test;
	// test = 0;
	// printf("%d %d\n", test, );
	// lib = printf("lib[%p]\n", -1);
	// ft = ft_printf("ft:[%p]\n", -1);
	// ft_printf("ft[%5.x]\n", NULL);
	// lib = printf("lib[%09s]\n", NULL);
	// ft = ft_printf("ft:[%09s]\n", NULL);

	char s[] = "hello!";
	lib = printf("lib[%10.3s]\n", s);
	ft = ft_printf("ft:[%10.3s]\n", s);

	printf("lib:%d ft:%d\n", lib - 6, ft - 6);
	return (0);
}
