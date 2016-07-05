/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 16:35:10 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/18 12:04:41 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	core_zero(t_vm *vm)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		vm->core[i] = 0;//i;//0xff;
		vm->data[i].num_plr = 0; // ou -1 si un player est le numero 0
		vm->data[i].pc = 0;
		i++;
	}
}

int			ftab_init(t_vm *vm)
{
	vm->ftab[1] = &ft_live;
	vm->ftab[2] = &ft_ld;
	vm->ftab[3] = &ft_st;
	vm->ftab[4] = &ft_add;
	vm->ftab[5] = &ft_sub;
	vm->ftab[6] = &ft_and;
	vm->ftab[7] = &ft_or;
	vm->ftab[8] = &ft_xor;
	vm->ftab[9] = &ft_zjmp;
	vm->ftab[10] = &ft_ldi;
	vm->ftab[11] = &ft_sti;
	vm->ftab[12] = &ft_fork;
	vm->ftab[13] = &ft_lld;
	vm->ftab[14] = &ft_lldi;
	vm->ftab[15] = &ft_lfork;
	vm->ftab[16] = &ft_aff;
	return (0);
}
void		cpu_init(t_vm *vm)
{
	vm->cpu.cycle2die = CYCLE_TO_DIE;
	vm->cpu.cur_cycle = 0;
	vm->cpu.cycle_to_check = CYCLE_TO_DIE;
	vm->cpu.nbchecks = 0;


}

void		vm_init(t_vm *vm)
{

	cpu_init(vm);
	vm->dump = -1;
	vm->step = 0;
	vm->aff = 0;
	vm->color = 0;
	vm->verbose = 0;
	vm->nb_proc = 1;
	vm->bplr.lst_plyr = NULL;
	vm->bplr.i_plr = 0;
	vm->bplr.tab[0] = -1;
	vm->bplr.tab[1] = -2;
	vm->bplr.tab[2] = -3;
	vm->bplr.tab[3] = -4;
	vm->proc = NULL;
	// cpu_init(vm->cpu);
	ftab_init(vm);
	core_zero(vm);
	// core_posplyer(vm);
}

int		ft_init_proc(t_bin	*plr, t_process *proc)
{
	int i;

	i = 0;
	proc->ir.ocp = 0;
	proc->ir.nb_arg = 0;
	while (i < 3)
	{
		proc->ir.code_args[i] = 0;
		proc->ir.types_args[i] = 0;
		proc->ir.args[i] = 0;
		i++;
	}
	proc->cycle_to_wait = -1;
	proc->num_plr = plr->num_plyr;
	proc->pc = plr->pc_tmp;
	proc->pcdelta = 0;
	proc->reg[1] = proc->num_plr;
	proc->carry = 0;
	return(0);
}
