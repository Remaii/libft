/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 15:28:07 by rthidet           #+#    #+#             */
/*   Updated: 2015/12/10 23:32:18 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int i;
	int nbr[10];

	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (!n)
		ft_putchar_fd('0', fd);
	while (n)
	{
		nbr[i] = n % 10;
		n /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_putchar_fd((nbr[i] + 48), fd);
	}
}
