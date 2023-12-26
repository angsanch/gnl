/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:15:55 by angsanch          #+#    #+#             */
/*   Updated: 2023/12/26 13:29:49 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
static char *process_buffer(int fd, t_buff *b)
{
	unsigned long int	readed;
	int					line_length;
	char				*result;

	readed = read(fd, b->b + b->used, BUFFER_SIZE - b->used);
	b->used += readed;
	printf("%lu %zd ", readed, b->used);
	if (readed < 0 || (b->used == 0 && readed == 0))
		return (NULL);
	line_length = ft_strnchr_index(b->b, '\n', b->used);
	printf("%d\n", line_length);
	if (line_length == -1)
		line_length = b->used;
	if (line_length > BUFFER_SIZE)
			line_length = BUFFER_SIZE;
	result = malloc(sizeof(char) * (line_length + 1));
	if (result == NULL)
		return (result);
	ft_memcpy(result, b->b, line_length);
	result[line_length] = '\0';
	b->used -= line_length;
	ft_memmove(b->b, b->b + line_length, b->used);
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
	return (process_buffer(fd, &buffs[fd + 1]));
}
