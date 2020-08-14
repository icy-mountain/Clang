/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <ykori@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:58:59 by ykori             #+#    #+#             */
/*   Updated: 2020/06/23 16:02:00 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		find_flags(const char *str, t_format *f)
{
	while (which_type(str) == 'E' && *str != '\0')
	{
		if (*str == '-' && f->flag % 2 != 0)
			f->flag *= 2;
		else if (*str == '.' && f->flag % 3 != 0)
			f->flag *= 3;
		else if (*str == '0' && f->flag % 5 != 0)
			f->flag *= 5;
		else if (*str == '*' && f->flag % 7 != 0)
			f->flag *= 7;
		else if (*str == '#' && f->flag % 11 != 0)
			f->flag *= 11;
		else if (*str == ' ' && f->flag % 13 != 0)
			f->flag *= 13;
		else if (*str == '+' && f->flag % 17 != 0)
			f->flag *= 17;
		str++;
		while ('0' <= *str && *str <= '9')
			str++;
	}
}

/*
** find_padd
*/

void		find_padding(const char *str, t_format *f)
{
	while (*str != '.' && which_type(str) == 'E' && *str != '\0')
	{
		if (*str == '*')
		{
			f->pad = va_arg(f->args, int);
			if (f->pad < 0 && (f->pad *= -1) > 0)
				f->flag *= fl2pn('-');
			return ;
		}
		if ('1' <= *str && *str <= '9')
		{
			while ('0' <= *str && *str <= '9')
				f->pad = 10 * f->pad + *(str++) - '0';
			return ;
		}
		str++;
	}
}

void		find_pred(const char *str, t_format *f)
{
	while (which_type(str) == 'E' && *str != '\0')
	{
		if (*str == '.' && *(str++) != '\0')
		{
			if (*str == '*')
			{
				f->pred = va_arg(f->args, int);
				return ;
			}
			while ('0' <= *str && *str <= '9')
				f->pred = 10 * f->pred + *(str++) - '0';
			return ;
		}
		str++;
	}
}

const char	*reach_type(const char *str)
{
	const char	*save;

	save = str - 1;
	while (which_type(str) == 'E' && *str != '\0')
		str++;
	if (*str == '\0')
		str = save;
	return (str);
}

void		format_init(t_format *f)
{
	f->flag = 1;
	f->pad = 0;
	f->pred = 0;
	f->type = '!';
}
