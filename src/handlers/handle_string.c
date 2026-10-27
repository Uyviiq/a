/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamr <ael-hamr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 19:00:24 by ael-hamr          #+#    #+#             */
/*   Updated: 2026/10/26 09:56:13 by ael-hamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(t_data *data)
{
	char	*str;

	if (data->specifier == SPEC_CHAR)
		print_char(data, va_arg(data->args, int));
	else
	{
		str = va_arg(data->args, char *);
		if (!str)
		{
			ft_putstr(data, "(null)");
			return ;
		}
		ft_putstr(data, str);
	}
}
