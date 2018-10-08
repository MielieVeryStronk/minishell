/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_setenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:25:17 by enikel            #+#    #+#             */
/*   Updated: 2018/10/08 15:58:07 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ms_cmd_setenv(char ***av, int ac, char ***env)
{
	int		line;
	char	**temp;
	char	*strtmp;

	if (ac == 1)
		ms_cmd_env(env);
	else if (ac != 3)
		ms_err(2);
	else
	{
		line = ms_find_env(av[0][1], env);
		if (line >= 0)
		{
			strtmp = env[0][line];
			env[0][line] = ft_strjoin_mult(3, av[0][1], "=", av[0][2]);
			free(strtmp);
		}
		else
		{
			temp = *env;
			*env = ms_new_env(*av, *env);
			ms_free_tab(temp);
		}
	}
}
