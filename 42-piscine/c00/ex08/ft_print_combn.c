/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:50:37 by ykori             #+#    #+#             */
/*   Updated: 2020/02/11 12:14:53 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	initialize(char *arr)
{
	int		idx;
	int		c;

	idx = -1;
	c = '/';
	while (++idx < 10)
	{
		arr[idx] = c++;
	}
}

void	rec_print_combn(int n, char *arr, int main_n)
{
	if (n == 1)
	{
		arr[main_n - 1] = main_n == 1 ? '/' : arr[main_n - 2];
		while (++arr[main_n - 1] <= '9')
		{
			write(1, arr, main_n);
			arr[0] == 10 - main_n + 48 ? 0 : write(1, ", ", 2);
		}
	}
	else if (n > 1)
	{
		arr[main_n - n] = n < main_n ? arr[main_n - n - 1] : arr[main_n - n];
		while (++arr[main_n - n] <= 10 - n + 48)
		{
			rec_print_combn(n - 1, arr, main_n);
		}
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];

	initialize(arr);
	rec_print_combn(n, arr, n);
}
