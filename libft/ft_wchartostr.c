/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchartostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:43:02 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/29 15:50:07 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_wchartostr(wchar_t wide)
{
	size_t	size;
	char	*ret;

	if (!(size = ft_wide_size((unsigned int)wide)))
		ret = ft_memalloc(1);
	else if (size < 8)
		ret = ft_memset(ft_strnew(1), wide, 1);
	else if (size < 12 && (ret = ft_memset(ft_strnew(2), wide / 64 + 192, 1)))
		ft_memset(ret + 1, wide % 64 + 128, 1);
	else if (size < 17)
	{
		ret = ft_memset(ft_strnew(3), wide / 4096 + 224, 1);
		ft_memset(ret + 1, wide % 4096 / 64 + 128, 1);
		ft_memset(ret + 2, wide % 64 + 128, 1);
	}
	else if (size < 22)
	{
		ret = ft_memset(ft_strnew(4), wide / 131072 + 224, 1);
		ft_memset(ret + 1, wide % 131072 / 4096 + 128, 1);
		ft_memset(ret + 2, wide % 4096 / 64 + 128, 1);
		ft_memset(ret + 3, wide % 64 + 128, 1);
	}
	else
		ret = NULL;
	return (ret);
}
