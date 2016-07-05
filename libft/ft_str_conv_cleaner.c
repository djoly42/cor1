/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_conv_cleaner.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 12:14:03 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/29 14:51:11 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_conv_cleaner(t_str_conv **elem)
{
	t_str_conv	*sub;

	if (elem)
	{
		sub = *elem;
		if (sub)
		{
			if (sub->next)
				ft_str_conv_cleaner(&sub->next);
			if (sub->str_out)
				ft_strdel(&sub->str_out);
			ft_memdel((void**)elem);
		}
	}
}
