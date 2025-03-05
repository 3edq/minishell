/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:12:12 by enkwak            #+#    #+#             */
/*   Updated: 2024/11/01 11:50:15 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

// int main()
// {
// 	char str71[] ="nesugosita!!!";
//     char str72[] ="nesugosita!!!";
//     printf("zisaku  : %s\n", ft_strchr(str71, 103));
//     printf("library : %s\n", strchr(str72, 103));
//     char str73[] = "aiueo";
//     printf("zisaku  : %s\n", ft_strchr(str73, 'a'));
//     printf("library : %s\n", strchr(str73, 'a'));
//     printf("zisaku  : %s\n", ft_strchr(str73, 'i'));
//     printf("library : %s\n", strchr(str73, 'i'));
//     printf("zisaku  : %s\n", ft_strchr(str73, 'u'));
//     printf("library : %s\n", strchr(str73, 'u'));
//     printf("zisaku  : %s\n", ft_strchr(str73, 'e'));
//     printf("library : %s\n", strchr(str73, 'e'));
// 	return (0);
// }