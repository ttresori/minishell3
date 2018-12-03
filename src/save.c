/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <rammsteinluffy@gmail.co...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 23:03:02 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/03 16:36:29 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	put_path(t_file *s_file)
{
	while (*s_file->path != NULL)
		ft_putendl(*s_file->path++);
}

void	cpy_env(t_file *s_file, char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
		i++;
	s_file->size_env = i;
	if (!(s_file->env = (char**)malloc(sizeof(char*) * (i + 1))))
		return ;
	i = 0;
	while (i < s_file->size_env)
	{
		if (!(s_file->env[i] = ft_strdup(env[i])))
			return ;
		i++;
	}
	s_file->env[i] = NULL;
	get_path(s_file);
}

int		help_check_dollar(t_file *s_file, int i)
{
	int				pos;
	char			**tmp;
	char			**tmp2;

	pos = -1;
	if (!(tmp = ft_strsplit(s_file->comm[i], '$')))
		return (-1);
	pos = search_env(s_file->env, s_file->size_env, tmp[0]);
	if (pos == -1)
	{
		free_split(tmp);
		i++;
		check_if_dollar(s_file);
	}
	if (!(tmp2 = ft_strsplit(s_file->env[pos], '=')))
		return (-1);
	free(s_file->comm[i]);
	if (!(s_file->comm[i] = ft_strdup(tmp2[1])))
		return (-1);
	free_split(tmp);
	free_split(tmp2);
	return (i);
}

void	check_if_dollar(t_file *s_file)
{
	static	int	i = 0;

	while (i < s_file->size_comm)
	{
		if (s_file->comm[i][0] == '$' && s_file->comm[i][1] != '$')
			i = help_check_dollar(s_file, i);
		if (s_file->comm[i][0] == '~' && s_file->comm[i][1] == '\0')
		{
			free(s_file->comm[i]);
			s_file->comm[i] = get_home(s_file);
		}
		i++;
	}
	i = 0;
	return ;
}

t_file	*split_line(t_file *s_file, char *line)
{
	s_file->size_comm = 0;
	s_file->comm = ft_strsplit_set(line, " \t\r\f");
	while (s_file->comm[s_file->size_comm] != NULL)
		s_file->size_comm++;
	check_if_dollar(s_file);
	if (s_file->path != NULL)
		free_split(s_file->path);
	get_path(s_file);
	return (s_file);
}
