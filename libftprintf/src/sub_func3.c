/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_func3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <ykori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:58:59 by ykori             #+#    #+#             */
/*   Updated: 2020/06/23 16:02:00 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void			for_n(int *p, t_format *f)
{
	*p = f->rtn;
}

const char		*exist_parcent(const char *str, t_format *f)
{
	find_flags(str + 1, f);
	find_padding(str + 1, f);
	find_pred(str + 1, f);
	str = reach_type(str + 1);
	f->type = which_type(str);
	if (f->type != 'E')
		str += 1;
	if (f->type == 'I' || f->type == 'l' || f->type == 'L' || f->type == 'U')
		str += 2;
	return (str);
}

void			which_spec(t_format *f)
{
	if (f->type == 'd' || f->type == 'i')
		pf_putnbr_i(va_arg(f->args, int), f);
	else if (f->type == 'I')
		pf_putnbr_ll(va_arg(f->args, long long), f);
	else if (f->type == 'u')
		pf_putnbr_ui(va_arg(f->args, unsigned int), f);
	else if (f->type == 'U')
		pf_putnbr_ull(va_arg(f->args, unsigned long long), f);
	else if (f->type == 'x' || f->type == 'X')
		putbase_ui(va_arg(f->args, unsigned int), f);
	else if (f->type == 'l' || f->type == 'L')
		putbase_ull(va_arg(f->args, unsigned long long), f);
	else if (f->type == 'c')
		pf_putchar(va_arg(f->args, int), f);
	else if (f->type == 's')
		pf_putstr(va_arg(f->args, char *), f);
	else if (f->type == 'p')
		put_p(va_arg(f->args, void *), f);
	else if (f->type == 'n')
		for_n(va_arg(f->args, int *), f);
	else if (f->type == '%')
		pf_putchar('%', f);
}
