/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_cleaner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:01:21 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/29 15:13:24 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_cleaner(t_conv **conv)
{
	t_conv	*cnv;

	if (conv)
	{
		cnv = *conv;
		if (cnv)
		{
			if (cnv->next)
				ft_conv_cleaner(&cnv->next);
			ft_memdel((void**)conv);
		}
	}
}
