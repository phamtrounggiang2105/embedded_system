/*Duyet argv tu 1 den argc-1:

    Neu la so:
        push vao stack

    Neu la toan tu:
        pop op2
        pop op1
        tinh op1 op op2
        push ket qua

Cuoi cung:
    in pop()
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSTACK 100

// Stack luu cac gia tri
double stack[MAXSTACK];
int top = 0;


// Ham push
void push(double val) {
    if (top < MAXSTACK) {
        stack[top++] = val;
    } else {
        printf("Stack day!\n");
    }
}


// Ham pop
double pop() {
    if (top > 0) {
        return stack[--top];
    } else {
        printf("Stack rong!\n");
        return 0.0;
    }
}


// Kiem tra chuoi co phai la so khong
int is_number(char *s) {
    int i = 0;

    // Bo qua dau am
    if (s[0] == '-') i++;

    for (; s[i]; i++) {
        if (!isdigit(s[i]) && s[i] != '.') {
            return 0;
        }
    }
    return 1;
}


int main(int argc, char *argv[]) {

    // Duyet tung argument
    for (int i = 1; i < argc; i++) {

        // Neu la so thi dua vao stack
        if (is_number(argv[i])) {
            push(atof(argv[i]));
        }

        // Neu la toan tu
        else {
            double op2 = pop();
            double op1 = pop();

            switch (argv[i][0]) {

                case '+':
                    push(op1 + op2);
                    break;

                case '-':
                    push(op1 - op2);
                    break;

                case '*':
                    push(op1 * op2);
                    break;

                case '/':
                    if (op2 != 0)
                        push(op1 / op2);
                    else
                        printf("Loi chia cho 0!\n");
                    break;

                default:
                    printf("Toan tu khong hop le: %s\n", argv[i]);
            }
        }
    }

    // In ket qua cuoi cung
    printf("Ket qua = %.2f\n", pop());

    return 0;
}