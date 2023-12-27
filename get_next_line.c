/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:15:55 by angsanch          #+#    #+#             */
/*   Updated: 2023/12/27 11:09:51 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*process_buffer(int fd, t_buff *b)
{
	char		*result;
	char		*copy;
	size_t		size;
	int			line_len;
	long int	readed;

	size = 0;
	result = NULL;
	while (1)
	{
		readed = read(fd, b->b + b->used, BUFFER_SIZE - b->used);
		if (readed <= 0 && b->used == 0)
			return (result);
		b->used += readed;
		copy = result;
		result = ft_memjoin(result, size, b->b, b->used);
		free(copy);
		if (result == NULL)
			return (NULL);
		size += b->used;
		result[size] = 0;
		b->used = 0;
		line_len = ft_strnchr_index(result, '\n', size);
		if (line_len != -1)
			break ;
	}
	ft_memcpy(b->b, result + line_len + 1, size - line_len - 1);
	b->used = size - line_len - 1;
	result[line_len + 1] = 0;
	return (result);
}

char	*get_next_line(int fd)
{
	static t_buff	buffs[FD_SETSIZE + 1] = {{0, ""}};
	unsigned int	i;

	if (buffs[0].used == 0)
	{
		i = 1;
		while (i < FD_SETSIZE)
		{
			buffs[i].used = 0;
			i ++;
		}
		buffs[0].used = 1;
	}
	if (fd < 0)
		return (NULL);
	return (process_buffer(fd, &buffs[fd + 1]));
}
