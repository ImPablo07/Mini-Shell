/******************************************************************************
 * @file lexer.c
 * @author Paweł Czarny
 * @brief Implementacja analizatora leksykalnego MiniShell.
 *
 * Lexer odpowiada za:
 * - rozpoznawanie słów,
 * - rozpoznawanie operatora pipe,
 * - obsługę pojedynczych cudzysłowów,
 * - obsługę podwójnych cudzysłowów,
 * - budowanie listy tokenów.
 ******************************************************************************/

#include <stdlib.h>

#include "lexer.h"
#include "utils.h"

/**
 * @brief Pomija białe znaki.
 *
 * @param str Analizowany ciąg znaków.
 * @param i Aktualna pozycja analizatora.
 */
static void skip_spaces(char *str, int *i)
{
    while (str[*i] == ' ' || str[*i] == '\t')
        (*i)++;
}

/**
 * @brief Tworzy nowy token.
 *
 * @param type Typ tokenu.
 * @param value Wartość tokenu.
 * @return Wskaźnik do nowego tokenu lub NULL.
 */
static t_token *create_token(t_token_type type, char *value)
{
    t_token *token;

    token = malloc(sizeof(t_token));
    if (!token)
        return (NULL);

    token->type = type;
    token->value = value;
    token->next = NULL;

    return (token);
}

/**
 * @brief Dodaje token na koniec listy.
 *
 * @param tokens Początek listy.
 * @param new_token Token do dodania.
 */
static void add_token(t_token **tokens, t_token *new_token)
{
    t_token *current;

    if (!*tokens)
    {
        *tokens = new_token;
        return ;
    }

    current = *tokens;

    while (current->next)
        current = current->next;

    current->next = new_token;
}

/**
 * @brief Pobiera zawartość pojedynczego cudzysłowu.
 *
 * Przykład:
 * 'hello world'
 *
 * @param line Linia wejściowa.
 * @param i Aktualna pozycja analizatora.
 * @return Wyodrębniony tekst.
 */
static char *extract_single_quote(char *line, int *i)
{
    int start;

    (*i)++;
    start = *i;

    while (line[*i] && line[*i] != '\'')
        (*i)++;

    return (ft_substr(line, start, *i - start));
}

/**
 * @brief Pobiera zawartość podwójnego cudzysłowu.
 *
 * Przykład:
 * "hello world"
 *
 * @param line Linia wejściowa.
 * @param i Aktualna pozycja analizatora.
 * @return Wyodrębniony tekst.
 */
static char *extract_double_quote(char *line, int *i)
{
    int start;

    (*i)++;
    start = *i;

    while (line[*i] && line[*i] != '"')
        (*i)++;

    return (ft_substr(line, start, *i - start));
}

/**
 * @brief Pobiera zwykłe słowo.
 *
 * Czyta znaki aż do:
 * - spacji,
 * - tabulatora,
 * - pipe,
 * - pojedynczego cudzysłowu,
 * - podwójnego cudzysłowu.
 *
 * @param line Linia wejściowa.
 * @param i Aktualna pozycja analizatora.
 * @return Wyodrębnione słowo.
 */
static char *extract_word(char *line, int *i)
{
    int start;

    start = *i;

    while (line[*i]
        && line[*i] != ' '
        && line[*i] != '\t'
        && line[*i] != '|'
        && line[*i] != '\''
        && line[*i] != '"')
    {
        (*i)++;
    }

    return (ft_substr(line, start, *i - start));
}

/**
 * @brief Tokenizuje linię wejściową.
 *
 * Zamienia tekst wpisany przez użytkownika
 * na listę tokenów.
 *
 * @param line Linia wejściowa.
 * @return Lista tokenów.
 */
t_token *tokenize(char *line)
{
    t_token *tokens;
    char    *value;
    int      i;

    tokens = NULL;
    i = 0;

    while (line[i])
    {
        skip_spaces(line, &i);

        if (!line[i])
            break ;

        if (line[i] == '|')
        {
            add_token(
                &tokens,
                create_token(TOKEN_PIPE, ft_strdup("|"))
            );
            i++;
        }
        else if (line[i] == '\'')
        {
            value = extract_single_quote(line, &i);

            if (line[i] == '\'')
                i++;

            add_token(
                &tokens,
                create_token(TOKEN_WORD, value)
            );
        }
        else if (line[i] == '"')
        {
            value = extract_double_quote(line, &i);

            if (line[i] == '"')
                i++;

            add_token(
                &tokens,
                create_token(TOKEN_WORD, value)
            );
        }
        else
        {
            value = extract_word(line, &i);

            add_token(
                &tokens,
                create_token(TOKEN_WORD, value)
            );
        }
    }

    return (tokens);
}

/**
 * @brief Zwalnia pamięć listy tokenów.
 *
 * @param tokens Lista tokenów.
 */
void free_tokens(t_token *tokens)
{
    t_token *next;

    while (tokens)
    {
        next = tokens->next;

        free(tokens->value);
        free(tokens);

        tokens = next;
    }
}
