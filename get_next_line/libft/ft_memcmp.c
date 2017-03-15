/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:42:38 by abenea            #+#    #+#             */
/*   Updated: 2017/01/07 15:30:59 by abenea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a1;
	unsigned char	*a2;

	if (!s1 || !s2)
		return (0);
	if (n)
	{
		a1 = (unsigned char *)s1;
		a2 = (unsigned char *)s2;
		if (n == 0)
		{
			if (*a1 != *a2)
				return (*--a1 - *--a2);
		}
		while (n--)
		{
			if (*a1++ != *a2++)
				return (*--a1 - *--a2);
		}
	}
	return (0);
}
