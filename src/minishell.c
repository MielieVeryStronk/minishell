/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:17:29 by enikel            #+#    #+#             */
/*   Updated: 2018/09/24 14:42:46 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ms_header()
{	
	ft_printcolour("black");
	ft_printf("********************************************\n");
	ft_printcolour("cyan");
	ft_printf("*            _       _     _          _ _  *\n");
	ft_printcolour("red");
	ft_printf("*  _ __ ___ (_)_ __ (_)___| |__   ___| | | *\n");
	ft_printcolour("cyan");
	ft_printf("* | '_ ` _ \\| | '_ \\| / __| '_ \\ / _ \\ | | *\n");
	ft_printcolour("red");
	ft_printf("* | | | | | | | | | | \\__ \\ | | |  __/ | | *\n");
	ft_printcolour("cyan");
	ft_printf("* |_| |_| |_|_|_| |_|_|___/_| |_|\\___|_|_| *\n");
	ft_printcolour("red");
	ft_printf("*                                          *\n");
	ft_printcolour("cyan");
	ft_printf("* by:  enikel                       v1.0.0 *\n");
	ft_printcolour("black");
	ft_printf("********************************************\n\n");
	ft_printcolour("black");
	ft_printf("\n");
}

int		main(int argc, char **argv, char **env)
{
	(void)(argc && argv);
	ms_header();
	while (1)
	{
		ms_printprompt();
		ms_get_av(env);
	}
	return (0);
}