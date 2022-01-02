#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iso646.h>

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

node* getSecondLast(node*head){
    if (head == NULL)
        exit(-2);

    if (head->next == NULL)
        return NULL;

    while (head->next->next)
        head = head->next;

    return head;
}

int popBack(node** head) {
    int res = 0;
    node *sLast = NULL;
    if (!head || !(*head))
        exit(-1);
    sLast = getSecondLast(*head);

    if (sLast == NULL){
        res = (*head)->value;
        free(*head);
        *head = NULL;
    }else{
        res = sLast->next->value;
        free(sLast->next);
        sLast->next = NULL;
    }
    return res;
}

int main(){


    FILE * fin = fopen("brackets.in", "r");
    FILE * fout = fopen("brackets.out", "w");

    char str[11000];
    while (fscanf(fin, "%s", str) != EOF){
        node *head = NULL;
        push(&head, 0);
        for (int i = 0; str[i] != '\0'; i++){
            if ((str[i] == ')' and head->value == '(') or (str[i] == ']' and head->value == '['))
            pop(&head);
            else
            push(&head, str[i]);
        }
        if (head->value == 0)
            fprintf(fout, "YES\n");
        else
            fprintf(fout, "NO\n");
    }
}