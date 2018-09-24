/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:26:55 by enikel            #+#    #+#             */
/*   Updated: 2018/08/24 13:14:22 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long long int n)
{
	long long int num;

	num = (long long int)n;
	if (num < 0)
	{
		num = num * -1;
		ft_putchar('-');
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar((num % 10) + 48);
}
