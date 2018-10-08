/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_find_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 09:02:46 by enikel            #+#    #+#             */
/*   Updated: 2018/10/08 15:56:11 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		ms_find_env(char *av, char ***env)
{
	int		i;
	char	*temp;

	i = 0;
	while (env[0][i])
	{
		temp = ft_strjoin(av, "=");
		if (ft_strzstr(env[0][i], temp))
		{
			free(temp);
			return (i);
		}
		i++;
		free(temp);
	}
	return (-1);
}
