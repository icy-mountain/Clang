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
	//確認事項　presition 0 引数0の時の挙動
	// presitionがマイナスの時の挙動
	// -:2 .:3 0:5 *:7 #:11 ' ':13 +:17 

	char s[] = "hello!";
	lib = printf("lib[%10.3s]\n", s);
	ft = ft_printf("ft:[%10.3s]\n", s);

	// -1を入れた時の挙動が一致しないから、態々long long とint を分けた
	// lib = printf("lib[% -.0lld]\n", (long long)INT_MIN);
	// ft = ft_printf("ft:[% -.0lld]\n", (long long)INT_MIN);

	// .predで、predが入力されなかったとき,pred < -1の時はpred = length
	// lib = printf("lib[%#*.*x]\n", 0, 5, 2);
	// ft = ft_printf("ft:[%#*.*x]\n", 0, 5, 2);
	// lib = printf("lib[%.8d]\n", 3);
	// ft = ft_printf("ft:[%.8d]\n", 3);
	// lib = printf("lib[*% -.* i]\n", 10, -123);
	// ft = ft_printf("ft:[% -.* i]\n", 10, -123);

	// *の解釈違い
	// ft = ft_printf("ft:[%-14i]\n", 94827);
	// int g, n;
	// lib = printf("lib[%p01234567%n]\n", &g, &g);
	// ft = ft_printf("ft:[%p01234567%n]\n", &n, &n);
	// printf("lib->%i ft->%i\n", g, n);
	
	// NULLチェック
	// lib = printf(NULL);
	// ft = ft_printf(NULL);
	
	// lib = printf("lib[%#-16x]\n", -255);
	// ft = ft_printf("ft:[%#-16x]\n", -255);
	
	//+の挙動が一致しないよ。undefinedだもの
	// lib = printf("lib[%#-+ 0p]\n", &n);
	// ft = ft_printf("ft:[%#- 0p]\n", &n);

	// //型チェック
	// if(__builtin_types_compatible_p(typeof(a), int))
	// 	puts("true")
	printf("lib:%d ft:%d\n", lib - 6, ft - 6);
	return (0);
}
