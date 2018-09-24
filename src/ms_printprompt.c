/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_printprompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:22:50 by enikel            #+#    #+#             */
/*   Updated: 2018/09/21 11:27:46 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ms_printprompt()
{
	ft_printcolour("red");
	ft_printf("-");
	ft_printcolour("cyan");
	ft_printf("-");
	ft_printcolour("white");
	ft_printf(">  ");
	ft_printcolour("cyan");
}