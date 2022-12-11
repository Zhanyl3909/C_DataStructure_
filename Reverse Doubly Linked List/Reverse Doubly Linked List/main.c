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

//Inserting to Doubly Linked List
void Insert(struct Node *p, int pos, int x) {  //where x is data of newnode
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = x;
    
    if(pos < 0 || Length(first) < pos) return;
    
    if(pos == 0) {  //insert to beginning
        newnode->next = p;
        newnode->prev = NULL;
        p->prev = newnode;
        p = newnode;
        
    } else {     //inserting into a certain position
        for(int i=0; i<pos-1; i++) {
            p = p->next;
        }
        newnode->next = p->next;
        newnode->prev = p;
        if(newnode->next) p->next->prev = newnode;
        p->next = newnode;
    }
}

//Deleting Function
int Delete(struct Node *p, int pos) {
    struct Node *tmp;
    int x = -1;
    if(pos < 1 || Length(first) < pos) return x;
    if(pos == 1) {  //deleting from the beginning
        tmp = p;
        x = tmp->data;
        p = p->next;
        p->prev = NULL;
        free(tmp);
    } else {         //deleting from a certain position
        tmp = p;
        for(int i=0; i<pos-1; i++) {
            tmp = tmp->next;
        }
        x = tmp->data;
        tmp->prev->next = tmp->next;
        if(tmp->next) tmp->next->prev = tmp->prev;
    }
    return x;
}


//Reversing function
void Reverse(struct Node *p) {
    struct Node *tmp;
    tmp = p;
    
    while (p) {
        tmp = p->next;
        p->next = p->prev;
        p->prev = tmp;
        p = p->prev;
        if(p!=NULL && p->next == NULL) first = p;
        
    }
}

int main() {
    int A[] = {10,20,30,40};
    int len = (sizeof(A)/sizeof(int));
    create(A,len);
    
    Reverse(first);
   Display(first);
//    printf("Deleted %d \n",Delete(first, 1) );
//    Display(first);
    
    return 0;
}


