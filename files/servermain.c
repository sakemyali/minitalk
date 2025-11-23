/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servermain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 18:17:11 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/23 19:00:06 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	return (0);
}

int	main(void)
{
	ft_printf("Server's PID is: %d\n", getpid());
	return (EXIT_SUCCESS);
}
