/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_new_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:57:43 by enikel            #+#    #+#             */
/*   Updated: 2018/10/08 15:54:24 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**ms_new_env(char **av, char **old)
{
	int		i;
	int		size;
	char	**new;

	i = 0;
	size = ms_env_size(old);
	new = (char**)malloc((sizeof(char *) * (size + 2)));
	new[size + 1] = NULL;
	while (old[i])
	{
		new[i] = ft_strdup(old[i]);
		i++;
	}
	new[i] = ft_strjoin_mult(3, av[1], "=", av[2]);
	return (new);
}
