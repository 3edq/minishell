/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:53:41 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/27 00:56:02 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

// int main()
// {
//     char str51[] ="nesugosita!!!";
//     char str52[] ="nesugosita!!!";
//     printf("zisaku  : %s\n", ft_memchr(str51, 103, 15));
//     printf("library : %s\n", memchr(str52, 103, 15));
// 	return (0);
// }