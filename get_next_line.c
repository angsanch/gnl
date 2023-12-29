/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:15:55 by angsanch          #+#    #+#             */
/*   Updated: 2023/12/30 00:03:01 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	extract_line(t_file *f)
{
	if (f->buffer == NULL || f->buff_len == 0)
	{
		f->len = 0;
		f->line = NULL;
		return ;
	}
	f->len = ft_strnchr_index(f->buffer, '\n', f->buff_len);
	if (f->len == -1)
	{
		f->line = ft_memjoin(f->buffer, f->buff_len, "\0", 1);
		f->len = f->buff_len;
		f->buff_len = 0;
		free(f->buffer);
		f->buffer = NULL;
		return ;
	}
	f->line = ft_memjoin(f->buffer, f->len + 1, "\0", 1);
	f->buff_len -= f->len + 1;
	ft_memmove(f->buffer, f->buffer + f->len + 1, f->buff_len);
}

static int	read_until_end_line(int fd, t_file *f)
{
	char	*buffer;
	long	readed;

	buffer = malloc(sizeof(char *) * BUFFER_SIZE);
	if (buffer == NULL)
		return (0);
	while (1)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed <= 0)
		{
			free(buffer);
			if (readed == 0 && f->buff_len == 0)
				free(f->buffer);
			return (readed == 0);
		}
		f->buffer = memjoin_free(f->buffer, f->buff_len, buffer, readed);
		f->buff_len += readed;
		if (ft_strnchr_index(f->buffer, '\n', f->buff_len) != -1)
		{
			free (buffer);
			return (1);
		}
	}
}

static char	*get_line(int fd, t_file *f)
{
	if (read_until_end_line(fd, f) == 0)
	{
		free (f->buffer);
		f->buff_len = 0;
		f->len = 0;
		return (NULL);
	}
	extract_line(f);
	return (f->line);
}

char	*get_next_line(int fd)
{
	static t_file	file = {NULL, 0, NULL, 0};

	if (fd < 0)
		return (NULL);
	return (get_line(fd, &file));
}
