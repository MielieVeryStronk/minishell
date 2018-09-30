/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:30:44 by enikel            #+#    #+#             */
/*   Updated: 2018/09/30 12:33:02 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_cmd_sys(char ***av, char ***env)
{
	pid_t	pid;
	int		err;

	pid = fork();
	err = 1;
	if (pid < 0)
		ms_err(9);
	if (pid != 0)
	{
		wait(NULL);
	}
	else if (pid == 0)
	{
		int		line;
		char	**path;

		line = ms_find_env("PATH=", env);
		path = ft_strsplit(ft_strchr(env[0][line], '/'), ':');
		line = 0;
		if (!access(av[0][0], F_OK))
		{
			if (!execve(av[0][0], av[0], *env))
				err = 0;
		}
		else while (path[line])
		{
			if (!access(path[line], F_OK))
			{
				if (!execve(ft_strjoin_mult(3, path[line], "/", av[0][0]), av[0], *env))
					err = 0;
			}
			line++;
		}
		if (err != 0)
			ms_err(8);
		exit(0);
	}
}

void	ms_cmd_all(char **av, int ac, char ***env)
{
	if (!ft_strcmp(av[0], "quit") || !ft_strcmp(av[0], "q")||
	!ft_strcmp(av[0], "exit"))
		exit(0);
	else if (!ft_strcmp(av[0], "echo"))
		ms_cmd_echo(av);
	else if (!ft_strcmp(av[0], "env"))
		ms_cmd_env(env);
	else if (!ft_strcmp(av[0], "setenv"))
		ms_cmd_setenv(&av, ac, env);
	else if (!ft_strcmp(av[0], "unsetenv"))
		ms_cmd_unsetenv(&av, ac, env);
	else if (!ft_strcmp(av[0], "cd"))
		ms_cmd_cd(av, ac, env);
	else if (!ft_strcmp(av[0], "pwd"))
		ms_cmd_pwd(ac);
	/*else if (!ft_strcmp(av[0], "./minishell"))
		ft_putchar('\n');*/
	else
		ft_cmd_sys(&av, env);
}