/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:21:05 by ykori             #+#    #+#             */
/*   Updated: 2020/02/14 11:54:22 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
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

int		rec_prime(int nb, int prime, int max)
{
	if (nb % prime == 0)
		return (0);
	if (prime >= max)
		return (1);
	else
		return (rec_prime(nb, prime + 2, max));
}

int		my_prime(int nb)
{
	if (nb == 2 || nb == 5 || nb == 7)
		return (1);
	if (nb < 2 || nb % 2 == 0 || nb % 3 == 0 || nb % 5 == 0)
		return (0);
	return (rec_prime(nb, 7, nb / 2));
}
