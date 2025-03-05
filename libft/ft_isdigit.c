/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:36:53 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/29 16:33:56 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
	{
		return (1);
	}
	return (0);
}

// int main()
// {
// 	printf("library :%d\n", isdigit('2'));
//     printf("zisaku  :%d\n", ft_isdigit('2'));
//     printf("library :%d\n", isdigit('A'));
//     printf("zisaku  :%d\n", ft_isdigit('A'));
//     printf("library :%d\n", isdigit('1'));
//     printf("zisaku  :%d\n", ft_isdigit('1'));
// 	return (0);
// }