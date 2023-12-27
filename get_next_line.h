/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:45:54 by angsanch          #+#    #+#             */
/*   Updated: 2023/12/27 21:03:13 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <sys/select.h>

typedef struct buffer
{
	size_t	used;
	char	b[BUFFER_SIZE];
}	t_buff;

char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strnchr_index(const char *s, int c, int len);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memjoin(const void *m1, size_t s1, const void *m2, size_t s2);

#endif
