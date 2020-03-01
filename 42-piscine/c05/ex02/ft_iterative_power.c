/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:11:06 by ykori             #+#    #+#             */
/*   Updated: 2020/02/13 18:22:41 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int		ans;

	ans = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power-- >= 1)
		ans *= nb;
	return (ans);
}
