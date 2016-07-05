/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlongrange_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 12:10:10 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/25 12:13:48 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_longlongrange_base(
		unsigned long long nbr, unsigned int base)
{
	unsigned long long range;

	range = 1;
	while (nbr >= (unsigned long long)base)
	{
		range = range * (unsigned long long)base;
		nbr = nbr / (unsigned long long)base;
	}
	return (range);
}
