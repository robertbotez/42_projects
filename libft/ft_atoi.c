/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbotez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 18:36:49 by rbotez            #+#    #+#             */
/*   Updated: 2017/01/07 18:47:34 by rbotez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isclean(int c)
{
	return (c == ' ' || c == '\r' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f');
}

int				ft_atoi(const char *nptr)
{
	int			i;
	int			k;
	int			sign;

	i = 0;
	k = 0;
	sign = 1;
	if (!nptr)
		return (0);
	while (ft_isclean(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		k = k * 10 + (nptr[i] - '0');
		i++;
	}
	return (k * sign);
}
