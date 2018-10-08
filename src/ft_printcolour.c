/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcolour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:06:03 by enikel            #+#    #+#             */
/*   Updated: 2018/10/08 15:58:39 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_printcolour(char *colour)
{
	if (!ft_strcmp(colour, "black"))
		ft_printf("\033[1;30m");
	else if (!ft_strcmp(colour, "red"))
		ft_printf("\033[1;31m");
	else if (!ft_strcmp(colour, "green"))
		ft_printf("\033[1;32m");
	else if (!ft_strcmp(colour, "yellow"))
		ft_printf("\033[1;33m");
	else if (!ft_strcmp(colour, "blue"))
		ft_printf("\033[1;34m");
	else if (!ft_strcmp(colour, "magenta"))
		ft_printf("\033[1;35m");
	else if (!ft_strcmp(colour, "cyan"))
		ft_printf("\033[1;36m");
	else if (!ft_strcmp(colour, "white"))
		ft_printf("\033[1;37m");
	else
		exit(0);
}
