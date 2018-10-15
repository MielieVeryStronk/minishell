/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_arg_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 09:37:21 by enikel            #+#    #+#             */
/*   Updated: 2018/10/15 11:55:52 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		ft_split_quote(char *str, char **av, int i, int k)
{
	int	j;

	i++;
	j = i;
	while (str[j] != '"' && str[j] != '\0')
		j++;
	av[k++] = ft_strsub(str, i, j - i);
	return (j);
}

int		ft_split_ws(char *str, char **av, int i, int k)
{
	int j;

	while (str[i] == ' ' || str[i] == '\t')
		i++;
	j = i;
	while (str[j] != ' ' && str[j] != '\t' && str[j] != '\0')
		j++;
	av[k++] = ft_strsub(str, i, (j - i));
	return (j);
}

char	**ms_arg_split(char *str, int ac)
{
	char	**av;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!str || ac <= 0)
		return (NULL);
	if (!(av = (char **)malloc(sizeof(char *) * (ac + 1))))
		ms_err(1);
	av[ac] = NULL;
	while (str[i] != '\0' && k < ac)
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == '"')
			i = ft_split_quote(str, av, i, k++);
		else if (str[i] != '\0')
			i = ft_split_ws(str, av, i, k++);
		if (str[i] != '\0')
			i++;
	}
	return (av);
}
