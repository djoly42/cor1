/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_to_conv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:47:38 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/27 18:04:24 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str_conv	*ft_strsplit_to_conv(char *str, t_param *param, va_list ap)
{
	t_str_conv	*elem;
	size_t		i;

	elem = NULL;
	i = 0;
	if (str[i])
	{
		elem = (t_str_conv*)ft_memalloc(sizeof(t_str_conv));
		if (!elem)
			return (elem);
		va_copy(elem->ap, ap);
		if (str[0] == '%')
			i = ft_conv_picker(str + i + 1, &elem, param) + 1;
		else
			i = ft_str_picker(str + i, &elem);
		if (!i)
			return (NULL);
		elem->next = ft_strsplit_to_conv(str + i, param, elem->ap);
	}
	return (elem);
}
