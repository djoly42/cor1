/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 17:27:16 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/21 19:01:14 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ultoa_base(unsigned long nbr, unsigned int base, char c)
{
	size_t			size;
	char			*ptr;

	size = ft_longsize_base(nbr, base);
	ptr = ft_strnew(size);
	if (!ptr)
		return (NULL);
	ft_ultoaa_base(nbr, ptr, base, c);
	return (ptr);
}
