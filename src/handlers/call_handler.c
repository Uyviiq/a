/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamr <ael-hamr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:51:37 by ael-hamr          #+#    #+#             */
/*   Updated: 2026/10/27 14:52:04 by ael-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_basic_specifiers(t_data *data)
{
	if (data->specifier == SPEC_CHAR || data->specifier == SPEC_STRING)
		print_string(data);
	else if (data->specifier == SPEC_INTEGER)
		print_signed(data, va_arg(data->args, int));
	else if (data->specifier == SPEC_UNSIGNED)
		ft_putnbr_base(data, va_arg(data->args, unsigned int),
			"0123456789");
	else if (data->specifier == SPEC_PERCENT)
		print_char(data, '%');
}

void	handle_address_specifiers(t_data *data)
{
	void	*ptr;

	if (data->specifier == SPEC_POINTER)
	{
		ptr = va_arg(data->args, void *);
		if (!ptr)
		{
			ft_putstr(data, "(nil)");
			return ;
		}
		ft_putstr(data, "0x");
		ft_putnbr_base(data, (unsigned long)ptr,
			"0123456789abcdef");
	}
	else if (data->specifier == SPEC_HEX_LOWER)
		ft_putnbr_base(data, (unsigned long)va_arg(data->args, unsigned int),
			"0123456789abcdef");
	else if (data->specifier == SPEC_HEX_UPPER)
		ft_putnbr_base(data, (unsigned long)va_arg(data->args, unsigned int),
			"0123456789ABCDEF");
}
