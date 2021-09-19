/*
** EPITECH PROJECT, 2019
** Project
** File description:
** Epitech 2018
*/

#include "include/my.h"

int	global = 0;

void	my_function(int sig, siginfo_t *inf, void *v)
{
    if (sig == SIGUSR1)
        global = global + 1;
}

void	connection(void)
{
     struct sigaction sa;

     sa.sa_sigaction = my_function;
     sa.sa_flags = SA_SIGINFO;
     sigaction(SIGUSR1, &sa, NULL);
     while (!global);
}

void	connect_player_1(void)
{
    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putchar('\n');
    my_putstr("waiting for enemy connection...\n\n");
    connection();
    if (global == 1)
        my_putstr("enemy connected\n\n");
}

int	connect_player_2(int pid)
{
    int x = 0;

    x = kill(pid, SIGUSR1);
    return x;
}
