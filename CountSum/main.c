#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *first = NULL;

void create(int A[], int n) {
    int i;
    struct Node *tmp, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    
    last = first;
    
    for(i=1; i<n; i++) {
        tmp = (struct Node*)malloc(sizeof(struct Node));
        tmp->data = A[i];
        tmp->next = NULL;
        
        last->next = tmp;
        last = tmp;
    }
}


//couting Length of LL iteratively
int countNode(struct Node *p){
    int count = 0;
    while(p!=NULL) {
        count++;
        p = p->next;
    }
    return count;
}

//counting Length of LL Recursively
int RecCountNode(struct Node *p) {
    if(p!= NULL) return RecCountNode(p->next) +1 ;
    else {
        return 0;
    }
}

//finding Sum of all nodes in LL iteratively
int SumOfNodes(struct Node *p) {
    int sum = 0;
    while(p) {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

//finding Sum of all nodes Recursively
int RecSumOfNodes(struct Node *p) {
    if(p == NULL) return 0;
    else{
        return RecSumOfNodes(p->next) + p->data;
    }
}


int main() {
    
    int A[] = {34,4,2,7,5,37,90,2,3};
    int len = sizeof(A)/sizeof(int);
    printf("hello\n\n");
    create(A, len);
    printf("The length of LL is %d \n", RecCountNode(first));
    printf("The sum of all nodes in LL is %d\n\n", RecSumOfNodes(first));
    
    return 0;
}
