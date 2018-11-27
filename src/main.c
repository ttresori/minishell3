/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <rammsteinluffy@gmail.co...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 22:56:08 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/27 04:40:36 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	core(char **env)
{
	char	*line;
	char	buf[255];
	t_file	*s_file;

	if (!(s_file = (t_file*)malloc(sizeof(t_file))))
		return ;
	if (!(s_file->pwd = ft_strdup(getcwd(buf, 255))))
		return ;
	s_file->size_comm = 0;
	s_file->comm = NULL;
	cpy_env(s_file, env);
	while (42)
	{
		print_prompt();
		get_next_line(0, &line);
		if (!(s_file = split_line(s_file, line)))
			return ;
		ft_strdel(&line);
		get_next_line(-2, NULL);
		check_builtin(s_file);
		free_line(s_file);
	}
}

int		main(int argc, char **argv, char **env)
{
	if (env[0] == NULL)
	{
		ft_putendl_fd("No env", 2);
		return (0);
	}
	core(env);
	(void)argc;
	(void)argv;
	return (0);
}
