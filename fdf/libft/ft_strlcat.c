/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:56:03 by rbotez            #+#    #+#             */
/*   Updated: 2017/01/11 15:50:14 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	i;
	size_t	len;

	dlen = ft_strlen(dest);
	len = dlen;
	i = 0;
	if (size < len)
		return (size + ft_strlen(src));
	if (size == len)
		return (ft_strlen(src) + len);
	else
	{
		while (src[i] != '\0' && size > len + i + 1)
		{
			dest[dlen] = src[i];
			dlen++;
			i++;
		}
		dest[dlen] = '\0';
	}
	return (len + ft_strlen(src));
}
