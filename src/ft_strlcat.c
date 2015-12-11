/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:49:36 by rthidet           #+#    #+#             */
/*   Updated: 2015/12/04 02:23:25 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char *dest;
	const char *srce;
	size_t i;
	size_t den;

	i = size;
	dest = dst;
	srce = src;
	while (i-- != 0 && *dest != '\0')
		dest++;
	den = dest - dst;
	i = size - den;
	if (i == 0)
		return (den + ft_strlen(srce));
	while (*srce != '\0')
	{
		if (i != 1)
		{
			*dest++ = *srce;
			i--;
		}
		srce++;
	}
	*dest = '\0';
	return (den + (srce - src));
}

/*
int		main()
{
	char dest[50] = {0};
	char dest1[50] = {0};

	printf("strlcat = %zu\n ft_strlcat = %zu\n", strlcat(dest, "Hello ", 0), ft_strlcat(dest1, "Hello ", 0));
	printf("strlcat = %zu\n ft_strlcat = %zu\n", strlcat(dest, "Hello ", 2), ft_strlcat(dest1, "Hello ", 2));
	printf("strlcat = %zu\n ft_strlcat = %zu\n", strlcat(dest, "Hello ", 4), ft_strlcat(dest1, "Hello ", 4));
	printf("strlcat = %zu\n ft_strlcat = %zu\n", strlcat(dest, "Hello ", 5), ft_strlcat(dest1, "Hello ", 5));
	printf("strlcat = %zu\n ft_strlcat = %zu\n", strlcat(dest, "Hello ", 6), ft_strlcat(dest1, "Hello ", 6));
	return (0);
}*/
