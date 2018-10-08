/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 10:02:25 by enikel            #+#    #+#             */
/*   Updated: 2018/10/08 15:58:10 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ms_cmd_pwd(int ac)
{
	char	*buff;

	buff = ft_strnew(PATH_MAX);
	if (ac == 1)
	{
		getcwd(buff, PATH_MAX);
		ft_printf("%s\n", buff);
	}
	else
		ms_err(2);
	if (buff)
		free(buff);
}
