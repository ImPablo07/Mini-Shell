# Parser

Parser przetwarza tokeny wygenerowane przez lexer.

Przykład:

echo hello

Tokeny:

WORD(echo)
WORD(hello)

Wynik:

Command {
    argv = ["echo", "hello"]
}
