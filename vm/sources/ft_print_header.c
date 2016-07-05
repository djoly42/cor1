/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 08:57:19 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/18 10:37:16 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_print_header(t_vm *vm)
{
	t_list_player	*elem;

	elem = vm->bplr.lst_plyr;
	ft_printf("Introducing contestants...\n");
	while (elem)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				-1 * elem->plr->num_plyr, elem->plr->size, elem->plr->name,
				elem->plr->com);
		elem = elem->next;
	}
	if (vm->step)
	{
		print_core(vm);
		ft_wait();
	}
}
