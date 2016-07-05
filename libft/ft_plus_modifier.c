/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_modifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 11:04:42 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/29 15:57:20 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_plus_modifier(t_str_conv *sub)
{
	char	*str;

	str = sub->str_out;
	if (!ft_strchr(str, '-'))
	{
		sub->str_out = ft_strjoin_clean(ft_strdup("+"), str);
		sub->size++;
	}
}
