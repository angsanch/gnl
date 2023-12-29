/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:45:54 by angsanch          #+#    #+#             */
/*   Updated: 2023/12/30 00:02:32 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/select.h>

typedef struct file
{
	char	*buffer;
	size_t	buff_len;
	char	*line;
	ssize_t	len;
}	t_file;

char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strnchr_index(const char *s, int c, int len);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memjoin(const void *m1, size_t s1, const void *m2, size_t s2);
void	*memjoin_free(const void *m1, size_t s1, const void *m2, size_t s2);

#endif
