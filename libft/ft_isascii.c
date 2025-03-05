/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:48:06 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/25 17:40:29 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

// int main()
// {
// 	printf("library :%d\n", isascii(' '));
//     printf("zisaku  :%d\n", ft_isascii('a'));
//     printf("library :%d\n", isascii('A'));
//     printf("zisaku  :%d\n", ft_isascii('A'));
//     printf("library :%d\n", isascii('1'));
//     printf("zisaku  :%d\n", ft_isascii('1'));
// 	return (0);
// }