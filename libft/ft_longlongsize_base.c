/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlongsize_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 12:06:20 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/25 12:07:05 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_longlongsize_base(unsigned long long nbr, unsigned int base)
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
