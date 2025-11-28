/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvrm <mvrm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:18:25 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/28 13:10:55 by mvrm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	s_send(char c, pid_t pid)
{
	int bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (c & (0b1000000 >> bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
	}
	
}

int	main(int argc, char *argv[])
{
	pid_t	server;
	char	*content;

	if (argc != 3) 
	{
		ft_printf("Wrong usage.");
		exit(EXIT_FAILURE);
	}
	server = ft_atoi(argv[1]);
	content = argv[2];
	while (*content)
		s_send(*content, server);
	s_send('\0', server);
	return (EXIT_SUCCESS);
}
