/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 11:17:21 by tmanet            #+#    #+#             */
/*   Updated: 2016/02/02 15:43:01 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_atoui_base(char *str)
{
	unsigned int	nbr;
	int				i;
	int				base;
	char			ltr;

	i = 0;
	if (ft_strequ("0x", str))
	{
		base = 16;
		ltr = str[1] - ('x' - 'a');
	}
	else if (str[0] == '0' && str[1] != 0)
		base = 8;
	else
		base = 10;
	while (str[i] && ((ft_isdigit(str[i]) && (str[i] < 8 || base > 8)) ||
				(base == 16 && (str[i] >= ltr && str[i] < ltr + 7))))
	{
		if (ft_isdigit(str[i]))
			nbr = nbr * base + (str[i] - '0');
		else
			nbr = nbr * base + (str[i] - ltr + 10);
		i++;
	}
	return (nbr);
}
