/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 09:25:36 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/18 09:36:18 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
   ajout au debut de t_proc
   */
t_process	*ft_add_link(t_process *beg, int plr, int pc, t_process *father)
{
	t_process *tmp;

	if (!(tmp = (t_process*)ft_memalloc(sizeof(t_process))))
		ft_error("malloc error in new cell creating");
	if (tmp)
	{
		ft_memcpy(tmp->reg, father->reg, sizeof(father->reg));
		tmp->cycle_to_wait = -1;
		tmp->num_plr = plr;
		tmp->pc = pc;
		tmp->next = beg;
	}
	return (tmp);
}

void	ft_init_pc(int plr, int pc, t_vm *vm, t_process *proc)
{
	vm->proc = ft_add_link(vm->proc, plr, pc, proc);
	vm->proc->num = vm->nb_proc++;
}

int		ft_init_lst_proc(t_vm *vm)
{
	t_process	*tmp;
	t_list_player	*lst_play;
	//t_process	*tmp2;

	lst_play = vm->bplr.lst_plyr;
	while (lst_play)
	{
		if (!(tmp = (t_process*)ft_memalloc(sizeof(t_process))))
			ft_error("error malloc");
		ft_init_proc(lst_play->plr, tmp);
		ft_fetch_next(vm, tmp);
		tmp->num = vm->nb_proc;
		vm->nb_proc += 1;
		//tmp->next = NULL;


		tmp->next = vm->proc;
		vm->proc = tmp;
		/*
		   if (vm->proc == NULL)
		   vm->proc = tmp;
		   else
		   tmp2->next = tmp;
		   tmp2 = tmp;*/
		/*
		   tmp->next = vm->proc;
		   vm->proc = tmp;*/
		lst_play = lst_play->next;
	}
	//		ft_putendl("\n__SORTIE_____\n");
	return (0);
}

int		copy_plr(t_vm *vm, t_bin *plr, int i)
{
	int		j;
	int		size;

	size = r4oi(plr->prog_size);
	j = 0;
	plr->pc_tmp = i;
	vm->data[i].pc = 1;
	while (j < size)
	{
		vm->core[i] = plr->program[j];
		vm->data[i].num_plr = plr->num_plyr;
		//printf(">%d\t%d\t%d< ", i, vm->core[i], vm->data[i].pc);
		//if (i == 3687)
		//printf(">>>>%d %d %d<<<", i, vm->core[i],  vm->data[i].pc);
		i++;
		j++;
	}
	plr->size = size;
	return (0);
}

int		ft_init_arena2(t_vm *vm)
{
	t_list_player *tmp;

	tmp = vm->bplr.lst_plyr;
	if (vm->bplr.nb_plyr == 1)
		copy_plr(vm, tmp->plr, 0);
	else if (vm->bplr.nb_plyr == 2)
	{
		copy_plr(vm, tmp->next->plr, (MEM_SIZE / 2));
		copy_plr(vm, tmp->plr, 0);
	}
	else if (vm->bplr.nb_plyr == 3)
	{
		copy_plr(vm, tmp->next->next->plr, ((MEM_SIZE / 3) * 2));
		copy_plr(vm, tmp->next->plr, (MEM_SIZE / 3));
		copy_plr(vm, tmp->plr, 0);
	}
	else if (vm->bplr.nb_plyr == 4)
	{
		copy_plr(vm, tmp->next->next->next->plr, ((MEM_SIZE / 4) * 3));
		copy_plr(vm, tmp->next->next->plr, (MEM_SIZE / 2));
		copy_plr(vm, tmp->next->plr, (MEM_SIZE / 4));
		copy_plr(vm, tmp->plr, 0);
	}
	return (0);
}

int		ft_init_arena(t_vm *vm)
{
	int				n_plyr;
	int				pos_delta;
	t_list_player	*l_plyr;

	n_plyr = 0;
	pos_delta = MEM_SIZE / vm->bplr.nb_plyr;
	l_plyr = vm->bplr.lst_plyr;

	while (l_plyr)
	{
		copy_plr(vm, l_plyr->plr, n_plyr * pos_delta);
		n_plyr++;
		l_plyr = l_plyr->next;
	}
	return (0);
}
