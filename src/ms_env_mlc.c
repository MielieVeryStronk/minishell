/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_mlc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 08:53:08 by enikel            #+#    #+#             */
/*   Updated: 2018/09/26 13:39:04 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**ms_env_mlc(char **old)
{
	int		i;
	char	**new;

	i = 0;
	new = (char**)malloc((sizeof(char *) * ms_env_size(old)) + 1);
	new[ms_env_size(old)] = NULL;
	while (old[i])
	{
		new[i] = ft_strdup(old[i]);
		i++;
	}
	return (new);
}