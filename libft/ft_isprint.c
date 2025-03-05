/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:53:20 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/29 16:34:25 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
	{
		return (1);
	}
	return (0);
}

// int main()
// {
// 	printf("library :%d\n", isprint('2'));
//     printf("zisaku  :%d\n", ft_isprint('2'));
//     printf("library :%d\n", isprint('\t'));
//     printf("zisaku  :%d\n", ft_isprint('\t'));
//     printf("library :%d\n", isprint('\n'));
//     printf("zisaku  :%d\n", ft_isprint('\n'));
// 	return (0);
// }