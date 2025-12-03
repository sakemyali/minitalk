/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:17:11 by mosakura          #+#    #+#             */
/*   Updated: 2025/12/04 01:24:38 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static int		bit;
	static char		c;
	static pid_t	server;

	(void)ucontext;
	if (info->si_pid)
		server = info->si_pid;
	if (SIGUSR1 == sig)
		c |= (0x80 >> bit);
	else if (SIGUSR2 == sig)
		c &= ~(0x80 >> bit);
	bit++;
	if (CHAR_BIT == bit)
	{
		bit = 0;
		if ('\0' == c)
		{
			k_kill(server, SIGUSR2, 1);
			c = 0;
			return ;
		}
		write(STDOUT_FILENO, &c, 1);
		c = 0;
	}
	k_kill(server, SIGUSR1, 0);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		write(STDOUT_FILENO, "Error: Invalid format.\n\nUsage: ./server\n", 40);
		return (EXIT_FAILURE);
	}
	ft_printf("Server's PID is: %d\n", getpid());
	s_signal(SIGUSR1, handler, true);
	s_signal(SIGUSR2, handler, true);
	while (1337)
		pause();
	return (EXIT_SUCCESS);
}
