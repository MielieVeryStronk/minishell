/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_mult.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:31:52 by enikel            #+#    #+#             */
/*   Updated: 2018/09/26 15:56:07 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_strjoin_mult(int ac, ...)
{
	char	*str;
	char	*temp;
	va_list valist;

	str = ft_strnew(0);
	va_start(valist, ac);
	while (ac > 0)
	{
		temp = str;
		str = ft_strjoin(str, va_arg(valist, char *));
		if (temp)
			free(temp);
		ac--;
	}
	va_end(valist);
	return (str);
}
