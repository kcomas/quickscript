
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    enum {
        TOKEN_WORD,
        TOKEN_INTEGER,
        TOKEN_STRING,
        TOKEN_TYPE_INT,
        TOKEN_FN,
        TOKEN_RETURN,
        TOKEN_IF,
        TOKEN_ELIF,
        TOKEN_ELSE,
        TOKEN_EXPORT,
        TOKEN_LBRACE,
        TOKEN_RBRACE,
        TOKEN_LBRACKET,
        TOKEN_RBRACKET,
        TOKEN_COLON,
        TOKEN_ASSIGN,
        TOKEN_LESSTHAN_EQUAL,
        TOKEN_COMMA,
        TOKEN_PERIOD
    } type;
    union {
        struct {
            size_t len;
            char* start;
        } value;
        int64_t integer;
    } data;
} token;

typedef struct {
    size_t cur_idx, line_no, char_no, len;
    char str[];
} token_state;

token_state *tokenize_file(const char *path);
