/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 19:00:31 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/28 14:41:34 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void s_signal(int signo, void *handler, bool use_siginfo)
{
    struct sigaction sa = {0};

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
        ft_printf("sigaction fail.");
        exit(EXIT_FAILURE);
    }
}

void    k_kill(__pid_t pid, int signum)
{
    if (kill(pid, signum) < 0)
    {
        ft_printf("Transmission failure.");
        exit(EXIT_FAILURE);
    }
}

void



//0b10000000
