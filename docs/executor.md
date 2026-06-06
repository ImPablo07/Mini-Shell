# Executor Module
## Cel modułu

Moduł Executor odpowiada za wykonywanie poleceń przygotowanych przez Parser.

Jego zadania obejmują:

- wykonywanie poleceń zewnętrznych,
- wykonywanie poleceń wbudowanych (builtins),
- obsługę procesów potomnych,
- obsługę przekierowań wejścia i wyjścia,
- obsługę pipe'ów,
- zarządzanie kodami zakończenia procesów.

## Architektura

Przepływ wykonywania poleceń

Input
↓
Lexer
↓
Parser
↓
Executor
├── Builtins
├── External Commands
├── Redirections
└── Pipes

## Struktura danych

typedef struct s_command
{
    char **argv;
    int argc;

    char *input_file;
    char *output_file;

    int append;

    struct s_command *next;
} t_command;

Opis pól:

Pole	Opis
argv	argumenty polecenia
argc	liczba argumentów
input_file	plik dla <
output_file	plik dla > lub >>
append	tryb dopisywania
next	następne polecenie w pipe

## Wykonywanie poleceń zewnętrznych
