/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 10:07:20 by enikel            #+#    #+#             */
/*   Updated: 2018/09/27 12:22:17 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ms_err(int	err)
{
	ft_printcolour("red");
	ft_printf("minishell: ");
	if (err == 1)
		{
			ft_printf("malloc error\n");
			exit (0);
		}
	else if (err == 2)
		ft_printf("incorrect number of arguments\n");
	else if (err == 3)
		ft_printf("incorrect usage of quote\n");
	else if (err == 4)
		ft_printf("env variable not found\n");
	else if (err == 5)
		ft_printf("env variable cannot contain '='\n");
	else if (err == 6)
		ft_printf("multiple arguments not supported for cd\n");
	else if (err == 7)
		ft_printf("invalid path\n");
	ft_printcolour("cyan");
}