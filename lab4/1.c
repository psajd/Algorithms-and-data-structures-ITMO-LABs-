#include <stdlib.h>
#include <stdio.h>
typedef struct node{
    int value;
    struct node* next;
}node;

void push(node** head, int data){
    node* tmp = malloc(sizeof(node));
    tmp->value = data;
    tmp->next = *head;
    (*head) = tmp;
}

int pop(node** head){
    if (*head == NULL){
        printf("Error: list is empty");
        exit(-1);
    }
    int res = (**head).value;
    *head = (*head)->next;
    return res;
}

int main(){
    node *head = NULL;

    FILE * fin = fopen("stack.in", "r");
    FILE * fout = fopen("stack.out", "w");

    int n;
    char command[2];
    int temp;
    fscanf(fin, "%d", &n);


    for (long long i = 0; i < n; i++){
        fscanf(fin, "%s", command);
        if (command[0] == '+'){
            fscanf(fin, "%d", &temp);
            push(&head, temp);
        }
        if (command[0] == '-')
            fprintf(fout, "%d\n", pop(&head));
    }

    return 0;
}