#include<stdio.h>
#include<stdlib.h>

struct node{
        int data;
        struct node *next;
};

void push(struct node** ,int);
int pop(struct node**);
void traversal(struct node *);


int main(){
        int want_continue,choice,data;
        struct node *top = NULL;
        printf("enter 1.push;2.pop;3.traversal\n");
        do{
                printf("enter your choice: ");
                scanf("%d",&choice);
                switch(choice){
                        case 1: printf("enter the value: ");
                                scanf("%d",&data);
                                push(&top,data);
                                break;
                        case 2: data = pop(&top);
                                printf("poped item: %d",data);
                                break;
                        case 3: traversal(top);
                                break;
               }
               printf("if you want to continue enter 1: ");
               scanf("%d",&want_continue);
        }while(want_continue == 1);
                return 0;
}


void push(struct node **top,int data){
        struct node *temp;
        
        temp = (struct node*)malloc(sizeof(struct node));
        temp -> data = data;
      
        temp -> next = *top;
        (*top) = temp;        
}

int pop(struct node **top){
        struct node *temp;
        int data;
        temp = *top;
        if(*top == NULL){
                printf("underflow\n");
                exit(0);
        }
        else{
                temp = *top;
                data = temp -> data;
                (*top)= (*top) -> next;
                temp -> next = NULL;
                free(temp);
                return data;
        }
}

void traversal(struct node *top){
        struct node *temp;
        temp = top;
        while(temp != NULL){
                printf("%d\t",temp -> data);
                temp = temp -> next;
        }
}











