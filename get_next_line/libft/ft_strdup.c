/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:52:39 by abenea            #+#    #+#             */
/*   Updated: 2017/01/23 22:19:48 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dup;

	if (!s)
		return (0);
	len = ft_strlen(s);
	dup = (char*)malloc(sizeof(*dup) * (len + 1));
	if (!dup)
		return (0);
	ft_strcpy(dup, s);
	return (dup);
	free(dup);
}
