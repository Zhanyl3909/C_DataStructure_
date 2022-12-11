#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
}*first = NULL;

//Create function
void create(int *A, int n) {
    int i;
    struct Node *tmp, *last;
    
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = first->prev = NULL;
    
    last = first;
    
    for(i=1; i<n; i++) {
        tmp = (struct Node*)malloc(sizeof(struct Node));
        tmp->data = A[i];
        tmp->next = last->next;
        tmp->prev = last;
        
        last->next = tmp;
        last = tmp;
    }
}


//Finding length of Double Linked List
int Length(struct Node *p) {
    int count = 0;
    while (p) {
        count++;
        p = p->next;
    }
    return count;
}

//Displaying function
void Display(struct Node *p) {
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n\n");
}

int main() {
    int A[] = {10,20,30,40};
    int len = (sizeof(A)/sizeof(int));
    
    create(A,len);
    Display(first);
    printf("The Length of Doubly Linked List: %d\n", Length(first));
    
    return 0;
}
