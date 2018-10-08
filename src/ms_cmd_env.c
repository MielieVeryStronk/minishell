/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 08:38:22 by enikel            #+#    #+#             */
/*   Updated: 2018/10/08 15:58:12 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ms_cmd_env(char ***env)
{
	int		i;

	i = 0;
	while (env[0][i])
	{
		ft_printf("%s\n", env[0][i]);
		i++;
	}
}
