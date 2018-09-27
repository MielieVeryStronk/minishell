/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_arg_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 09:37:21 by enikel            #+#    #+#             */
/*   Updated: 2018/09/25 14:41:59 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**ms_arg_split(char *str)
{
	char	**av;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!str)
		return (NULL);
	if (ms_argscnt(str) == -1)
		return (NULL);
	if (!(av = (char **)malloc(sizeof(char *) * (ms_argscnt(str) + 1))))
		ms_err(1);
	av[ms_argscnt(str)] = NULL;
	while (str[i] != '\0' && k < ms_argscnt(str))
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == '"')
		{
			i++;
			j = i;
			while (str[j] != '"' && str[j] != '\0')
				j++;
			av[k++] = ft_strsub(str, i, j - i);
			i = j;
		}
		else if (str[i] != '\0')
		{
			while (str[i] == ' ' || str[i] == '\t')
				i++;
			j = i;
			while (str[j] != ' ' && str[j] != '\t' && str[j] != '\0')
				j++;
			av[k++] = ft_strsub(str, i, (j - i));
			i = j;
		}
		if (str[i] != '\0')
			i++;
	}
	return (av);
}