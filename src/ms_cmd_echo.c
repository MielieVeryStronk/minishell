/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:38:15 by enikel            #+#    #+#             */
/*   Updated: 2018/10/08 15:58:16 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ms_cmd_echo(char **av)
{
	int		i;
	char	*ptr;

	i = 1;
	if (!av[i])
		ft_printf("\n");
	while (av[i])
	{
		if (ft_strchr(av[i], '='))
		{
			ptr = ft_strchr(av[i], '=');
			ptr++;
			ft_putstr(ptr);
		}
		else
			ft_putstr(av[i]);
		i++;
		if (av[i])
			ft_putchar(' ');
	}
	if (av[i - 1][ft_strlen(av[i - 1]) - 1] != '\n')
		ft_printf("\n");
}
