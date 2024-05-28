#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_NUMBER,
    TOKEN_OPERATOR
} TokenType;

typedef struct {
    TokenType type;
    char *text;
} Token;

Token *create_token(TokenType type, const char *text);
void destroy_token(Token *token);
Token **tokenize(const char *input, int *token_count);

#endif // LEXER_H
