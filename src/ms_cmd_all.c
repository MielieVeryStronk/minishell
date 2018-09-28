/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:30:44 by enikel            #+#    #+#             */
/*   Updated: 2018/09/28 11:51:10 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_cmd_sys(char **av, int ac, char ***env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		int		line;
		char	**path;

		if (ac == 1)
			av[1] = ft_strdup(".");
		line = ms_find_env("PATH=", env);
		path = ft_strsplit(ft_strchr(env[0][line], '/'), ':');
		line = 0;
		ft_putchar('\n');
		while (path[line])
		{
			if (!access(path[line], F_OK))
			{
				execve(ft_strjoin_mult(3, path[line], "/", av[0]), av, *env);
			}
			line++;
		}
		kill(pid, SIGKILL);
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
		ft_cmd_sys(av, ac, env);
}