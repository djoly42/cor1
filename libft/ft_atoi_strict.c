/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_strict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:30:05 by tmanet            #+#    #+#             */
/*   Updated: 2016/02/19 10:31:03 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_strict(const char *str)
{
	int		i;
	long	nbr;
	int		neg;

	i = 0;
	nbr = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + (str[i] - '0');
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_error("invalid input in atoi_strict");
		i++;
	}
	if (str[i])
		ft_error("invalid input in atoi_strict");
	return ((int)nbr * neg);
}
