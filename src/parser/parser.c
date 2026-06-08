/******************************************************************************
 * @file parser.c
 * @author Paweł Czarny
 * @brief Implementacja parsera MiniShell.
 *
 * Parser zamienia listę tokenów wygenerowaną przez lexer
 * na listę poleceń wykorzystywaną później przez executor.
 ******************************************************************************/

#include <stdlib.h>

#include "parser.h"
#include "utils.h"

/**
 * @brief Liczy argumenty dla pojedynczego polecenia.
 *
 * Funkcja analizuje tokeny do momentu napotkania
 * operatora pipe lub końca listy.
 *
 * @param tokens Początek analizowanej listy tokenów.
 * @return Liczba argumentów.
 */
static int count_args(t_token *tokens)
{
    int count;

    count = 0;

    while (tokens && tokens->type != TOKEN_PIPE)
    {
        if (tokens->type == TOKEN_WORD)
            count++;

        tokens = tokens->next;
    }

    return (count);
}

/**
 * @brief Tworzy nową strukturę polecenia.
 *
 * @return Wskaźnik do nowego polecenia lub NULL.
 */
static t_command *create_command(void)
{
    t_command *cmd;

    cmd = malloc(sizeof(t_command));
    if (!cmd)
        return (NULL);

    cmd->argv = NULL;
    cmd->argc = 0;
    cmd->next = NULL;

    return (cmd);
}

/**
 * @brief Wypełnia tablicę argv polecenia.
 *
 * @param cmd Polecenie do uzupełnienia.
 * @param tokens Tokeny należące do polecenia.
 */
static void fill_argv(t_command *cmd, t_token *tokens)
{
    int i;

    i = 0;

    while (tokens && tokens->type != TOKEN_PIPE)
    {
        if (tokens->type == TOKEN_WORD)
        {
            cmd->argv[i] = ft_strdup(tokens->value);
            i++;
        }

        tokens = tokens->next;
    }

    cmd->argv[i] = NULL;
}

/**
 * @brief Parsuje tokeny do listy poleceń.
 *
 * @param tokens Lista tokenów wygenerowana przez lexer.
 * @return Lista poleceń.
 */
t_command *parse_tokens(t_token *tokens)
{
    t_command *head;
    t_command *current;
    t_command *new_cmd;

    head = NULL;
    current = NULL;

    while (tokens)
    {
        new_cmd = create_command();
        if (!new_cmd)
            return (NULL);

        new_cmd->argc = count_args(tokens);

        new_cmd->argv = malloc(
            sizeof(char *) * (new_cmd->argc + 1)
        );

        if (!new_cmd->argv)
            return (NULL);

        fill_argv(new_cmd, tokens);

        if (!head)
            head = new_cmd;
        else
            current->next = new_cmd;

        current = new_cmd;

        while (tokens && tokens->type != TOKEN_PIPE)
            tokens = tokens->next;

        if (tokens)
            tokens = tokens->next;
    }

    return (head);
}
