#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int cq[MAX];
int frontc = -1, rearc = -1;
int isFull(){
    return (frontc == (rearc+1)%MAX);
}
int isEmpty(){
    return (frontc == -1);
}
void enqueue(int val){
    if(isFull()){
        printf("Queue overflow\n");
        return;
    }
    if(isEmpty()) frontc = 0;
    rearc = (rearc + 1) % MAX;
    cq[rearc] = val;
    printf("%d enqueued\n", val);
}
void dequeuec(){
    if(isEmpty()){
        printf("Queue empty\n");
        return;
    }
    int val = cq[frontc];
    if(frontc == rearc){
        frontc = rearc = -1;
    } else {
        frontc = (frontc + 1) % MAX;
    }
    printf("%d dequeued\n", val);
}
void displayc(){
    if(isEmpty()){
        printf("Queue empty\n");
        return;
    }
    int i = frontc;
    while(1){
        printf("%d ", cq[i]);
        if(i == rearc) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main(){
    int ch, val;
    do{
        printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        if(scanf("%d",&ch)!=1) return 0;
        switch(ch){
            case 1: printf("Enter value: "); if(scanf("%d",&val)!=1) return 0; enqueue(val); break;
            case 2: dequeuec(); break;
            case 3: displayc(); break;
            case 4: break;
            default: printf("Invalid choice\n");
        }
    }while(ch!=4);
    return 0;
}

