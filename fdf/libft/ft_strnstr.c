/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:48:24 by rbotez            #+#    #+#             */
/*   Updated: 2017/01/11 15:50:41 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *mare, const char *mic, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	nmic;

	i = 0;
	j = 0;
	nmic = ft_strlen(mic);
	if (nmic == 0)
		return ((char *)mare);
	while (mare[i] && i < len)
	{
		while (mare[i + j] == mic[j] && ((i + j) < len && mare[i + j]))
		{
			if (j == nmic - 1)
				return ((char *)mare + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
