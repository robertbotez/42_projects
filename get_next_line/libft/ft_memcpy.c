/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:38:13 by abenea            #+#    #+#             */
/*   Updated: 2017/01/06 20:21:01 by abenea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *dst;
	unsigned char *sr;

	if (!dest || !src)
		return (0);
	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	while (n--)
	{
		*dst++ = *sr++;
	}
	return (dest);
}
