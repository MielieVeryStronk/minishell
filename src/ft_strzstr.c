/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strzstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikel <enikel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:41:14 by enikel            #+#    #+#             */
/*   Updated: 2018/09/27 13:50:51 by enikel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_strzstr(const char *haystack, const char *needle)
{
	int		a;
	int		ph;

	a = 0;
	ph = 0;
	if (haystack == needle || !needle[a])
		return ((char *)haystack);
	if (!haystack[a])
		return (NULL);
	if (haystack[0] != needle[0])
		return (NULL);
	while (haystack[ph + a] != '\0')
	{
		if (needle[a] == haystack[ph + a])
			a++;
		if (needle[a] == '\0')
			return ((char *)&haystack[ph]);
		if (needle[a] != haystack[a + ph] && needle[a] != '\0')
		{
			ph++;
			a = 0;
		}
	}
	return (NULL);
}
