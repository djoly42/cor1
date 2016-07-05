/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_picker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 13:39:06 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/27 17:44:27 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_width_picker(t_str_conv *sub, char *str)
{
	size_t i;

	i = 0;
	sub->width = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		sub->width = sub->width * 10 + (str[i] - '0');
		i++;
	}
	return (i);
}
