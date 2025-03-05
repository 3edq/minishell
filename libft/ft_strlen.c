/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:57:48 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/25 17:15:02 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

// int main()
// {
// 	int str121 = strlen("chidoridaisuki");
//     int str122 = ft_strlen("chidoridaisuki");
//     printf("library: %d\n", str121);
//     printf("zisaku : %d\n", str122);
// 	return (0);
// }