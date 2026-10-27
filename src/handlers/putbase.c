/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putbase.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamr <ael-hamr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:56:10 by ael-hamr          #+#    #+#             */
/*   Updated: 2026/10/27 13:56:48 by ael-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_signed(t_data *data, int nbr)
{
	if (nbr < 0)
	{
		print_char(data, '-');
		ft_putnbr_base(data, (unsigned long)(-(long)nbr),
			"0123456789");
	}
	else
		ft_putnbr_base(data, (unsigned long)nbr, "0123456789");
}

void	ft_putnbr_base(t_data *data, unsigned long nbr, char *base)
{
	unsigned long	base_len;
	int				count;
	char			digit;

	base_len = 0;
	count = 0;
	while (base[base_len])
		base_len++;
	if (base_len < 2)
		return ;
	if (nbr < 0)
	{
		print_char(data, '-');
		nbr = -nbr;
	}
	if (nbr >= base_len)
		ft_putnbr_base(data, nbr / base_len, base);
	digit = base[nbr % base_len];
	print_char(data, digit);
}
