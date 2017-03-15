/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:00:04 by abenea            #+#    #+#             */
/*   Updated: 2017/01/06 18:00:06 by abenea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	size;
	long	nbr;

	size = 1;
	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	while (nbr / size >= 10)
		size = size * 10;
	while (size > 0)
	{
		ft_putchar(nbr / size + '0');
		nbr %= size;
		size /= 10;
	}
}
