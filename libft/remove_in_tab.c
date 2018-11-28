/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_in_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 05:32:02 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/28 15:09:44 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**remove_in_tab(char **tab, int size, int pos)
{
	int		i;
	int		i2;
	char	**new;

	i = 0;
	i2 = 0;
	if (!(new = (char**)malloc(sizeof(char*) * (size - 1))))
		return (NULL);
	while (i2 < size)
	{
		if (i2 == pos)
			i2++;
		if (tab[i2] == NULL)
			return (new);
		new[i] = ft_strdup(tab[i2]);
		i++;
		i2++;
	}
	return (new);
}
