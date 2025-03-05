/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:02:28 by enkwak            #+#    #+#             */
/*   Updated: 2024/11/01 12:18:11 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL || src == NULL || !n)
	{
		return (dest);
	}
	if (dest < src)
	{
		while (i < n)
		{
			*((char *)dest + i) = *((char *)src + i);
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			*((char *)dest + n - 1) = *((char *)src + n - 1);
			n--;
		}
	}
	return (dest);
}

// int main()
// {
// 	char str31[] = "abcdefghijklmnopqrstu";
//     char str32[] = "abcdefghijklmnopqrstu";
//     ft_memmove(str31 + 5, str31, 10);
//     memmove(str32 + 5, str32, 10);
//     printf("zisaku  : %s\n", str31);
//     printf("library : %s\n", str32);
// 	return (0);
// }