/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_arg_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 09:37:21 by enikel            #+#    #+#             */
/*   Updated: 2018/09/30 12:59:16 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**ms_arg_split(char *str, int ac)
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
	if (ac <= 0)
		return (NULL);
	if (!(av = (char **)malloc(sizeof(char *) * (ac + 1))))
		ms_err(1);
	av[ac] = NULL;
	while (str[i] != '\0' && k < ac)
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