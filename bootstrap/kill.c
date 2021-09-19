/*
** EPITECH PROJECT, 2019
** projec
** File description:
** test
*/

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int	main(int ac, char **av)
{
    pid_t x = atoi(av[1]);

    kill(x, SIGQUIT);
    return (0);
}
