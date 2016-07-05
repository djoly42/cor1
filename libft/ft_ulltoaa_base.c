/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoaa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 12:08:05 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/25 12:42:50 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ulltoaa_base(unsigned long long nbr,
		char *ptr, unsigned int base, char c)
{
	int					i;
	unsigned long long	range;
	int					digit;

	i = 0;
	range = ft_longlongrange_base(nbr, base);
	while (range)
	{
		digit = nbr / range;
		if (digit < 10)
			ptr[i] = digit + '0';
		else
			ptr[i] = digit + c - 10;
		nbr = nbr % range;
		range = range / base;
		i++;
	}
}
