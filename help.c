/*
** EPITECH PROJECT, 2019
** dash-h
** File description:
** help
*/

#include "include/my.h"

char    *help_board_5s(char **map, char **coord, int pos_y, int pos_x)
{
    for (unsigned int i = 0; i < 5; pos_y += 1, i++) {
        if (map[pos_y][pos_x] == '.')
            map[pos_y][pos_x] = coord[3][0];
        else
            return NULL;
    }
}

void	print_help(void)
{
    my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n\tfirst_player_pid: only for the 2nd player");
    my_putstr(". pid of the first player.\n\tnavy_postions: file repres");
    my_putstr("enting the positions of the ships.\n");
}

void	my_print_array(char **arr)
{
    int i = 0;

    while (arr[i]) {
        my_putstr(arr[i]);
        my_putchar('\n');
        i++;
    }
}

char	**mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int i = 0;
    char **arr = NULL;

    arr = malloc(sizeof(char *) * (nb_rows + 1));
    arr[i] = malloc(sizeof(char) * nb_cols + 1);
    while (i < nb_rows) {
        arr[i] = malloc(sizeof(char) * nb_cols + 1);
        i++;
    }
    arr[i] = NULL;
    return (arr);
}

int     find_num_string(char *str, char a)
{
    int nr_of_char = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == a)
            nr_of_char++;
        i++;
    }
    return nr_of_char;
}
