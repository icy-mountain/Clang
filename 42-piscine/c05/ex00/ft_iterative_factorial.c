/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:51:08 by ykori             #+#    #+#             */
/*   Updated: 2020/02/14 13:17:34 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		ans;

	if (nb < 0)
		return (0);
	ans = 1;
	while (nb > 0)
	{
		ans *= nb;
		nb--;
	}
	return (ans);
}