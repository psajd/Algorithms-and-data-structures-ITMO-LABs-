#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    node *head = NULL;

    FILE * fin = fopen("postfix.in", "r");
    FILE * fout = fopen("postfix.out", "w");
    int temp;
    char str[10000];
    while(fscanf(fin, "%s", str) != EOF) {
        if (strcmp(str, "+") == 0) {
            temp = head->value + head->next->value;
            pop(&head);
            pop(&head);
            push(&head, temp);
        }
        else if (strcmp(str, "*") == 0) {
            temp = head->value * head->next->value;
            pop(&head);
            pop(&head);
            push(&head, temp);
        }
        else if (strcmp(str, "-") == 0) {
            temp = head->next->value - head->value;
            pop(&head);
            pop(&head);
            push(&head, temp);
        }
        else
            push(&head, atoi(str));
    }
    fprintf(fout, "%d", pop(&head));
}