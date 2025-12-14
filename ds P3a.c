#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
void insert(int val){
    if(rear == MAX-1){
        printf("Queue overflow\n");
        return;
    }
    if(front == -1) front = 0;
    queue[++rear] = val;
    printf("%d inserted\n", val);
}
void deleteq(){
    if(front == -1 || front > rear){
        printf("Queue empty\n");
        front = rear = -1;
        return;
    }
    int val = queue[front++];
    if(front > rear) front = rear = -1;
    printf("%d deleted\n", val);
}
void display(){
    if(front == -1){
        printf("Queue empty\n");
        return;
    }
    for(int i = front; i <= rear; i++) printf("%d ", queue[i]);
    printf("\n");
}
int main(){
    int ch, val;
    do{
        printf("1.Insert 2.Delete 3.Display 4.Exit\n");
        if(scanf("%d",&ch)!=1) return 0;
        switch(ch){
            case 1: printf("Enter value: "); if(scanf("%d",&val)!=1) return 0; insert(val); break;
            case 2: deleteq(); break;
            case 3: display(); break;
            case 4: break;
            default: printf("Invalid choice\n");
        }
    }while(ch!=4);
    return 0;
}

