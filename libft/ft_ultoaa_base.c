/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoaa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 18:58:49 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/22 12:09:01 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ultoaa_base(unsigned long nbr, char *ptr, unsigned int base, char c)
{
	int				i;
	size_t			range;
	int				digit;

	i = 0;
	range = ft_longrange_base(nbr, base);
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
