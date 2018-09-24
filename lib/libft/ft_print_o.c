/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 15:15:58 by enikel            #+#    #+#             */
/*   Updated: 2018/09/05 08:43:53 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_o(unsigned int o)
{
	char	*str;
	int		len;

	str = ft_itoa_base(o, 8);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
