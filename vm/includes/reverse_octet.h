/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_octet.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 09:59:24 by djoly             #+#    #+#             */
/*   Updated: 2016/05/01 10:53:24 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_OCTET_H
# define REVERSE_OCTET_H
# include "corewar.h"

union	u_2o
{
	short int 	i;
	char		c[2];
};

union	u_4o
{
	int 	i;
	char	c[4];
};

short int	r2oi(short int val);
int			r4oi(int val);

// reverse octet avec arg et return en union*
union u_2o *r2o(union u_2o *val); // reverse 2 octet
union u_4o *r4o(union u_4o *val); // reverse 4 octet

// reverse octet avec arg et return en char*
char *r2oc(char *val);// reverse 2 octet
char *r4oc(char *val); // reverse 4 octet


#endif
