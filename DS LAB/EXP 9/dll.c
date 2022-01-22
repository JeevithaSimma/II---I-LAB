#include <stdio.h>
#include <stdlib.h>
struct node{
       int data;
       struct node *next;
       struct node *prev;
};
void insert(struct node**,int,int);
void delete(struct node**,int);
void traversal(struct node*);
struct node *search(struct node*,int);
void middle(struct node *head);

int main(){
    int choice,want_continue,pos,data,key;
    printf("enter choice 1.insert,2.delete,3.traversal,4.search,5.middle\n");
    struct node *head = NULL,*r;
    do{
         printf("enter choice:\n");
         scanf("%d",&choice);
         switch(choice){
                     case 1:printf("enter value and position:");
                            scanf("%d%d",&data,&pos);
                            insert(&head,data,pos);
                            break;
                     case 2:printf("enter position to delete:\n");
                            scanf("%d",&pos);
                            delete(&head,pos);
                            break;
                     case 3:traversal(head);
                            break;
                     case 4:printf("enter the key\n");
                            scanf("%d",&key);
                            r = search(head,key);
                            if(r == NULL)
                            printf("not found\n");
                            else
                            printf("successful\n");
                            break;
                     case 5:
                           middle(head);
                     
                     }
                     printf("want to continue,enter 1:");
                     scanf("%d",&want_continue);
                     }
                     while(want_continue == 1);
         return 0;
}
void insert(struct node **head,int data,int pos){
     struct node *p,*temp;
     int k = 1;
     temp = (struct node*)malloc(sizeof(struct node));
     temp -> data = data;
     p = *head;
     if(pos == 1){
                temp -> next = *head;
                temp -> prev = NULL;
                if(*head){
                      (*head)->prev = temp;
                }
                *head = temp;
     }
     else{
            while((k < pos-1) && (p -> next != NULL)){
                             p = p -> next;
                             k++;
            }
            if(k!=pos-1){
                  printf("position doesn't exist\n");
                  return;
            }
            temp -> next = p -> next;
            temp ->prev = p;
            if(p -> next)
                   p ->next ->prev = temp;
                   p ->next = temp;
      }
  }
void delete(struct node **head,int pos){
     struct node *p,*q;
     int k = 1;
     p = *head;
     if(pos == 1){
          *head = (*head) -> next;
           if(*head)
              (*head) -> prev = NULL;
              free(p);
         }
     else{
         while((k<pos) && (p -> next != NULL)){
                     p = p -> next;
                     k++;
          }
          if(k!=pos){
                  printf("position doesn't exist\n");
                  return;
          }
          
               q = p -> prev;
               q -> next = p -> next;
               if(p -> next)
                   p -> next -> prev = q;
               free(p);
          
      }
 }
void traversal(struct node *head){
     struct node *p;
     p = head;
     while(p!=NULL){
          printf("%d\t",p -> data);
          p = p -> next;
      }
 }
struct node *search(struct node *head,int key){
     struct node *p;
     p = head;
     while(p!=NULL){
          if(p -> data == key){
                 return p;
           }
           p = p -> next;
     }
     return NULL;
}     
void middle(struct node *head){
     struct node *p,*q;
     p = head;
     q = head;
     if(head!=NULL){
        while((p != NULL) && ((p->next)!= NULL)){
        p = p->next->next;
        q = q->next;
        }
        printf("%d\n",q->data);
        }
        }      

	
			
