//  main.c
//  isSortedLinkedList
//
//  Created by Dzholchieva Zhanylai on 2022/12/11.
//
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *first = NULL,*second = NULL, *third = NULL;

//create function
void Create(int A[], int n) {
    struct Node *last, *tmp;
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    
    last = first;
    
    for(int i=1; i<n; i++) {
        tmp = (struct Node *)malloc(sizeof(struct Node));
        tmp->data = A[i];
        tmp->next = NULL;
        
        last->next = tmp;
        last = tmp;
    }
}
void Create2(int A[], int n) {
    struct Node *last, *tmp;
    
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    
    last = second;
    
    for(int i=1; i<n; i++) {
        tmp = (struct Node *)malloc(sizeof(struct Node));
        tmp->data = A[i];
        tmp->next = NULL;
        
        last->next = tmp;
        last = tmp;
    }
}


//display function
void Display(struct Node *p) {
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n\n");
}

//count fucntion
int Count(struct Node *p) {
    int count = 0;
    while(p) {
        count++;
        p = p->next;
    }
    return count;
}

//Concationtion function
void Conacationation(struct Node *p, struct Node *q) {  //first and second lists
   
    third = p; //third will start from first
    while (p->next!= NULL)
        p = p->next;
          p->next = q;
}
  


int main() {
    
    int A[] = {10,20,20,20,20,30,40,50};
    int len = (sizeof(A)/sizeof(int));
    Create(A, len);
    
    int B[] = {1,2,3,4,5,6,7,8};
    int Blen = (sizeof(B)/sizeof(int));
    Create2(B, Blen);
    
    Conacationation(first, second);
    printf("Concatinated: \n");
    Display(third);
    

    
    return 0;
}
