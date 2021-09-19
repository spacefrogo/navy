/*
** EPITECH PROJECT, 2018
** my
** File description:
** header file
*/

#ifndef _MY_H_
#define _MY_H_

#include <grp.h>
#include <pwd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <stddef.h>
#include <stdlib.h>
#include <signal.h>
#include <assert.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

char    *help_board_3(char **, char **, int, int);
char    *help_board_3s(char **, char **, int, int);
char    *help_board_4(char **, char **, int, int);
char    *help_board_4s(char **, char **, int, int);
char    *help_board_5(char **, char **, int, int);
char    *help_board_5s(char **, char **, int, int);
void	my_putchar(char const);
void	my_put_nbr(int);
int	my_putstr(char const *);
int	my_strlen(char const *);
int	my_count_digits(int);
int	my_strcmp(char const *, char const *);
char	*my_itoa(int);
char	*my_revstr(char *);
char	*my_strdup(char const *);
char	*my_strcat(char *, char const *);
char	*my_strcpy(char *, char const *);
static 	int	my_count_digits_rec(int, int);
void	my_print_array(char **);
int	my_getnbr(char *);
int	my_str_isnum(char const *);
char	**mem_alloc_2d_array(int, int);
int	run_game(int);
char	**get_board(void);
int	my_strcmp(char const *, char const *);
void	print_help(void);
int	find_num_string(char *, char);
char	*check_file(int);
int	check_coordinates(char *);
char	**string_to_double_array(char *);
int	letter_to_number(char);
int	check_coordinates_2(char *);
char	**get_updated_board_5(char *);
int	my_atoi(char *);
void	connection(void);
void	connect_player_1(void);
int	connect_player_2(int);

#endif /* _MY_H_ */
