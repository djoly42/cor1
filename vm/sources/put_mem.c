/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 17:49:26 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/17 13:49:32 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	put_mem(t_vm *vm, t_process *proc, int off, int val)
{
	union u_4o	tmp;
	int			i;
	int			k;
	int			j;

	tmp.i = val;
	i = 0;
	j = off % IDX_MOD;
	k = proc->pc + j;
	while (k < 0)
		k = k + MEM_SIZE;
	// ft_putendl("offset du pc :");
	// ft_putnbrendl(j);
	// ft_putendl("index d'ecriture :");
	// ft_putnbrendl(k % MEM_SIZE);
	while (i < 4)
	{
		vm->core[(k + i) % MEM_SIZE] = tmp.c[3 - i];
		vm->data[(k + i) % MEM_SIZE].num_plr = proc->num_plr;
		i++;
	}
}
