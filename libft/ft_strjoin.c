/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 18:01:06 by rbotez            #+#    #+#             */
/*   Updated: 2017/01/07 18:40:31 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;

	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
						+ 1))))
		return (0);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	str[ft_strlen(str)] = '\0';
	return (str);
}
