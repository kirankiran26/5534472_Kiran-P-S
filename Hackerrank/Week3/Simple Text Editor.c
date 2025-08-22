#include <stdio.h>
#define MAX 1000000

typedef struct{
    int type;
    char *data;
} Operation;

int main() {
    int Q;
    scanf("%d", &Q);

    char text[MAX] = "";
    Operation stack[Q];
    int top = -1;
    while (Q--){
        int t;
        scanf("%d", &t);

        if (t == 1){
            char s[MAX];
            scanf("%s", s);
            strcat(text, s);

            stack[++top].type = 1;
            stack[top].data = strdup(s);

        } else if (t == 2){
            int k;
            scanf("%d", &k);
            int len = strlen(text);

            char *deleted = (char*)malloc((k+1) * sizeof(char));
            strcpy(deleted, text + len - k);
            text[len - k] = '\0';

            stack[++top].type = 2;
            stack[top].data = deleted;

        } else if (t == 3){
            int k;
            scanf("%d", &k);
            printf("%c\n", text[k-1]);

        } else if (t == 4){
            if (top >= 0){
                Operation op = stack[top--];
                if (op.type == 1){
                    int len = strlen(text);
                    int d = strlen(op.data);
                    text[len - d] = '\0';
                } else if (op.type == 2){
                    strcat(text, op.data);
                }
                free(op.data);
            }
        }
    }   
    return 0;
}