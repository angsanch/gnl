/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:16:39 by angsanch          #+#    #+#             */
/*   Updated: 2023/12/26 11:48:04 by angsanch         ###   ########.fr       */
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

int	ft_strnchr_index(const char *s, int c, int len)
{
	int				i;
	unsigned char	chr;

	chr = c;
	i = 0;
	while (s[i] != chr && s[i] != 0 && i < len)
		i ++;
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
