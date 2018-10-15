/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_av.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:47:18 by enikel            #+#    #+#             */
/*   Updated: 2018/10/15 15:33:05 by enikel           ###   ########.fr       */
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
		if (ac == -1)
			ms_err(3);
		av = ms_arg_split(line, ac);
		if (av != NULL)
		{
			ms_sub_var(&av, env);
			ms_cmd_all(av, ac, env);
		}
	}
	free(line);
	return (av);
}
