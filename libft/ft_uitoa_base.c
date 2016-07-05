/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 10:40:43 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/25 12:43:28 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_uitoaa_base(unsigned int nbr,
		char *ptr, unsigned int base, char c)
{
	int				i;
	size_t			range;
	int				digit;

	i = 0;
	range = ft_range_base(nbr, base);
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

char		*ft_uitoa_base(unsigned int nbr, unsigned int base, char c)
{
	size_t			size;
	char			*ptr;
	int				i;

	i = 0;
	size = ft_intsize_base(nbr, base);
	ptr = ft_strnew(size);
	if (!ptr)
		return (NULL);
	ft_uitoaa_base(nbr, ptr + i, base, c);
	return (ptr);
}
