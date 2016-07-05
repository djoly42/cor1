/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_for_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 13:18:32 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/29 13:27:53 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hash_for_hex(t_str_conv *sub, char *str)
{
	if (sub->zero && (sub->size + 2 < sub->width))
	{
		sub->width = sub->width - 2;
		ft_width_modifier(sub);
	}
	if (sub->str_out[0] &&
			!(sub->str_out[0] == '0' && sub->str_out[1] == 0))
		sub->str_out = ft_strjoin_clean(ft_strdup(str), sub->str_out);
	sub->size = ft_strlen(sub->str_out);
}
