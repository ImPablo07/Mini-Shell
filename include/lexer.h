#ifndef LEXER_H
# define LEXER_H

/**
 * @enum e_token_type
 * @brief Typ tokenu zwróconego przez lexer.
 */
typedef enum e_token_type
{
    TOKEN_WORD,
    TOKEN_PIPE,
    TOKEN_REDIR_IN,
    TOKEN_REDIR_OUT
} t_token_type;

/**
 * @struct s_token
 * @brief Reprezentuje pojedynczy token.
 *
 * Tokeny tworzą listę jednokierunkową
 * przekazywaną później do parsera.
 */
typedef struct s_token
{
    t_token_type    type;
    char            *value;
    struct s_token  *next;
} t_token;

/**
 * @brief Tokenizuje linię wejściową użytkownika.
 *
 * Zamienia tekst wpisany przez użytkownika
 * na listę tokenów.
 *
 * Przykład:
 *
 * echo "hello world"
 *
 * =>
 *
 * TOKEN_WORD("echo")
 * TOKEN_WORD("hello world")
 *
 * @param line Linia wejściowa.
 * @return Początek listy tokenów.
 */
t_token *tokenize(char *line);

/**
 * @brief Zwalnia pamięć listy tokenów.
 *
 * @param tokens Lista tokenów.
 */
void free_tokens(t_token *tokens);

#endif
