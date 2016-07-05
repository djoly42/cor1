/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_picker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 13:20:28 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/26 13:34:00 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_precision_picker(t_str_conv *sub, char *str)
{
	size_t i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		sub->prec = sub->prec * 10 + (str[i] - '0');
		i++;
	}
	return (i);
}
