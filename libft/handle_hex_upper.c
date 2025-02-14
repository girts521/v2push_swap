/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: girts <girts@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:30:40 by girts             #+#    #+#             */
/*   Updated: 2024/07/27 16:45:58 by girts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_hex_upper(va_list ap, int *i)
{
	unsigned int	hex_arg;
	unsigned int	temp;
	int				len;

	hex_arg = va_arg(ap, unsigned int);
	len = 1;
	temp = hex_arg;
	ft_puthex_upper_fd(hex_arg, 1);
	while (temp >= 16)
	{
		temp = temp / 16;
		len++;
	}
	*i += len;
}
