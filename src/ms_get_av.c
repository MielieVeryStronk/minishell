/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_av.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:47:18 by enikel            #+#    #+#             */
/*   Updated: 2018/09/30 14:15:23 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**ms_get_av(char ***env)
{
	char	**av;
	char	*line;
	int		ac;

	av = NULL;
	get_next_line(1, &line);
	if (ft_strlen(line) == 0)
		ft_printf("");
	else
	{
		ac = ms_argscnt(line);
		av = ms_arg_split(line, ac);
		free(line);
		if (av != NULL)
		{
			ms_sub_var(&av, env);
			ms_cmd_all(av, ac, env);
		}
	}
	return (av);
}