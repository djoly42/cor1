/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 12:37:24 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/18 11:19:41 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_live(t_vm *vm, t_process *proc)
{
	t_list_player	*plr;
	int				tmp;
	int				arg[3];

	arg[0] = proc->ir.args[0];
	plr = vm->bplr.lst_plyr;
	while (plr && plr->plr->num_plyr != proc->ir.args[0])
		plr = plr->next;
	if (plr)
	{
		plr->plr->last_live = vm->cpu.cur_cycle;
		proc->lst_live = vm->cpu.cur_cycle;
		if (vm->verbose & 1)
		{
			if (proc->ir.args[0] < 0)
				tmp = (-1 * proc->ir.args[0]);
				else
				tmp = proc->ir.args[0];
			ft_printf("Player %d (%s) is said to be alive\n", tmp, plr->plr->prog_name);
		}
		plr->plr->last_live = vm->cpu.cur_cycle;
	}
	vm->nbr_live++;
	proc->live++;
	if (vm->verbose & 4)
		ft_print_operations(proc, arg);
}
