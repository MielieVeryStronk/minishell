/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:30:44 by enikel            #+#    #+#             */
/*   Updated: 2018/09/27 09:14:30 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
	else if (!ft_strcmp(av[0], "./minishell"))
	{
		ft_putchar('\n');
	}
	else
		ft_printf("minishell: command not found: %s\n", av[0]);
}