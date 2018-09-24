/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 10:07:20 by enikel            #+#    #+#             */
/*   Updated: 2018/09/24 13:09:06 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ms_err(int	err)
{
	if (err == 1)
		{
			ft_printf("malloc error\n");
			exit (0);
		}
	else if (err == 3)
		ft_printf("incorrect usage of quote\n");
}