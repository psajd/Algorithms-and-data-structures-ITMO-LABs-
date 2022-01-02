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

    FILE * fin = fopen("queue.in", "r");
    FILE * fout = fopen("queue.out", "w");

    int n;
    char command[2];
    int temp;
    fscanf(fin, "%d", &n);

    for (int i = 0; i < n; i++){
        fscanf(fin, "%s", command);
        if (command[0] == '+'){
            fscanf(fin, "%d", &temp);
            push(&head, temp);
        }
        if (command[0] == '-')
            fprintf(fout, "%d\n", popBack(&head));
    }
    return 0;
}