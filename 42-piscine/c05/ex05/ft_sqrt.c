/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:42:28 by ykori             #+#    #+#             */
/*   Updated: 2020/02/14 11:53:54 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		rec_sqrt(int nb, int ans)
{
	if (ans >= 46341)
		return (0);
	if (ans * ans == nb)
		return (ans);
	else
		return (rec_sqrt(nb, ans + 1));
}

int		ft_sqrt(int nb)
{
	return (rec_sqrt(nb, 1));
}
