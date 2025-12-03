/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:18:25 by mosakura          #+#    #+#             */
/*   Updated: 2025/12/04 01:29:30 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_server = 0;

static void	start_handler(int sig)
{
	(void)sig;
	g_server = 1;
}

static void	end_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "Success signal received from server.\n", 37);
	exit(EXIT_SUCCESS);
}

static void	s_send(char c, pid_t pid)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (c & (0x80 >> bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		while (g_server == 0)
			usleep(42);
		g_server = 0;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server;
	char	*content;

	if (argc != 3)
	{
		write(STDOUT_FILENO, "Error: Invalid format.\n\nUsage: ./client\
			<server_pid> <message>\n", 73);
		exit(EXIT_FAILURE);
	}
	server = ft_atoi(argv[1]);
	if (server <= 0)
	{
		write(STDOUT_FILENO, "Invalid PID.\n", 13);
		exit(EXIT_FAILURE);
	}
	content = argv[2];
	s_signal(SIGUSR1, start_handler, false);
	s_signal(SIGUSR2, end_handler, false);
	while (*content)
		s_send(*content++, server);
	s_send('\0', server);
	return (EXIT_SUCCESS);
}
