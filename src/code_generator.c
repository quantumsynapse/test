#include "code_generator.h"
#include <stdio.h>

void generate_code(ASTNode *node) {
    if (node->type == AST_NUMBER) {
        printf("mov ax, %s\n", node->text);
    } else if (node->type == AST_OPERATOR) {
        generate_code(node->left);
        printf("push ax\n");
        generate_code(node->right);
        printf("pop bx\n");
        if (node->text[0] == '+') {
            printf("add ax, bx\n");
        } else if (node->text[0] == '-') {
            printf("sub ax, bx\n");
        } else if (node->text[0] == '*') {
            printf("mul bx\n");
        } else if (node->text[0] == '/') {
            printf("div bx\n");
        }
    }
}
