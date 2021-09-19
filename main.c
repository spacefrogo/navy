/*
** EPITECH PROJECT, 2019
** hello
** File description:
** there
*/

#include "include/my.h"

char	*get_attack_position(void)
{
    char	*buf;

    while (1) {
        my_putstr("attack: ");
        buf = malloc(sizeof(char) * 1024);
        read(0, buf, 1024);
        if (my_strlen(buf) == 3 && buf[0] >= 'A' && buf[0] <= 'H' \
            && buf[1] >= '1' && buf[1] <= '8' && buf[2] == '\n') {
            return buf;
        } else if (buf != NULL) {
            my_putstr("wrong position\n");
            free(buf);
        }
    }
    return NULL;
}

int	run_game(int fd)
{
    char	*buf;
    char	**map;

    if (fd == -1)
        return (84);
    buf = check_file(fd);
    if (buf == NULL)
        return (84);
    map = get_updated_board_5(buf);
    if (map == NULL)
        return (84);
    my_putstr("my positions:\n |A B C D E F G H\n-+---------------\n");
    my_print_array(map);
    my_putstr("\nenemy's positions:\n |A B C D E F G H\n-+---------------\n");
    my_print_array(get_board());
    my_putchar('\n');
    return (0);
}

int	player_two(char **av)
{
    if (my_str_isnum(av[1]) == 0 || open(av[2], O_RDONLY) == -1)
        return (84);
    if (connect_player_2(my_atoi(av[1])) == -1)
        return (84);
    else {
        my_putstr("my pid: ");
        my_put_nbr(getpid());
        my_putchar('\n');
        my_putstr("successfully connected\n\n");
    }
    return run_game(open(av[2], O_RDONLY));
}

int	player_one(char **av)
{
    int ret = 0;

    if (my_strcmp(av[1], "-h") == 0 && my_strlen(av[1]) == 2) {
        print_help();
        return (0);
    }
    if (open(av[1], O_RDONLY) == -1)
        return (84);
    connect_player_1();
    ret = run_game(open(av[1], O_RDONLY));
    if (ret == 84)
        return (84);
    else {
        get_attack_position();
        return (0);
    }
}

int	main(int ac, char **av)
{
    if (ac < 2 && ac > 3)
        return (84);
    if (ac == 3) {
        if (player_two(av) == 84)
            return (84);
        else
            return (0);
    }
    if (ac == 2) {
        if (player_one(av) == 84)
            return (84);
        else
            return (0);
    }
}
