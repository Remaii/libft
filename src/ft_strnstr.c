/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:19:16 by rthidet           #+#    #+#             */
/*   Updated: 2015/12/10 22:35:00 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t bilen)
{
	size_t lilen;
	int cmp;

	if (little[0] == '\0')
		return ((char*)big);
	lilen = ft_strlen(little);
	cmp = 1;
	while (lilen <= bilen && *big != '\0'
			&& (cmp = ft_strncmp(big, little, lilen)))
	{
		bilen--;
		big++;
	}
	if (cmp != 0)
		return (NULL);
	else
		return ((char*)big);
}
