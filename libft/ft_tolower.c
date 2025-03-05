/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:10:05 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/29 16:53:03 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}

// int main()
// {
// 	int str113 = tolower('A');
//     int str114 = ft_tolower('A');
//     printf("library: %c\n", str113);
//     printf("zisaku : %c\n", str114);
// 	return (0);
// }