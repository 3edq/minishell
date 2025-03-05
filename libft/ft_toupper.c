/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:05:57 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/29 16:53:33 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
	{
		return (c - 32);
	}
	return (c);
}

// int main()
// {
// 	int str111 = toupper('a');
//     int str112 = ft_toupper('a');
//     printf("library: %c\n", str111);
//     printf("zisaku : %c\n", str112);
// 	return (0);
// }