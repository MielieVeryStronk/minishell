/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_unsetenv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 09:01:23 by enikel            #+#    #+#             */
/*   Updated: 2018/09/27 09:38:26 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ms_cmd_unsetenv(char ***av, int ac, char ***env)
{
	int		line;
	int		i;

	if (ac != 2)
		ms_err(2);
	else if (ft_strchr(av[0][1], '='))
		ms_err(5);
	else
	{
		line = ms_find_env(av[0][1], env);
		if (line >= 0)
		{
			ft_printf("hello\n");
			free(env[0][line]);
			i = line + 1;
			while (env[0][i])
			{
				env[0][i - 1] = env[0][i];
				i++;
			}
			env[0][i - 1] = NULL;
		}
	}
}