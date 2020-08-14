/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:28:57 by ykori             #+#    #+#             */
/*   Updated: 2020/02/25 08:53:50 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	dot_flag(char *s, t_format *f)
{
	int thre;
	int	c;

	c = 0;
	thre = ft_strlen(s) < f->pred ? ft_strlen(s) : f->pred;
	while (f->flag % fl2pn('-') != 0 && thre < f->pad-- && f->rtn++ > -1)
		ft_putchar(' ');
	while (c++ < thre && f->rtn++ > -1)
		ft_putchar(*(s++));
	while (f->flag % fl2pn('-') == 0 && thre < f->pad-- && f->rtn++ > -1)
		ft_putchar(' ');
}

static void	minus_flag(char *s, t_format *f)
{
	int	size;

	size = ft_strlen(s);
	f->rtn += size;
	ft_putstr(s);
	while (size < f->pad-- && f->rtn++ > -1)
		ft_putchar(' ');
}

static void	other_flag(char *s, t_format *f)
{
	int	size;

	size = ft_strlen(s);
	while (f->flag % fl2pn('0') == 0 && size < f->pad-- && f->rtn++ > -1)
		ft_putchar('0');
	while (f->flag % fl2pn('0') != 0 && size < f->pad-- && f->rtn++ > -1)
		ft_putchar(' ');
	f->rtn += size;
	ft_putstr(s);
}

void		pf_putstr(char *s, t_format *f)
{
	int	flag;

	flag = 0;
	if (s == NULL)
	{
		flag = 1;
		f->pred = f->pred < 0 ? 6 : f->pred;
		s = ft_strdup("(null)");
		if (s == NULL && (f->rtn = -1) == -1)
			return ;
	}
	else
		f->pred = f->pred < 0 ? ft_strlen(s) : f->pred;
	if (f->flag % fl2pn('.') == 0)
		dot_flag(s, f);
	else if (f->flag % fl2pn('-') == 0)
		minus_flag(s, f);
	else
		other_flag(s, f);
	if (flag == 1)
		free(s);
}
