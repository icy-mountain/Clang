/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr_ull.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:28:57 by ykori             #+#    #+#             */
/*   Updated: 2020/02/25 08:53:50 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	dot_flag(unsigned long long nb, t_format *f)
{
	int	size;

	size = ft_numlen_ull(nb, 10);
	f->rtn += size;
	while (f->flag % fl2pn('-') != 0 && f->pred < f->pad-- && f->rtn++ > -1)
		ft_putchar(' ');
	if (nb == 0 && f->pred == 0 && f->rtn-- > -1)
		return ;
	while (size++ < f->pred && f->rtn++ > -1)
		ft_putchar('0');
	ft_putnbr_ull(nb);
	while (f->flag % fl2pn('-') == 0 && f->pred < f->pad-- && f->rtn++ > -1)
		ft_putchar(' ');
}

static void	minus_flag(unsigned long long nb, t_format *f)
{
	int	size;

	size = ft_numlen_ull(nb, 10);
	f->rtn += size;
	ft_putnbr_ull(nb);
	while (size < f->pad-- && f->rtn++ > -1)
		ft_putchar(' ');
}

static void	zero_flag(unsigned long long nb, t_format *f)
{
	int	size;

	size = ft_numlen_ull(nb, 10);
	while (size < f->pad-- && f->rtn++ > -1)
		ft_putchar('0');
	f->rtn += size;
	ft_putnbr_ull(nb);
}

static void	other_flag(unsigned long long nb, t_format *f)
{
	int	size;

	size = ft_numlen_ull(nb, 10);
	while (size < f->pad-- && f->rtn++ > -1)
		ft_putchar(' ');
	f->rtn += size;
	ft_putnbr_ull(nb);
}

void		pf_putnbr_ull(unsigned long long nb, t_format *f)
{
	if (f->flag % fl2pn('.') == 0 && nb == 0 && f->pred == 0)
	{
		dot_flag(nb, f);
		while (f->flag % fl2pn('-') == 0 && f->pred < f->pad-- && \
			f->rtn++ > -1)
			ft_putchar(' ');
		return ;
	}
	if (f->pred < ft_numlen_ull(nb, 10))
		f->pred = ft_numlen_ull(nb, 10);
	if (f->flag % fl2pn('.') == 0)
		dot_flag(nb, f);
	else if (f->flag % fl2pn('-') == 0)
		minus_flag(nb, f);
	else if (f->flag % fl2pn('0') == 0)
		zero_flag(nb, f);
	else
		other_flag(nb, f);
}
