/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_sub_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 09:20:41 by enikel            #+#    #+#             */
/*   Updated: 2018/09/25 13:37:41 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ms_sub_var(char ***av, char ***env)
{
	int		i;
	int		j;
	int		found;

	i = 0;
	found = 0;
	while (av[0][i])
	{
		if (av[0][i][0] != '$')
			found = 1;
		j = 0;
		while (env[0][j])
		{
			if (av[0][i][0] == '$' && ft_strstr(env[0][j], &av[0][i][1]))
			{
				free(av[0][i]);
				av[0][i] = env[0][j];
				/*av[0][i] = ft_strdup(ft_strchr(env[0][j], '/'));*/
				found = 1;
			}
			j++;
		}
		if (found == 0)
		{
			ft_printf("minishell: variable not found: %s", av[0][i]);
			ft_strdel(&av[0][i]);
		}
		found = 0;
		i++;
	}
}