/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 22:27:43 by agrumbac          #+#    #+#             */
/*   Updated: 2016/12/15 06:23:51 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		read_more(const int fd, t_gnl *gnl)
{
	char	tmp_buf[BUFF_SIZE + 1];
	char	*tmp;

	gnl->readstatus = read(fd, tmp_buf, BUFF_SIZE);
	if (gnl->readstatus == -1)
	{
		gnl->errno = -1;
		return (-42);
	}
	if (gnl->readstatus == 0)
	{
		if (gnl->buf[0] != '\0')
			return (0);
		ft_memdel((void**)&(gnl->buf));
		gnl->errno = 0;
		return (-42);
	}
	tmp_buf[gnl->readstatus] = '\0';
	tmp = gnl->buf;
	gnl->buf = ft_strjoin(gnl->buf, tmp_buf);
	free(tmp);
	return (1);
}

char	*line_seeker(t_gnl *gnl)
{
	char	*tmp_line;
	char	*tmp;

	while (!(ft_strchr(gnl->buf, '\n')))
	{
		if (read_more(gnl->fd, gnl) == -42)
			return (NULL);
		if (!gnl->buf)
			return (NULL);
		if (gnl->readstatus == 0)
		{
			gnl->readstatus = 1;
			tmp_line = ft_strdup(gnl->buf);
			ft_memdel((void**)&(gnl->buf));
			return (tmp_line);
		}
	}
	gnl->endlpos = (int)(ft_strchr(gnl->buf, '\n') - gnl->buf);
	if (!(tmp_line = ft_strnew(gnl->endlpos)))
		return (NULL);
	ft_memccpy(tmp_line, gnl->buf, '\n', gnl->endlpos);
	tmp = gnl->buf;
	gnl->buf = ft_strdup((gnl->buf + gnl->endlpos + 1));
	free(tmp);
	return (tmp_line);
}

void	gnl_init(t_gnl *gnl, int fd)
{
	gnl->fd = fd;
	gnl->buf = NULL;
	gnl->readstatus = 1;
	gnl->errno = -1;
}

t_gnl	*list_manager(t_list **fdlist, int fd)
{
	t_list	*new_lst;
	t_gnl	*new_gnl;

	if (!(new_lst = *fdlist))
	{
		if (!(new_gnl = (t_gnl*)malloc(sizeof(t_gnl))) || \
			!(*fdlist = ft_lstnew(new_gnl, sizeof(t_gnl))))
			return (NULL);
		free(new_gnl);
		gnl_init(((t_gnl*)((*fdlist)->content)), fd);
	}
	while (new_lst)
		if (((t_gnl*)(new_lst->content))->fd == fd)
			return (new_lst->content);
		else
			new_lst = new_lst->next;
	if (!(new_gnl = (t_gnl*)malloc(sizeof(t_gnl))) || \
		!(new_lst = ft_lstnew(new_gnl, sizeof(t_gnl))))
		return (NULL);
	free(new_gnl);
	gnl_init(((t_gnl*)((new_lst)->content)), fd);
	ft_lstaddend(fdlist, new_lst);
	return (new_lst->content);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*fdlist = NULL;
	char			*tmp_line;
	int				status;

	if (!line || fd < 0)
		return (-1);
	if (!(list_manager(&fdlist, fd)->buf))
		if (!(list_manager(&fdlist, fd)->buf = ft_strnew(0)))
			return (-1);
	if (!(list_manager(&fdlist, fd)->readstatus))
		return (0);
	tmp_line = line_seeker(list_manager(&fdlist, fd));
	*line = tmp_line;
	if (!(tmp_line))
		return (list_manager(&fdlist, fd)->errno);
	status = list_manager(&fdlist, fd)->readstatus;
	return (status > 0 ? 1 : status);
}
