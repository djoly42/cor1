/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_champ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:21:09 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/17 14:49:00 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_check_champ(t_champ *chp)
{
	if (!chp->name[0])
		ft_error(ft_strjoin("missing champ name in file ", chp->file_n));
	if (!chp->com)
		ft_error(ft_strjoin("missing comment in file ", chp->file_n));
	if (!chp->bin[0])
		ft_error(ft_strjoin("missing instructions in file ", chp->file_n));
}

void	ft_write_bin(t_champ *c, int pos, char ocp)
{
	if (c->pos <= CHAMP_MAX_SIZE)
	{
		c->bin[pos] = ocp;
		c->pos++;
	}
	else
		ft_error("The champion is too big. Size must not exceed 682 bytes.");
}

int		check_flags(t_champ *c, char **argv)
{
	if (ft_strcmp(argv[1], "-a") == 0)
	{
		c->fd_out = 1;
		return (1);
	}
	else
		return (0);
}
