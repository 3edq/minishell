/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:39:14 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/26 23:26:43 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *s1 == *s2 && *s1 && *s2)
	{
		i++;
		s1++;
		s2++;
	}
	if (i == n)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

// int main()
// {
// 	 char str141[] = "chidoridaisuki";
//     char str142[] = "chidoridaisuki";
//     char str143[] = "chidori&nobu&daigo";
//     printf("library: %d\n", strncmp(str141, str142, 14));
//     printf("zisaku : %d\n", ft_strncmp(str141, str142, 14));
//     printf("library: %d\n", strncmp(str141, str143, 7));
//     printf("zisaku : %d\n", ft_strncmp(str141, str143, 7));
//     printf("library: %d\n", strncmp(str141, str143, 8));
//     printf("zisaku : %d\n", ft_strncmp(str141, str143, 8));
// 	return (0);
// }