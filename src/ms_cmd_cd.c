/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 09:46:10 by enikel            #+#    #+#             */
/*   Updated: 2018/09/27 14:08:42 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ms_cmd_cd(char **av, int ac, char ***env)
{
	char	*path;
	char	*buff;

	buff = ft_strnew(PATH_MAX);
	getcwd(buff, PATH_MAX);
	path = ft_strdup(av[1]);
	if (ac < 2)
		ms_err(2);
	else if (ac > 2)
		ms_err(6);
	else if (chdir(path) == 0)
	{
		av[1] = ft_strdup("OLDPWD");
		av[2] = buff;
		ms_cmd_setenv(&av, 3, env);
		getcwd(buff, PATH_MAX);
		av[1] = ft_strdup("PWD");
		av[2] = buff;
		ms_cmd_setenv(&av, 3, env);
	}
	else
		ms_err(7);
	if (buff)
		free(buff);
}