/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_mlc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 08:53:08 by enikel            #+#    #+#             */
/*   Updated: 2018/10/08 15:58:01 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**ms_env_mlc(char **old)
{
	int		i;
	char	**new;

	i = 0;
	new = malloc((sizeof(char *) * (ms_env_size(old) + 1)));
	new[ms_env_size(old)] = NULL;
	while (old[i])
	{
		new[i] = ft_strdup(old[i]);
		i++;
	}
	return (new);
}
