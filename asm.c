/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:55:31 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/09 16:21:39 by ssicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

int		main(int argc, char **argv)
{
	t_champ	chp;
	int i;

	init_structure(&chp);
	i = check_flags(&chp, argv);
	if (argc == 2 + i && argv[1 + i])
	{
		chp.file_n = argv[1 + i];
		read_s_file(&chp, argv[1 + i]);
		ft_find_labels(&chp);
		ft_check_champ(&chp);
		//argv[1] = epur_file_name(argv[1]);
		chp.file_n = ft_strjoin(argv[1 + i], ".cor");
		ft_print_champ(&chp);
	}
	else
		ft_putendl("Bad parameters");
	return (0);
}
