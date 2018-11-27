/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 01:51:19 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/27 03:59:39 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	do_echo(t_file *s_file)
{
	int i;

	i = 1;
	while (s_file->comm[i] != NULL)
	{
		ft_putstr(s_file->comm[i]);
		i++;
		ft_putchar(' ');
	}
	ft_putchar('\n');
}