#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    s->data[++(s->top)] = value;
}

int pop(Stack* s) {
    return s->data[(s->top)--];
}

int peek(Stack* s) {
    return s->data[s->top];
}

int main() {
    Stack s1, s2;
    init(&s1);
    init(&s2);

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int x;
            scanf("%d", &x);
            push(&s1, x);
        } else if (type == 2) {
            if (isEmpty(&s2)) {
                while (!isEmpty(&s1)) {
                    push(&s2, pop(&s1));
                }
            }
            pop(&s2);
        } else if (type == 3) {
            if (isEmpty(&s2)) {
                while (!isEmpty(&s1)) {
                    push(&s2, pop(&s1));
                }
            }
            printf("%d\n", peek(&s2));
        }
    }

    return 0;
}
