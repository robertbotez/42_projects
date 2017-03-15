/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:44:22 by rbotez            #+#    #+#             */
/*   Updated: 2017/01/11 15:50:33 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;
	int	nlen;

	i = 0;
	j = 0;
	nlen = ft_strlen(little);
	if (nlen == 0)
		return ((char *)big);
	while (big[i])
	{
		while (big[i + j] == little[j])
		{
			if (j == nlen - 1)
				return ((char *)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
