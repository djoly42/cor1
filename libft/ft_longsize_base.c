/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longsize_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 17:27:05 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/20 17:27:07 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_longsize_base(unsigned long nbr, unsigned int base)
{
	size_t	i;

	i = 1;
	while (nbr >= base)
	{
		nbr = nbr / base;
		i++;
	}
	return (i);
}
