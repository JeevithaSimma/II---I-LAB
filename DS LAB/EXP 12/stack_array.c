#include<stdio.h>
#include<stdlib.h>

int isempty();
int isfull();
void push(int);
void pop();
void traversal();

#define max_size 5
int stack[5],top;

int main(){
        int want_continue,choice,data;
        top = stack[0];
        printf("enter 1.push ; 2.pop ; 3.traversal\n");
        do{
                printf("enter your choice: ");
                scanf("%d",&choice);
                isempty();
                isfull();
                switch(choice){
                        case 1: printf("enter the value: ");
                                scanf("%d",&data);
                                push(data);
                                break;
                        
                        case 2: pop();
                                break;
                                
                        case 3: traversal();
                                break;
                }
                printf("want to continue enter 1 : ");
                scanf("%d",&want_continue);
        }while(want_continue == 1);
        return 0;
}

int isempty(){
        return top<0;
}
int isfull(){
        return top == max_size -1;
}
void push(int data){
        if(isfull() == 1){
                printf("overflow\n");
                return;
        }
        stack[top] = data;
        top += 1;      
}
void pop(){
        if(isempty() == -1){
                printf("underflown\n");
                return;
        }
        top = top -1;
}

void traversal(){
        int i;
        for(i = 0;i<top;i++){
                printf("%d\t",stack[i]);
        }
}


