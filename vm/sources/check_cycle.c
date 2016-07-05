/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:22:45 by djoly             #+#    #+#             */
/*   Updated: 2016/05/18 11:30:51 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		check_live(t_vm *vm)
{
	t_cpu	*tmp;

	tmp = &vm->cpu;
	if (vm->nbr_live >= NBR_LIVE || tmp->nbchecks == MAX_CHECKS)
	{
		tmp->cycle2die -= CYCLE_DELTA;
		vm->nbr_live = 0;
		tmp->nbchecks = 0;
		if (vm->verbose & 2)
			ft_printf("Cycle to die is now %d\n", tmp->cycle2die);
	}
	return (0);
}

int		check_cycle(t_vm *vm)
{
	t_cpu	*tmp;

	tmp = &vm->cpu;
	if (tmp->cur_cycle == tmp->cycle_to_check)
	{
		if (to_kill_or_not_to_kill_proc(vm))
			return (1);
		tmp->nbchecks++;
		check_live(vm);
		tmp->cycle_to_check = tmp->cur_cycle + tmp->cycle2die;
	}
	if (tmp->cycle2die <= 0 || vm->dump == tmp->cur_cycle)
		return (1); // I break
	return (0);// NO break
}
