/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_cleaner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 15:06:59 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/29 15:13:29 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_cleaner(t_flag **flag)
{
	t_flag	*flg;

	if (flag)
	{
		flg = *flag;
		if (flg)
		{
			if (flg->next)
				ft_flag_cleaner(&flg->next);
			ft_memdel((void**)flag);
		}
	}
}
