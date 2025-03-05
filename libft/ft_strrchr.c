/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:29:04 by enkwak            #+#    #+#             */
/*   Updated: 2024/11/01 11:47:20 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	search;

	if (c == '\0')
	{
		return ((char *)(str + ft_strlen(str)));
	}
	search = ft_strlen((char *)str) + 1;
	while (search--)
	{
		if (*(str + search) == (char)c)
			return ((char *)(str + search));
	}
	return (NULL);
}

// int main()
// {
// 	char a[] = "aiueo";
//     printf("zisaku  : %s\n", ft_strrchr(a, 'a'));
//     printf("library : %s\n", strrchr(a, 'a'));
//     printf("zisaku  : %s\n", ft_strrchr(a, 'i'));
//     printf("library : %s\n", strrchr(a, 'i'));
//     printf("zisaku  : %s\n", ft_strrchr(a, 'u'));
//     printf("library : %s\n", strrchr(a, 'u'));
//     printf("zisaku  : %s\n", ft_strrchr(a, 'e'));
//     printf("library : %s\n", strrchr(a, 'e'));
//     printf("zisaku  : %s\n", ft_strrchr(a, 'o'));
//     printf("library : %s\n", strrchr(a, 'o'));
//     printf("zisaku  : %s\n", ft_strrchr(a, 0));
//     printf("library : %s\n", strrchr(a, 0));
// 	return (0);
// }