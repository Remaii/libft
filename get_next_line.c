/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 22:59:31 by rthidet           #+#    #+#             */
/*   Updated: 2016/03/28 19:23:08 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			count_to_bn(t_gnl *gnl, int fd)
{
	int				i;

	i = 0;
	while (gnl->line[fd][i] != '\n' && gnl->line[fd][i] != '\0')
		i++;
	return (i);
}

static	void		get_line(t_gnl *gnl, int fd)
{
	if (gnl->line[fd] == NULL)
		gnl->line[fd] = ft_strnew(1);
	while (!(ft_strchr(gnl->line[fd], '\n'))
			&& (gnl->nb = read(fd, gnl->buffer, BUFF_SIZE)) > 0)
	{
		gnl->buffer[gnl->nb] = '\0';
		gnl->tmp = gnl->line[fd];
		gnl->line[fd] = ft_strjoin(gnl->line[fd], gnl->buffer);
		ft_strdel(&gnl->tmp);
	}
	ft_strdel(&gnl->buffer);
}

int					get_next_line(int const fd, char **line)
{
	static t_gnl	gnl;

	if (fd < 0 || fd > MAX_FD || line == NULL ||
		!(gnl.buffer = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	get_line(&gnl, fd);
	if (gnl.nb == -1)
		return (-1);
	*line = ft_strsub(gnl.line[fd], 0, count_to_bn(&gnl, fd));
	if (ft_strchr(gnl.line[fd], '\n'))
	{
		gnl.tmp = gnl.line[fd];
		gnl.line[fd] = ft_strdup(ft_strchr(gnl.line[fd], '\n') + 1);
		ft_strdel(&gnl.tmp);
		return (1);
	}
	if (count_to_bn(&gnl, fd) > 0)
	{
		gnl.line[fd] = gnl.line[fd] + count_to_bn(&gnl, fd);
		return (1);
	}
	return (0);
}
