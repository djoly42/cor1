/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 18:09:31 by eozdek            #+#    #+#             */
/*   Updated: 2016/05/18 12:10:01 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
fonction recupere le num du plr et stock dans la T_vm
*/

int		ft_stock_num_plr(char **av, int *i, t_vm *vm)
{
	(*i)++;
	if (!av[*i] || ft_is_number(av[*i]) == 0)
		ft_error("ARG is not a number");
	BPLR.tmpnum = BPLR.tab[BPLR.nb_plyr];
	BPLR.tab[BPLR.nb_plyr] = ft_atoi(av[*i]);
	BPLR.i_plr += 1;
	ft_check_other_num(BPLR);
	return (0);
}

/*
fonction pour gerer les bonus et ARGS
*/

void	ft_handle_bonus(char **av, int *i, t_vm *vm)
{
	if (ft_strcmp("-v", av[*i]) == 0){
//		ft_putstr(">>DANS -D<<");
		ft_stock_verb(av, i, vm);
	}
	if (ft_strcmp("-d", av[*i]) == 0){
//		ft_putstr(">>DANS -D<<");
		ft_stock_dump(av, i, vm);
	}
	if (ft_strcmp("-a", av[*i]) == 0){
//		ft_putstr(">>DANS -D<<");
		ft_stock_aff(vm);
	}
	if (ft_strcmp("--color", av[*i]) == 0){
//		ft_putstr(">>DANS -D<<");
		ft_stock_color(vm);
	}
	if (ft_strcmp("-s", av[*i]) == 0){
//		ft_putstr(">>DANS -D<<");
		ft_stock_step(av, i, vm);
	}
	if (ft_strcmp("-n", av[*i]) == 0)
	{
//		ft_putstr(">>DANS -N<<");


		ft_stock_num_plr(av, i, vm);
	}
//	if (ft_strcmp("-v", av[*i]) == 0)
//	{
//		ft_putstr(">>DANS -V<<");
//		ft_stock_verbose(av, i, vm);
//}
}

/*
INIT numero du plr
*/

void	ft_init_num_plr(t_base_player *player, t_list_player *tmp)
{
	tmp->plr->num_plyr = player->tab[player->nb_plyr];
}

/*
alloue de la memoire pour une nouvelle cellule et met de l'information dedans,
*/

void	ft_mem_champs(t_base_player *player, char *av)
{
	t_list_player	*tmp;
	//t_list_player	*tmp2;
	t_list_player	*lplr;

	tmp = (t_list_player*)ft_memalloc(sizeof(t_list_player));
	tmp->plr = (t_bin *)ft_memalloc(sizeof(t_bin));
	ft_open_champion(av, tmp->plr);
	lplr = player->lst_plyr;

	while(lplr && lplr->next)
		lplr = lplr->next;
	if(!lplr)
		player->lst_plyr = tmp;
	else
		lplr->next = tmp;


/*

	if (!player->lst_plyr)
	{
		player->lst_plyr = tmp;
	}
	else
	{
		tmp2 = player->lst_plyr;
		player->lst_plyr = tmp;
		tmp->next = tmp2;
	}*/
	ft_init_num_plr(player, tmp);
//	player->nb_plyr = player->nb_plyr + 1;
}

/*
gerer chaque arguments, voir si cest un ".cor" (rentre dans les verifs des champions), sinon dans ceux des bonus
*/

void	ft_handle_args(int ac, char **av, t_vm *vm)
{
	int				i;
//	t_base_player	*player;

	i = 1;
//	player = (t_base_player*)ft_memalloc(sizeof(t_base_player));
	BPLR.nb_plyr = 0;
//			ft_putstr(">>WTF<<\n");
	while (i < ac)
	{
		if (ft_check_args(av[i]))
		{
//			ft_putstr(">>WTF<<\n");
			ft_mem_champs(&(BPLR), av[i]);
			vm->bplr.nb_plyr += 1;
//			printf("nombre de joueurs : %d\n", vm->bplr.nb_plyr);
			if (BPLR.nb_plyr > 4)
				ft_error("Wrong number of players");
		}
		else
		{
//			ft_putstr(">>GO IN HANDE BONUS<<\n");
			ft_handle_bonus(av, &i, vm);
		}
		i++;
	}
	if (BPLR.nb_plyr <= 0)
		ft_error("Wrong number of players");
//			ft_putstr(">>FIN<<\n");
}
