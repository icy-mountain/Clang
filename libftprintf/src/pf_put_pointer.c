/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:23:06 by ykori             #+#    #+#             */
/*   Updated: 2020/02/18 13:56:09 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	dot_flag(long unsigned int nb, char *base, t_format *f)
{
	int	size;

	size = ft_numlen_lui(nb, 16);
	f->pad -= 2;
	f->rtn += size + 2;
	while (f->flag % fl2pn('-') != 0 && f->pred < f->pad-- && f->rtn++ > -1)
		ft_putchar(' ');
	write(1, "0x", 2);
	if (nb == 0 && f->pred == 0 && f->rtn-- > -1)
		return ;
	while (size++ < f->pred && f->rtn++ > -1)
		ft_putchar('0');
	ft_put_pointer(nb, base);
	while (f->flag % fl2pn('-') == 0 && f->pred < f->pad-- && f->rtn++ > -1)
		ft_putchar(' ');
}

static void	minus_flag(long unsigned int nb, char *base, t_format *f)
{
	int	size;

	size = ft_numlen_lui(nb, 16) + 2;
	f->rtn += size;
	write(1, "0x", 2);
	ft_put_pointer(nb, base);
	while (size < f->pad-- && f->rtn++ > -1)
		ft_putchar(' ');
}

static void	other_flag(long unsigned int nb, char *base, t_format *f)
{
	int	size;

	size = ft_numlen_lui(nb, 16) + 2;
	f->rtn += size;
	while (size < f->pad-- && f->rtn++ > -1)
		ft_putchar(' ');
	write(1, "0x", 2);
	ft_put_pointer(nb, base);
}

void		pf_put_pointer(long unsigned int nb, char *base, \
	t_format *f)
{
	if (f->flag % fl2pn('.') == 0 && nb == 0 && f->pred == 0)
	{
		dot_flag(nb, base, f);
		while (f->flag % fl2pn('-') == 0 && f->pred < f->pad-- && \
			f->rtn++ > -1)
			ft_putchar(' ');
		return ;
	}
	if (f->pred < ft_numlen((long long)nb, 16))
		f->pred = ft_numlen((long long)nb, 16);
	if (f->flag % fl2pn('.') == 0)
		dot_flag(nb, base, f);
	else if (f->flag % fl2pn('-') == 0)
		minus_flag(nb, base, f);
	else
		other_flag(nb, base, f);
}
