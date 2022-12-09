#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *first = NULL;

//create nodes
void create(int A[], int n) {
    int i;
    struct Node *last, *tmp;
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    
    last = first;
    
    for(i=1; i<n; i++) {
        tmp = (struct Node *)malloc(sizeof(struct Node));
        tmp->data = A[i];
        tmp->next = NULL;
        
        last->next = tmp;
        last = tmp;
    }
}


//displaying function
void Display(struct Node *p) {
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

//counting length of Node
int Count(struct Node *p) {
    int count = 0;
    while (p) {
        count++;
        p = p->next;
    }
    return count;
}

//inserting function
void Insert(struct Node *p, int pos, int val) {
    struct Node *tmp, *newnode;
    tmp = first;
    
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;
    
    if(pos < 0 || pos > Count(p))
        return;
    
    if(pos == 0) {    //if it is an Empty list
        newnode->next = first;
        first = newnode;
    }
    else {
        for(int i=0; i<pos-1; i++) {
            tmp = tmp->next;
        }
        newnode->next = tmp->next;
        tmp->next = newnode;
    }
}

int main() {
    
//    int A[] = {34,2,31};
//    int len = (sizeof(A)/sizeof(int));
//
//    printf("hello\n\n");
//    create(A, len);
  
    Insert(first, 0, 6);
    Insert(first, 1, 7);
    Insert(first, 2, 8);
    Insert(first, 0, 5);
//    printf("\n\nLength of Node in linked list: %d \n\n", Count(first));
    Display(first);
    return 0;
}
