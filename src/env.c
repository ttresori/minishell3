/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 03:18:30 by ttresori          #+#    #+#             */
/*   Updated: 2019/01/21 03:18:34 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	add_new(t_file *s_file)
{
	char	*tmp;
	char	**new_env;

	tmp = NULL;
	new_env = NULL;
	if (!(tmp = ft_strdup(s_file->comm[1])))
		return ;
	new_env = add_in_tab(s_file->env, s_file->size_env, tmp);
	free_env(s_file);
	s_file->env = new_env;
	s_file->size_env++;
	free(tmp);
}

void	unset_env(t_file *s_file)
{
	int		pos;
	char	**search;

	pos = 0;
	if (s_file->comm[1] == NULL)
		return ;
	if (!(search = ft_strsplit(s_file->comm[1], '=')))
		return ;
	if ((pos = search_env(s_file->env, s_file->size_env, search[0])) == -1)
	{
		search = free_split(search);
		return ;
	}
	s_file->env = remove_in_tab(s_file->env, s_file->size_env, pos);
	search = free_split(search);
	s_file->size_env--;
}

void	add_env(t_file *s_file, char *var, char *element)
{
	char	**new_env;
	char	*tmp;

	tmp = ft_strjoin(var, element);
	new_env = add_in_tab(s_file->env, s_file->size_env, tmp);
	free_env(s_file);
	free(tmp);
	s_file->env = new_env;
	s_file->size_env++;
}

void	do_set_env(t_file *s_file)
{
	int		find;
	char	**search;

	find = 0;
	if (s_file->comm[1] == NULL)
		return ;
	if (!(search = ft_strsplit(s_file->comm[1], '=')))
		return ;
	if (search[1] == NULL)
	{
		search = free_split(search);
		return ;
	}
	if ((find = search_env(s_file->env, s_file->size_env, search[0])) > -1)
	{
		free(s_file->env[find]);
		s_file->env[find] = ft_strdup(s_file->comm[1]);
	}
	else
		add_new(s_file);
	search = free_split(search);
}

void	put_env(char **env, int size)
{
	int i;

	i = 0;
	while (i < size)
		ft_putendl(env[i++]);
}
