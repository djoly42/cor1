/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:26:12 by djoly             #+#    #+#             */
/*   Updated: 2016/05/18 11:18:35 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H
# include "corewar.h"
# include "ir.h"

struct s_process
{
	int		num;  // numero du processus
	int		num_plr; // num du plyr ou
	int		cycle_to_wait; // -1 soit cur_cycle + temps d attente
	int		pc;
	int		pcdelta; // avancer de pc + pcdelta
	int		reg[17]; // LITTLE ENDIAN
	int		carry; //
	int		ir_error; //0
	t_ir	ir;
	t_process	*next;
	int		live;
	int		lst_live;
};
/*
struct s_list_process
{
	t_process		proc;
	t_list_process	*next;
};

struct s_base_process
{
	int				nb_proc;
	t_list_process	*lst_proc; // liste des processs
};
*/
#endif
