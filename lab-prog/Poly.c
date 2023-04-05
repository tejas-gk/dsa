#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int coef,expox,expoy,expoz;
    struct node*link;
};

typedef struct node* NODE;

NODE createnode(int coef,int ex,int ey,int ez){
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    temp->coef=coef;
    temp->expox=ex;
    temp->expoy=ey;
    temp->expoz=ez;
    temp->link=NULL;
    return temp;
}
NODE createheadnode(){
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    temp->coef=0;
    temp->expox=-1;
    temp->expoy=-1;
    temp->expoz=-1;
    temp->link=temp;
    return temp;
}

void insert_rear(int coef,int ex,int ey,int ez,NODE head){
    NODE cur,temp;
    temp=createnode(coef,ex,ey,ez);
    if(head->link==head){
        head->link=temp;
    }else{
        cur=head;
        while(cur->link!=head){
            cur=cur->link;
        }cur->link=temp;
    }temp->link=head;
     head->coef=(head->coef)+1;
}
void createpoly(NODE poly){
   int n,coef,ex,ey,ez;
   printf("Enter the number of terms\n");
   scanf("%d",&n);
   for(int i=0;i<n;i++){
    printf("Enter the coeff\n");
    scanf("%d",&coef);
    printf("Enter the exponenets(x,y,z):\n");
    scanf("%d%d%d",&ex,&ey,&ez);
    insert_rear(coef,ex,ey,ez,poly);
   }
}
void disp(NODE head){
   NODE cur;
   if(head->link==head){
    printf("List is empty\n");
   }else{
    cur=head->link;
    while(cur!=head){
        if(cur->coef<0){
            printf("%dx^%dy^%dz^%d",cur->coef,cur->expox,cur->expoy,cur->expoz);
        }else{
            printf("+ %dx^%dy^%dz^%d",cur->coef,cur->expox,cur->expoy,cur->expoz);
        }
        cur=cur->link;
    }printf("The number of the terms is %d\n",head->coef);
   }
}
double evaluate(int ex,int ey,int ez,NODE head){
    double result=0;
    NODE cur;
    if(head->link==head){
        printf("List is empty\n");
    }else{
       cur=head->link;
       while(cur!=head){
        result+=cur->coef*pow(ex,cur->expox)*pow(ey,cur->expoy)*pow(ez,cur->expoz);
        cur=cur->link;
       }
    }return result;
}
NODE polyadd(NODE a,NODE b){
     NODE starta;
     int sum=0;
     NODE startb;
     starta=a;
     startb=b;
     a=a->link;
     b=b->link;
     NODE c;
     c=createheadnode();
     while(a!=starta && b!=startb){
        if((a->expox == b->expox)&&(a->expoy == b->expoy) && (a->expoz==b->expoz)){
            sum=a->coef+b->coef;
            insert_rear(sum,a->expox,a->expoy,a->expoz,c);
            a=a->link;
            b=b->link;
        }else if(a->expox > b->expox){
            insert_rear(a->coef,a->expox,a->expoy,a->expoz,c);
            a=a->link;
        }
        else if((a->expox == b->expox)&&(a->expoy > b->expoy)){
            insert_rear(a->coef,a->expox,a->expoy,a->expoz,c);
            a=a->link;
        }
        else if((a->expox == b->expox)&&(a->expoy == b->expoy) && (a->expoz>b->expoz)){
            insert_rear(a->coef,a->expox,a->expoy,a->expoz,c);
            a=a->link;
        }else{
             insert_rear(b->coef,b->expox,b->expoy,b->expoz,c);
            b=b->link;
        }
     }
     while(a!=starta){
         insert_rear(a->coef,a->expox,a->expoy,a->expoz,c);
            a=a->link;
     }
     while(b!=startb){
          insert_rear(b->coef,b->expox,b->expoy,b->expoz,c);
            b=b->link;
     }
     return c;
}

void main(){
    int x,y,z,n;
    double eval=0;
    NODE poly1=NULL;
    NODE poly2=NULL;
    NODE polysum=NULL;
    printf("-----------------Evaluation of polynomial-----------------\n");
    poly1=createheadnode();
    createpoly(poly1);
    printf("Polnomial is\n");
    disp(poly1);
   printf("\nEnter the value of x,y and z\n");
   scanf("%d%d%d",&x,&y,&z);
   eval=evaluate(x,y,z,poly1); 
   printf("The total number of terms is %.2f\n",eval);
   printf("-------------------Addition of two polynomials----------------\n");
   poly1=NULL;
   poly1=createheadnode();
   createpoly(poly1);
   printf("Polynomial1 is\n");
   disp(poly1);
   poly2=createheadnode();
   createpoly(poly2);
   printf("Polynomial2 is\n");
   disp(poly2);
   polysum=polyadd(poly1,poly2);
   printf("Sum of the polynomial is\n");
   disp(polysum);
}
