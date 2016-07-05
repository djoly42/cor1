/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testdav.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 10:18:48 by djoly             #+#    #+#             */
/*   Updated: 2016/04/28 17:57:56 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/reverse_octet.h"
#include <stdio.h>

void test_r2o()
{
char core[] = "defg";
	union u_2o	v2;
	union u_4o	v4;


	v2.c[0] =	core[0];
	v2.c[1] =	core[1];

	v4.c[0] =	core[0];
	v4.c[1] =	core[1];
	v4.c[2] =	core[2];
	v4.c[3] =	core[3];
	printf("|%d|%d|\n", v2.i, v4.i);
	r2o(&v2);
	r4o(&v4);
	printf("|%d|%d|", v2.i, v4.i);
}

void	print_core(t_base_core *core)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			printf("\n");
		//printf(" %.2d", core->core[i]);
		printf(" %.2x", core->core[i]);
		i++;
	}
}

int main()
{
	t_vm	vm;
	
	vm_init(&vm);
	print_core(&vm.core);

	//test_r2o();


	return (0);
}
