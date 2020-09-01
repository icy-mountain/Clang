/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykori <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:38:29 by ykori             #+#    #+#             */
/*   Updated: 2020/02/27 13:54:21 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **s1, char **s2)
{
	char	*buf;

	buf = *s1;
	*s1 = *s2;
	*s2 = buf;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		max;
	int		flag;
	int		idx;

	flag = 1;
	max = 0;
	if (tab[0] == 0)
		return ;
	while (tab[max] != 0)
		max++;
	while (flag == 1)
	{
		idx = max - 2;
		flag = 0;
		while (idx >= 0)
		{
			if (cmp(tab[idx], tab[idx + 1]) > 0)
			{
				swap(&tab[idx], &tab[idx + 1]);
				flag = 1;
			}
			idx--;
		}
	}
}
