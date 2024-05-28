#include "lexer.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Token *create_token(TokenType type, const char *text) {
    Token *token = (Token *)malloc(sizeof(Token));
    token->type = type;
    token->text = strdup(text);
    return token;
}

void destroy_token(Token *token) {
    if (token) {
        free(token->text);
        free(token);
    }
}

Token **tokenize(const char *input, int *token_count) {
    int length = strlen(input);
    Token **tokens = (Token **)malloc(length * sizeof(Token *));
    *token_count = 0;

    for (int i = 0; i < length; i++) {
        if (isspace(input[i])) {
            continue;
        } else if (isdigit(input[i])) {
            char buffer[16];
            int j = 0;
            while (isdigit(input[i])) {
                buffer[j++] = input[i++];
            }
            buffer[j] = '\0';
            tokens[(*token_count)++] = create_token(TOKEN_NUMBER, buffer);
            i--;
        } else {
            char buffer[2] = {input[i], '\0'};
            tokens[(*token_count)++] = create_token(TOKEN_OPERATOR, buffer);
        }
    }

    return tokens;
}
