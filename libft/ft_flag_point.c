/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 16:32:53 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/27 16:22:03 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_flag_point(t_str_conv *sub, char *str)
{
	size_t	i;
	int		prec;

	i = 1;
	if (str[i] == '*')
	{
		prec = va_arg(sub->ap, int);
		i++;
	}
	else
	{
		while (ft_isdigit(str[i]))
			i++;
		prec = ft_atoi(str + 1);
	}
	if (prec < 0)
		sub->prec = 0;
	else
	{
		sub->prec = prec;
		sub->point = 1;
	}
	return (i);
}
