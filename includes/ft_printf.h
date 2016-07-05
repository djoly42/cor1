/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:43:34 by tmanet            #+#    #+#             */
/*   Updated: 2016/05/03 12:38:33 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct s_str_conv	t_str_conv;

struct				s_str_conv
{
	char			error;
	char			space;
	char			zero;
	char			plus;
	char			hash;
	char			minus;
	char			point;
	char			*str_out;
	size_t			size;
	size_t			prec;
	size_t			width;
	va_list			ap;
	char			*type;
	t_str_conv		*next;
};

typedef struct		s_flag
{
	char			*ptn;
	size_t			size;
	size_t			(*f)(t_str_conv*, char*);
	struct s_flag	*next;
}					t_flag;

typedef struct		s_conv
{
	char			*ltr;
	size_t			size;
	int				less_flags;
	char			*(*f)(t_str_conv*);
	struct s_conv	*next;
}					t_conv;

typedef struct		s_param
{
	t_conv			*conv;
	t_flag			*flag;
}					t_param;

int					ft_printf(char *str, ...);
int					ft_param_size(char *str, t_list *conv);
t_flag				*ft_flag_lister();
t_flag				*ft_newflag(t_flag *nxt, char *ptn,
		size_t (*f)(t_str_conv*, char*));
t_param				*ft_param_builder(void);
t_conv				*ft_conv_lister();
t_conv				*ft_newconv(t_conv *nxt, char *ptn,
		char *(*f)(t_str_conv*));
size_t				ft_conv_picker(char *str, t_str_conv **elem,
		t_param *param);
int					ft_putcountstr(char *str);
t_str_conv			*ft_strsplit_to_conv(char *str, t_param *param, va_list ap);
int					ft_endof_opt(char *str, t_conv *conv);
size_t				ft_str_picker(char *str, t_str_conv **elem);
char				*ft_conv_s(t_str_conv *sub);
char				*ft_conv_ups(t_str_conv *sub);
char				*ft_conv_c(t_str_conv *sub);
char				*ft_conv_upc(t_str_conv *sub);
char				*ft_conv_d(t_str_conv *sub);
char				*ft_conv_upd(t_str_conv *sub);
char				*ft_conv_o(t_str_conv *sub);
char				*ft_conv_upo(t_str_conv *sub);
char				*ft_conv_x(t_str_conv *sub);
char				*ft_conv_upx(t_str_conv *sub);
char				*ft_conv_u(t_str_conv *sub);
char				*ft_conv_upu(t_str_conv *sub);
char				*ft_conv_p(t_str_conv *sub);
char				*ft_conv_percent(t_str_conv *sub);
size_t				ft_conv_no(t_str_conv *sub, char *str);
size_t				ft_flag_h(t_str_conv *sub, char *str);
size_t				ft_flag_hash(t_str_conv *sub, char *str);
size_t				ft_flag_hh(t_str_conv *sub, char *str);
size_t				ft_flag_j(t_str_conv *sub, char *str);
size_t				ft_flag_l(t_str_conv *sub, char *str);
size_t				ft_flag_ll(t_str_conv *sub, char *str);
size_t				ft_flag_minus(t_str_conv *sub, char *str);
size_t				ft_flag_picker(char *str, t_str_conv *sub, t_param *param);
size_t				ft_flag_plus(t_str_conv *sub, char *str);
size_t				ft_flag_point(t_str_conv *sub, char *str);
void				ft_flag_validator(t_str_conv *sub, t_conv *conv);
size_t				ft_flag_space(t_str_conv *sub, char *str);
size_t				ft_flag_star(t_str_conv *sub, char *str);
size_t				ft_flag_z(t_str_conv *sub, char *str);
size_t				ft_flag_zero(t_str_conv *sub, char *str);
void				ft_string_modifier(t_str_conv *sub);
void				ft_plus_modifier(t_str_conv *sub);
size_t				ft_precision_picker(t_str_conv *sub, char *str);
void				ft_prec_modifier(t_str_conv *sub);
void				ft_width_modifier(t_str_conv *sub);
size_t				ft_width_picker(t_str_conv *sub, char *str);
void				ft_space_modifier(t_str_conv *sub);
void				ft_str_conv_cleaner(t_str_conv **elem);
int					ft_param_cleaner(t_param **param, t_str_conv **elem);
void				ft_conv_cleaner(t_conv **conv);
void				ft_flag_cleaner(t_flag **flag);
size_t				ft_wide_size(unsigned int wide);
char				*ft_wchartostr(wchar_t wide);
size_t				ft_last_char(char *str, size_t size);
void				ft_hash_for_hex(t_str_conv *sub, char *str);
#endif
