/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 12:04:43 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/25 12:18:13 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ulltoa_base(unsigned long long nbr, unsigned int base, char c)
{
	size_t			size;
	char			*ptr;

	size = ft_longlongsize_base(nbr, base);
	ptr = ft_strnew(size);
	if (!ptr)
		return (NULL);
	ft_ulltoaa_base(nbr, ptr, base, c);
	return (ptr);
}
