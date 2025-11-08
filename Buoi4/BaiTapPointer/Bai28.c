//28	Triển khai linked list cơ bản bằng con trỏ.
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void printList(struct Node* head){
    struct Node* temp = head;
    
    printf("Printing list...\n");
    
    while (temp != NULL){
        printf("%d;\n", temp->data);
        temp = temp->next;
    }
    printf("Print finished\n");
};

void freeList(struct Node* head){
    struct Node* current = head;
    struct Node* temp;
    
    while (current != NULL){
        temp = current->next;
        free(current);
        current = temp;
    }
    printf("Free successful\n");
};



int main(){
    struct Node* head = NULL;
    struct Node* node2 = NULL;
    struct Node* node3 = NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    node2 = (struct Node*)malloc(sizeof(struct Node));
    node3 = (struct Node*)malloc(sizeof(struct Node));

    head->data=10;
    node2->data=20;
    node3->data=30;
    
    head->next=node2;
    node2->next=node3;
    node3->next=NULL;
    
    printList(head);
    freeList(head);
    return 0;
}
