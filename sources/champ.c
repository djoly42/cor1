/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 09:50:09 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/09 16:39:35 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_print_champ(t_champ *chp)
{
	if (!chp->fd_out)
	{
		if ((chp->fd_out = open(chp->file_n, O_RDWR | O_CREAT | O_TRUNC,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
			ft_error(ft_strjoin("error while opening file ", chp->file_n));
	}
	ft_print_magic(chp);
	ft_print_name(chp);
	ft_print_bin_size(chp);
	ft_print_comment(chp);
	ft_print_bin(chp);
	if (chp->fd_out != 1)
		ft_putendl(ft_strjoin("Writing output program to ", chp->file_n));
	close(chp->fd_out);
}

void	ft_print_name(t_champ *chp)
{
	char	*zero;

	zero = "\0\0\0\0";
	write(chp->fd_out, &chp->name, PROG_NAME_LENGTH);
	write(chp->fd_out, zero, 4);
}

void	ft_print_magic(t_champ *c)
{
	char	magic[4];

	magic[0] = COREWAR_EXEC_MAGIC / 256 / 256 / 256 % 256;
	magic[1] = COREWAR_EXEC_MAGIC / 256 / 256 % 256;
	magic[2] = COREWAR_EXEC_MAGIC / 256 % 256;
	magic[3] = COREWAR_EXEC_MAGIC % 256;
	write(c->fd_out, magic, sizeof(COREWAR_EXEC_MAGIC));
}

void	ft_print_comment(t_champ *chp)
{
	char	*zero;

	zero = "\0\0\0\0";
	write(chp->fd_out, &chp->comment, COMMENT_LENGTH);
	write(chp->fd_out, zero, 4);
}

void	ft_print_bin_size(t_champ *chp)
{
	char	nbr[4];

	nbr[0] = chp->pos / 256 / 256 / 256;
	nbr[1] = chp->pos / 256 / 256 % 256;
	nbr[2] = chp->pos / 256 % 256;
	nbr[3] = chp->pos % 256;
	write(chp->fd_out, nbr, 4);
}
