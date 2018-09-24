/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_arg_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 09:37:21 by enikel            #+#    #+#             */
/*   Updated: 2018/09/24 14:06:21 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	ft_wrdcnt(const char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"' && str[i] != '\0')
				i++;
			if (str[i] != '"')
			{
				ms_err(3);
				return (-1);
			}
			else
				num++;
		}
		else if (str[i] != ' ' && str[i] != '\t' && (str[i + 1] == ' ' ||
		str[i + 1] == '\t' || str[i + 1] == '\0'))
			num++;
		i++;
	}
	return (num);
}

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
	if (ft_wrdcnt(str) == -1)
		return (NULL);
	if (!(av = (char **)malloc(sizeof(char *) * (ft_wrdcnt(str) + 1))))
		ms_err(1);
	av[ft_wrdcnt(str)] = NULL;
	while (str[i] != '\0' && k < ft_wrdcnt(str))
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