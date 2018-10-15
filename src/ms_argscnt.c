/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_argscnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:33:07 by enikel            #+#    #+#             */
/*   Updated: 2018/10/15 08:33:21 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		ms_argscnt(const char *str)
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
				return (-1);
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
