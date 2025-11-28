/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:18:25 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/28 14:28:00 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	server = 0;

static void	start_handler(int sig)
{
	server = 1;
}

static void	end_handler(int sig)
{
	ft_printf("\n Received.\n");
	exit(EXIT_SUCCESS);
}

static void	s_send(char c, pid_t pid)
{
	int bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (c & (0x80 >> bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		while (server == 0)
			usleep(42);
		server = 0;
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
	s_signal(SIGUSR1, start_handler, false);
	s_signal(SIGUSR2, end_handler, false);
	while (*content)
		s_send(*content++, server);
	s_send('\0', server);
	return (EXIT_SUCCESS);
}
