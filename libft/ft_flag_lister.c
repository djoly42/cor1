/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_lister.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 15:40:51 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/27 18:14:41 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*ft_flag_lister(void)
{
	t_flag	*flag;
	int		grp;

	grp = 0;
	flag = NULL;
	if ((flag = ft_newflag(flag, "l", &ft_flag_l)))
		if ((flag = ft_newflag(flag, "ll", &ft_flag_ll)))
			if ((flag = ft_newflag(flag, "j", &ft_flag_j)))
				if ((flag = ft_newflag(flag, "t", NULL)))
					if ((flag = ft_newflag(flag, "z", &ft_flag_z)))
						if ((flag = ft_newflag(flag, "h", &ft_flag_h)))
							if ((flag = ft_newflag(flag, "hh", &ft_flag_hh)))
								grp = 1;
	if (grp == 1 && (flag = ft_newflag(flag, "*", &ft_flag_star)))
		if ((flag = ft_newflag(flag, "#", &ft_flag_hash)))
			if ((flag = ft_newflag(flag, "-", &ft_flag_minus)))
				if ((flag = ft_newflag(flag, "+", &ft_flag_plus)))
					if ((flag = ft_newflag(flag, "0", &ft_flag_zero)))
						if ((flag = ft_newflag(flag, ".", &ft_flag_point)))
							if ((flag = ft_newflag(flag, " ", &ft_flag_space)))
								return (flag);
	return (NULL);
}
