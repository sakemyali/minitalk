/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servermain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvrm <mvrm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:17:11 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/28 13:10:54 by mvrm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	static int bit;
	static char c;

	if (SIGUSR1 == sig)
		
}

int	main(void)
{
	ft_printf("Server's PID is: %d\n", getpid());
	s_signal(SIGUSR1, handler, true);
	s_signal(SIGUSR2, handler, true);
	while (1337)
		pause();
	return (EXIT_SUCCESS);
}
