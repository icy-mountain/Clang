/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <ykori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:58:59 by ykori             #+#    #+#             */
/*   Updated: 2020/06/23 16:02:00 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_printf(const char *str, ...)
{
	t_format	*f;
	int			rtn;

	f = malloc(sizeof(t_format) * (1));
	if (f == NULL || str == NULL)
		return (-1);
	format_init(f);
	f->rtn = 0;
	va_start(f->args, str);
	while (*str != '\0' && f->rtn != -1)
	{
		if (*str == '%')
			str = exist_parcent(str, f);
		// printf("str:%c type:%c padd:%i pred:%i\n", str[0], f->type, f->pad, f->pred);
		if (f->type != '!' && f->type != 'E')
			which_spec(f);
		else
			pf_putchar(*(str++), f);
		format_init(f);
	}
	va_end(f->args);
	rtn = f->rtn;
	free(f);
	return (rtn);
}
