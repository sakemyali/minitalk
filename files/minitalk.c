/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 19:00:31 by mosakura          #+#    #+#             */
/*   Updated: 2025/12/04 01:28:15 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	s_signal(int signo, void *handler, bool use_siginfo)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	if (use_siginfo)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
	}
	else
		sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(signo, &sa, NULL) < 0)
	{
		write(STDOUT_FILENO, "Signal handler setup failure.\n", 38);
		exit(EXIT_FAILURE);
	}
}

void	k_kill(pid_t pid, int signum, int n)
{
	if (n == 1)
		write(STDOUT_FILENO, "\n", 1);
	if (kill(pid, signum) < 0)
	{
		write(STDOUT_FILENO, "Transmission failure.\n", 24);
		exit(EXIT_FAILURE);
	}
}
