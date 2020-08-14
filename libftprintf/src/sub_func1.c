/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_func1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <ykori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:58:59 by ykori             #+#    #+#             */
/*   Updated: 2020/06/23 16:02:00 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		putbase_ui(unsigned int num, t_format *f)
{
	if (f->type == 'X')
		pf_putnbr_base_ui(num, "0123456789ABCDEF", f);
	if (f->type == 'x')
		pf_putnbr_base_ui(num, "0123456789abcdef", f);
}

void		putbase_ull(unsigned long long num, t_format *f)
{
	if (f->type == 'L')
		pf_putnbr_base_ull(num, "0123456789ABCDEF", f);
	if (f->type == 'l')
		pf_putnbr_base_ull(num, "0123456789abcdef", f);
}

void		put_p(void *p, t_format *f)
{
	uintptr_t	pp;

	pp = (long unsigned int)p;
	pf_put_pointer(pp, "0123456789abcdef", f);
}

char		which_type2(char const *str)
{
	if (*(str++) == 'l' && *(str++) == 'l')
	{
		if (*str == 'i' || *str == 'd')
			return ('I');
		if (*str == 'x')
			return ('l');
		if (*str == 'X')
			return ('L');
		if (*str == 'u')
			return ('U');
	}
	return ('E');
}

char		which_type(char const *str)
{
	if (*str == 'c')
		return ('c');
	if (*str == 's')
		return ('s');
	if (*str == 'p')
		return ('p');
	if (*str == 'd')
		return ('d');
	if (*str == 'i')
		return ('i');
	if (*str == 'u')
		return ('u');
	if (*str == 'x')
		return ('x');
	if (*str == 'X')
		return ('X');
	if (*str == 'n')
		return ('n');
	if (*str == '%')
		return ('%');
	return (which_type2(str));
}
