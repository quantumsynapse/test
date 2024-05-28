#include "lexer.h"
#include "parser.h"
#include "code_generator.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *input = "3 4 + 2 * 7 /";
    int token_count;
    Token **tokens = tokenize(input, &token_count);
    ASTNode *ast = parse(tokens, token_count);
    generate_code(ast);

    for (int i = 0; i < token_count; i++) {
        destroy_token(tokens[i]);
    }
    free(tokens);
    destroy_ast_node(ast);

    return 0;
}
