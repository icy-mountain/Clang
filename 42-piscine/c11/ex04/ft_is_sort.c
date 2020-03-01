/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:29:26 by ykori             #+#    #+#             */
/*   Updated: 2020/02/24 19:49:43 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		flag;
	int		idx;

	flag = 0;
	idx = 0;
	while (idx < length - 1)
	{
		if (flag != 0)
		{
			if (flag > 0 && f(tab[idx], tab[idx + 1]) < 0)
				return (0);
			if (flag < 0 && f(tab[idx], tab[idx + 1]) > 0)
				return (0);
		}
		if (f(tab[idx], tab[idx + 1]) != 0)
			flag = f(tab[idx], tab[idx + 1]);
		idx++;
	}
	return (1);
}
