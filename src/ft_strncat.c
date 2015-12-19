/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:50:14 by rthidet           #+#    #+#             */
/*   Updated: 2015/12/19 16:47:25 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (s2[i] != '\0' && n != 0)
	{
		s1[len] = s2[i];
		len++;
		i++;
		if (n == 1)
			return (s1);
		n--;
	}
	s1[len] = '\0';
	return (s1);
}
