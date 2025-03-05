/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:04:05 by enkwak            #+#    #+#             */
/*   Updated: 2024/11/01 12:17:05 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (i < n)
	{
		*((unsigned char *)s + i) = c;
		i++;
	}
	return (s);
}

// int main()
// {
// 	char str01[] = "0123456789";
//     char str02[] = "0123456789";
//     ft_memset(str01 + 2, '*', 5);
//     memset(str02 + 2, '*', 5);
//     printf("zisaku  : %s\n", str01);
//     printf("library : %s\n", str02);
// 	return (0);
// }