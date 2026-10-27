/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamr <ael-hamr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 09:06:51 by ael-hamr          #+#    #+#             */
/*   Updated: 2026/10/27 13:59:03 by ael-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef enum e_specifier
{
	SPEC_CHAR,
	SPEC_STRING,
	SPEC_POINTER,
	SPEC_INTEGER,
	SPEC_UNSIGNED,
	SPEC_HEX_LOWER,
	SPEC_HEX_UPPER,
	SPEC_PERCENT,
	SPEC_INVALID,
}	t_specifier;

typedef enum e_status
{
	STATUS_OK = 0,
	STATUS_ERROR = 1337,
	PRINTF_ERROR = -1,
	YES = 1,
	NO = 0
}	t_status;

typedef struct s_data
{
	const char	*fmt;
	int			fmt_index;
	int			count;
	va_list		args;
	t_specifier	specifier;
}	t_data;

// prototypes
int			ft_printf(const char *fmt, ...);
t_status	print_char(t_data *data, char c);
t_status	ft_putstr(t_data *data, const char *s);
t_status	parse_format(t_data *data);
size_t		ft_strlen(const char *s);
void		handle_address_specifiers(t_data *data);
void		handle_basic_specifiers(t_data *data);
void		print_string(t_data *data);
void		ft_putnbr_base(t_data *data, unsigned long nbr, char *base);
void		print_signed(t_data *data, int nbr);
void		print_percent(t_data *data);

#endif
