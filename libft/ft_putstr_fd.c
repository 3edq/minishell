/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enkwak <enkwak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:56:57 by enkwak            #+#    #+#             */
/*   Updated: 2024/10/25 18:03:08 by enkwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

// int main()
// {
//     char *test_strings[] = {
//         "Hello, World!",
//         "This is a test.",
//         "ft_putstr_fd works!",
//         "Goodbye!\n",
//         NULL
//     };
//     for (size_t i = 0; test_strings[i] != NULL; i++)
//     {
//         ft_putstr_fd(test_strings[i], 1);
//     }
//     return 0;
// }