/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:45:43 by ykori             #+#    #+#             */
/*   Updated: 2020/02/14 12:00:54 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_prime(int nb)
{
	int		prime;

	prime = 7;
	if (nb == 2 || nb == 3 || nb == 5)
		return (1);
	if (nb < 2 || nb % 2 == 0 || nb % 3 == 0 || nb % 5 == 0)
		return (0);
	while (prime <= nb / 2)
	{
		if (nb % prime == 0)
			return (0);
		prime += 2;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	while (nb <= 2147483647)
	{
		if (is_prime(nb))
			break ;
		nb++;
	}
	return (nb);
}
