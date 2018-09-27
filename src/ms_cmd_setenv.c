/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_setenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:25:17 by enikel            #+#    #+#             */
/*   Updated: 2018/09/26 16:04:04 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		ms_find_env(char *av, char ***env)
{
	int		i;

	i = 0;
	while (env[0][i])
	{
		if (ft_strstr(env[0][i], av))
			return (i);
		i++;
	}
	return (-1);
}

void	ms_cmd_setenv(char ***av, int ac, char ***env)
{
	int		line;

	if (ac == 1)
		ms_cmd_env(env);
	else if (ac != 3)
		ms_err(2);
	else
	{
		line = ms_find_env(av[0][1], env);
		if (line >= 0)
			env[0][line] = ft_strjoin_mult(3, av[0][1], "=", av[0][2]);
		else
			*env = ms_new_env(*av, *env);
	}
}