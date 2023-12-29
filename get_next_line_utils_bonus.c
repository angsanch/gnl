/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:16:39 by angsanch          #+#    #+#             */
/*   Updated: 2023/12/29 18:41:04 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dstint;
	const char	*srcint;

	i = 0;
	dstint = dst;
	srcint = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dstint[i] = srcint[i];
		i ++;
	}
	return (dst);
}

void	*ft_memjoin(const void *m1, size_t s1, const void *m2, size_t s2)
{
	void	*result;

	result = malloc(sizeof(char) * (s1 + s2 + 2));
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, m1, s1);
	ft_memcpy(result + s1, m2, s2);
	return (result);
}

int	ft_strnchr_index(const char *s, int c, int len)
{
	int				i;
	unsigned char	chr;

	chr = c;
	i = 0;
	while (i < len)
	{
		if (s[i] == chr)
			break ;
		i ++;
	}
	if (i >= len)
		return (-1);
	if (s[i] == chr)
		return (i);
	else
		return (-1);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*dstchr;
	const char	*srcchr;
	size_t		i;

	if (src > dst)
	{
		ft_memcpy(dst, src, n);
		return (dst);
	}
	if (dst == src)
		return (dst);
	dstchr = dst;
	srcchr = src;
	i = 0;
	while (i < n)
	{
		dstchr[n - i - 1] = srcchr[n - i - 1];
		i ++;
	}
	return (dst);
}
