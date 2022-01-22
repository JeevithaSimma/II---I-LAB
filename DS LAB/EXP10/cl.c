#include <stdio.h>
#include <stdlib.h>
struct node{
       int data;
       struct node *next;
};
void insert_beg(struct node **,int);
void insert_pos(struct node **,int,int);
void insert_end(struct node **,int);
void delete_beg(struct node **);
void delete_end(struct node **);
void delete_pos(struct node **,int);
void traversal(struct node *);
struct node *search(struct node *,int);
int main(){
    int choice,want_continue,pos,data,key;
    printf("enter choice 1.insert_beg,2.insert_pos,3.insert_end,4.delete_beg,5.delete_end,6.delete_pos,7.traversal,8.search\n");
    struct node *head = NULL,*r;
    do{
       printf("enter your choice:\n");
       scanf("%d",&choice);
       switch(choice){
               case 1:printf("enter the value at beg:");
                      scanf("%d",&data);
                      insert_beg(&head,data);
                      break;
               case 2:printf("enter value and position:");
                      scanf("%d%d",&data,&pos);
                      insert_pos(&head,data,pos);
                      break;
               case 3:printf("enter value at end:");
                      scanf("%d",&data);
                      insert_end(&head,data);
                      break;
               case 4:delete_beg(&head);
                      break;
               case 5:delete_end(&head);
                      break;
               case 6:printf("enter position to be deleted:");
                      scanf("%d",&pos);
                      delete_pos(&head,pos);
                      break;
               case 7:traversal(head);
                      break;
               case 8:printf("enter the key:\n");
                      scanf("%d",&key);
                      r = search(head,key);
                      if(r==NULL){
                             printf("not successful\n");
                       }
                       else{
                             printf("successful\n");
                       }
                       break;
           }
           printf("want to continue,enter 1:");
           scanf("%d",&want_continue);
      }
      while(want_continue == 1);
      return 0;
}
void insert_beg(struct node **head,int data){
     struct node *p,*temp;
     temp = (struct node *)malloc(sizeof(struct node));
     temp -> data = data;
     p = *head;
     if(*head == NULL){
           temp->next = temp;
           *head = temp;
      }
      else{
           while(p -> next != *head){
               p = p->next;
           }
           temp -> next = *head;
           p -> next = temp;
           *head = temp;
      }
}
void insert_pos(struct node **head,int data,int pos){
     struct node *p,*q,*temp;
     int k =1;
     temp = (struct node *)malloc(sizeof(struct node));
     temp -> data = data;
     p = *head;
     while(k<pos){
           q = p;
           p = p -> next;
           k++;
     }
     q -> next = temp;
     temp -> next = p;
}
void insert_end(struct node **head,int data){
     struct node *p,*temp;
     temp = (struct node *)malloc(sizeof(struct node));
     temp -> data = data;
     p = *head;
     if(*head == NULL){
         temp -> next = temp;
         *head = temp;
      }
      else{
         while(p -> next != *head){
                p = p->next;
          }
          p -> next = temp;
          temp -> next = *head;
       }
}
void delete_beg(struct node **head){
     struct node *p = *head,*q;
     if(*head == NULL){
             printf("empty cell\n");
             return;
      }
      if((*head) -> next == *head){
                 *head = NULL;
                  free(p);
      }
      else{
           q = p;
           while(p -> next != *head){
                       p = p->next;
           }
           *head = (*head) -> next;
           p -> next = *head;
           free(q);
      }
}
void delete_end(struct node **head){
     struct node *p = *head,*q;
     if(head == NULL){
              printf("empty cell\n");
              return;
      }
      if((*head)-> next == *head){
              *head = NULL;
               free(p);
      }
      else{
          while(p -> next != *head){
                   q = p;
                   p = p -> next;
           }
           q -> next = *head;
           free(p);
       }
}
void delete_pos(struct node **head,int pos){
     struct node *p,*q;
     int k =1;
     p = *head;
     while(k <  pos){
             q = p;
             p = p -> next;
             k++;
    }
    q -> next = p-> next;
    free(p);
}
void traversal(struct node *head){
     struct node *p;
     p = head;
     do{
        printf("%d\t",p -> data);
        p = p -> next;
     }
     while(p != head);
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
      
               

     
               

