/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakrouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 23:36:41 by rakrouna          #+#    #+#             */
/*   Updated: 2020/04/30 23:36:43 by rakrouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# define BUFF_SIZE 4096

typedef struct	s_padding
{
	int	left_spaces;
	int	sign;
	int	zeros;
	int	size;
	int	right_spaces;
}				t_padding;

typedef struct	s_data
{
	va_list			ap;
	char			buffer[BUFF_SIZE];
	int				i;
	int				fd;
	int				left;
	int				plus;
	int				zero;
	int				space;
	int				sharp;
	int				l_min;
	int				prec;
	int				size;
	int				ret;
	const char		*invalid;
	t_padding		padding;
}				t_data;

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *restrict format, ...);
int				pf_atoi(const char *str);
void			pf_putpercent(t_data *data);
void			init_data(t_data *data, int fd);
void			parse_format(const char *restrict format, t_data *data);
void			pf_putchar(t_data *data);
void			pf_putfloat(t_data *data);
void			pf_putnbr(t_data *data);
void			pf_putunbr(t_data *data);
void			pf_putstr(t_data *data);
void			pf_putaddr(t_data *data);
void			pf_putnbr_x(t_data *data);
void			pf_putnbr_xcaps(t_data *data);
void			pf_putnbr_o(t_data *data);
void			pf_putnbr_b(t_data *data);
void			pf_putlong_base(unsigned long nbr, char *base, t_data *data);
void			pf_invalid(t_data *data);
void			pf_putpercent(t_data *data);
void			fill_buffer(t_data *data, const char *s, unsigned int size);
char			parse_flags(const char *s, int *i, t_data *data);
void			parse_color(const char *s, int *i, t_data *data);
int				pf_atoi(const char *str);
void			reset_options(t_data *data);
int				pf_strnequ(char const *s1, char const *s2, size_t n);
void			set_fpadding_lmin(t_data *data);
void			fill_buffer(t_data *data, const char *s, unsigned int size);
void			set_fpadding(t_data *data, long i_part, long double nb);
void			set_fpadding_inf(t_data *data, long double nb);
int				inf(t_data *data, long double nb);
long double		cast_float(t_data *data);
int				get_size(long nbr);
long double		power(long double nb, int power);
char			*pf_strnew(int size, t_data *data);
void			rev_str(char *str, int len);
void			pf_strdel(char **ap);
void			parse_options(const char *s, int *i, t_data *data);
void			parse_l_min(const char *s, int *i, t_data *data);
void			parse_prec(const char *s, int *i, t_data *data);
void			parse_size(const char *s, int *i, t_data *data);
void			parse_wildcard(const char *s, int *i, t_data *data);

#endif
