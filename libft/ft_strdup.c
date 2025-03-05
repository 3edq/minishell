/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:57:22 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/29 18:33:29 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*dest;

	size = ft_strlen(s1);
	dest = (char *)malloc((size + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s1, size + 1);
	return (dest);
}

// int main()
// {
// 	char str161[] ="radwimps";
//     printf("zisaku  : %s\n", ft_strdup(str161));
//     printf("library  : %s\n", strdup(str161));
// 	return (0);
// }