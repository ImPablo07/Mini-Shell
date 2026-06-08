#ifndef PARSER_H
# define PARSER_H

# include "lexer.h"

/**
 * @struct s_command
 * @brief Reprezentuje pojedyncze polecenie.
 */
typedef struct s_command
{
    char                **argv;
    int                 argc;

    struct s_command    *next;
} t_command;

/**
 * @brief Parsuje tokeny do listy poleceń.
 *
 * @param tokens Lista tokenów.
 * @return Lista poleceń.
 */
t_command    *parse_tokens(t_token *tokens);

/**
 * @brief Zwalnia pamięć listy poleceń.
 *
 * @param commands Lista poleceń.
 */
void free_commands(t_command *commands);

/**
 * @brief Funkcja debugująca.
 *
 * @param commands Lista poleceń.
 */
void print_commands(t_command *commands);

#endif
