/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_no.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:40:36 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/28 12:06:44 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_conv_no(t_str_conv *sub, char *str)
{
	size_t	i;

	i = 0;
	if (str[i])
	{
		sub->str_out = ft_strncpy(ft_strnew(1), str + i, 1);
		sub->size = 1;
		if (sub->width > sub->size)
			ft_width_modifier(sub);
	}
	else
	{
		sub->str_out = ft_strdup("%");
		sub->size = 0;
	}
	return (str[i] != 0);
}
