/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_av.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:47:18 by enikel            #+#    #+#             */
/*   Updated: 2018/09/24 14:43:52 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ms_get_av(char **env)
{
	char	**av;
	char	*line;

	get_next_line(1, &line);
	if (ft_strlen(line) == 0)
		ft_printf("");
	else
	{
		av = ms_arg_split(line);
		free(line);
		if (av != NULL)
			ms_cmd_all(av, env);
	}
}