/*
** EPITECH PROJECT, 2019
** get
** File description:
** board
*/

#include "include/my.h"

char    **get_updated_board_2(char *buf)
{
    char        **map = get_board();
    char        **coord = string_to_double_array(buf);
    int         pos_y = coord[0][3] - '0' - 1;
    int         pos_x = letter_to_number(coord[0][2]);

    if (map == NULL)
        return NULL;
    if (map[pos_y][pos_x] == '.')
        map[pos_y][pos_x] = coord[0][0];
    else
        return NULL;
    pos_y = coord[0][6] - '0' - 1;
    pos_x = letter_to_number(coord[0][5]);
    if (map[pos_y][pos_x] == '.')
        map[pos_y][pos_x] = coord[0][0];
    else
        return NULL;
    return map;
}

char    **get_updated_board_3(char *buf)
{
    char        **map = get_updated_board_2(buf);
    char        **coord = string_to_double_array(buf);
    int         pos_y = coord[1][3] - '0' - 1;
    int         pos_x = letter_to_number(coord[1][2]);

    if (map == NULL)
        return NULL;
    if (coord[1][3] == coord[1][6]) {
        if (help_board_3(map, coord, pos_y, pos_x) == NULL)
            return NULL;
        else
            return map;
    } else {
        if (help_board_3s(map, coord, pos_y, pos_x) == NULL)
            return NULL;
        else
            return map;
    }
}

char    **get_updated_board_4(char *buf)
{
    char        **map = get_updated_board_3(buf);
    char        **coord = string_to_double_array(buf);
    int         pos_y = coord[2][3] - '0' - 1;
    int         pos_x = letter_to_number(coord[2][2]);

    if (map == NULL)
        return NULL;
    if (coord[2][3] == coord[2][6]) {
        if (help_board_4(map, coord, pos_y, pos_x) == NULL)
            return NULL;
        else
            return map;
    } else {
        if (help_board_4s(map, coord, pos_y, pos_x) == NULL)
            return NULL;
        else
            return map;
    }
}

char    **get_updated_board_5(char *buf)
{
    char        **map = get_updated_board_4(buf);
    char        **coord = string_to_double_array(buf);
    int         pos_y = coord[3][3] - '0' - 1;
    int         pos_x = letter_to_number(coord[3][2]);

    if (map == NULL)
        return NULL;
    if (coord[3][3] == coord[3][6]) {
        if (help_board_5(map, coord, pos_y, pos_x) == NULL)
            return NULL;
        else
            return map;
    } else {
        if (help_board_5s(map, coord, pos_y, pos_x) == NULL)
            return NULL;
        else
            return map;
    }
}

char    **get_board(void)
{
    char        **board = mem_alloc_2d_array(8, 17);
    char        *str = "|. . . . . . . .\0";
    int i = 0;
    int k = 0;
    int j = 0;
    char *beg;

    for (int b = 1; b < 9; b++) {
        beg = my_itoa(b);
        board[i][k] = beg[0];
        k++;
        for (; str[j] != '\0'; j++, k++)
            board[i][k] = str[j];
        board[i][++k] = '\0';
        j = 0;
        k = 0;
        i++;
    }
    return board;
}
