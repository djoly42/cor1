/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_cleaner.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 14:52:14 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/29 15:18:50 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_param_cleaner(t_param **param, t_str_conv **conv)
{
	t_param	*prm;

	prm = *param;
	ft_conv_cleaner(&prm->conv);
	ft_flag_cleaner(&prm->flag);
	ft_memdel((void**)param);
	ft_str_conv_cleaner(conv);
	return (-1);
}
