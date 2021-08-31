//preprocessing part
#include <stdio.h>
#include <stdlib.h>
//A struct of nodes
struct node 
{
    int data;
    struct node *next;
} *front, *rear;
 // create queue
void create()
{
    front = rear = NULL;
}
//get size of queuw
 int queueSize()
{
    struct node *temp = front;
    int count = 0;     
    if(front == NULL && rear == NULL)
        return 0;
    while(temp != rear){
        count++;
        temp = temp->next;
    }
    if(temp == rear)
        count++;
    return count;
}
//front function
 int getFront()
{
    return front->data;
}
//Rear function
 int getRear()
{
    return rear->data;
}
//check queue is empty.
 void isEmpty()
{
    if (front == NULL && rear == NULL)
        printf("\t    Empty \n");
    else
        printf("\tnot Empty\n");
}
//enqueue function
void enqueue(int num) 
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;
     
    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}
//dequeue function
void dequeue()
{
    struct node *temp;
    if (front == NULL) {
        return;
    } else {
        temp = front;
        front = front->next;
        if(front == NULL){
            rear = NULL;
        }
        printf("Element deleted : %d\n", temp->data);
        free(temp);
    }
}
// see elements
void displayqueue() 
{
    struct node *temp = front;
  
    if ((front == NULL) && (rear == NULL)) {
        printf("\tQueue is Empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
        if(temp != NULL)
            printf(", ");
    }
}
int main() {
    create();
    enqueue(2);
    enqueue(3);
    enqueue(10);
    enqueue(2);
    enqueue(0);
    enqueue(0);
    enqueue(0);
    displayqueue();
    printf("\n\tSize of Queue : %d\n", queueSize());
    printf("Front index : %d\n", getFront());
    printf("Rear index : %d\n", getRear());
    dequeue();
    dequeue();
    dequeue();
    dequeue();    
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    isEmpty();
    printf("\tSize of Queue : %d", queueSize());
    return 0;
}

