/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 20:00:13 by rthidet           #+#    #+#             */
/*   Updated: 2015/12/10 21:33:00 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char *ret;

	ret = dst;
	while (*src != '\0' && n > 0)
	{
		*dst++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*dst++ = '\0';
		n--;
	}
	return (ret);
}
