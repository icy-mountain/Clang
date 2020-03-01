/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:50:37 by ykori             #+#    #+#             */
/*   Updated: 2020/02/11 12:13:56 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	idx0;
	char	idx1;
	char	idx2;

	idx0 = '0';
	while (idx0 <= '7')
	{
		idx1 = idx0 + 1;
		while (idx1 <= '8')
		{
			idx2 = idx1 + 1;
			while (idx2 <= '9')
			{
				write(1, &idx0, 1);
				write(1, &idx1, 1);
				write(1, &idx2, 1);
				if (idx0 == '7' && idx1 == '8' && idx2 == '9')
					return ;
				write(1, ", ", 2);
				idx2++;
			}
			idx1++;
		}
		idx0++;
	}
}
