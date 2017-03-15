/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:50:30 by rbotez            #+#    #+#             */
/*   Updated: 2017/01/11 15:50:26 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		size;

	if (!s)
		return (0);
	size = ft_strlen(s);
	while (s[size] != c && 0 <= size)
		size--;
	if (s[size] == (char)c)
		return ((char*)s + size);
	return (0);
}
