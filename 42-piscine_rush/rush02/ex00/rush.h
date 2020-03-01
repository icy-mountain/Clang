/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuehara <yuehara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 10:14:27 by yuehara           #+#    #+#             */
/*   Updated: 2020/02/23 21:36:34 by ykori            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int		ft_checkargv(int elm, char *elmv, char *dict);

int		dict_check(char *dict);

void	ft_init(char *str, int size);

int		str_len(char *str, char end);

void	str_ncpy(char *dest, char *src, int size);

int		set_dict(char *dict, char *filename, int size);

char	*search_val(char *dict, char *key);

int		search_index(char *dict, char *key);

void	write_sp(char *key, char *argv);

void	read_argv(char *argv, char *dict);

#endif
