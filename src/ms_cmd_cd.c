/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 09:46:10 by enikel            #+#    #+#             */
/*   Updated: 2018/09/28 09:05:13 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ms_cd_dash(char *av, char ***env)
{
	char	*path;
	int		line;

	path = ft_strnew(PATH_MAX);
	if (!ft_strcmp(av, "-"))
	{
		line = ms_find_env("OLDPWD", env);
		if (line >= 0)
			path = ft_strdup(ft_strchr(env[0][line], '/'));
		ft_printf("%s\n", path);
	}
	else if (!ft_strcmp(av, "~"))
	{
		line = ms_find_env("HOME", env);
		if (line >= 0)
		path = ft_strdup(ft_strchr(env[0][line], '/'));
	}
	return (path);
}

void	ms_cmd_cd(char **av, int ac, char ***env)
{
	char	*path;
	char	*buff;
	char	*temp;

	buff = ft_strnew(PATH_MAX);
	getcwd(buff, PATH_MAX);
	if (av[1])
		path = ft_strdup(av[1]);
	if (ac == 1 || !ft_strcmp(av[1], "-") || !ft_strcmp(av[1], "~"))
	{
		if (ac == 1)
			temp = ft_strdup("~");
		else
			temp = ft_strdup(av[1]);
		path = ms_cd_dash(temp, env);
		free(temp);
	}
	if (ac > 2)
		ms_err(2);
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