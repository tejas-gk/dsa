#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// help me i regret my decision to do this
struct node{
    int coeff, expox, expoy, expoz;
    struct node *next;
};
typedef struct node *NODE;

NODE createnode(int, int, int, int);
NODE createheadnode();
void insert_rear(NODE, int, int, int, int);
void createpoly(NODE poly);
void display(NODE poly);
double evaluate(NODE poly, int x, int y, int z);
NODE polyadd(NODE poly1, NODE poly2);

NODE createnode(
    int coeff, int expox, int expoy, int expoz
){
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->coeff = coeff;
    temp->expox = expox;
    temp->expoy = expoy;
    temp->expoz = expoz;
    temp->next = NULL;
    return temp;
}

NODE createheadnode(){
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->coeff = 0;
    temp->expox = -1;
    temp->expoy = -1;
    temp->expoz = -1;
    temp->next = NULL;
    return temp;
}

void insert_rear(
    NODE head, int coeff, int expox, int expoy, int expoz
){
    NODE temp, cur;
    temp = createnode(coeff, expox, expoy, expoz);
    if(head->link==head)
        head->link=temp;
    else{
        cur=head;
        while(cur->link!=head)
            cur=cur->link;
        temp->link = head;
        head->coeff=(head->coeff)+1;
    }
}

void createpoly(NODE poly){
    int i, n, coeff, ex, ey, ez;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n;i++){
        printf("enter coeff");
        scanf("%d", &coeff);
        printf("enter x y and z");
        scanf("%d%d%d", &ex, &ey, &ez);
        insert_rear(coeff, ex, ey, ez,poly);
    }
}

void display(NODE head){
    NODE cur;
    if(head->link==head)
        printf("list is empty");
    else {
        cur = head->link;
        while(cur!=head){
            if(cur->coeff<0)
                printf("%dx^%dy^%dz^%d", cur->coeff, cur->expox, cur->expoy, cur->expoz);
            cur = cur->link;
        }

    }
}

double evaluate(
    int x,int y,int z,NODE head
){
    double result = 0;
    NODE cur;
    if(head->link==head){
        printf("list is empty");
        return 0;
    }
    else{
        cur = head->link;
        while(cur!=head){
            result += cur->coeff * pow(x, cur->expox) * pow(y, cur->expoy) * pow(z, cur->expoz);
            cur = cur->link;
        }
        return result;
    }
}

NODE polyadd(NODE a,NODE b){
    NODE c,starta,startb;
    int sum = 0;
    starta = a->link;
    startb = b->link;
    c=createheadnode();
    while((a!=starta)&&(b!=startb)){
        if((a->expox==b->expox)&&(a->expoy==b->expoy)&&(a->expoz==b->expoz)){
            sum = a->coeff + b->coeff;
            insert_rear(c, sum, a->expox, a->expoy, a->expoz);
            a = a->link;
            b = b->link;
        }else if((a->expox==b->expox)&&(a->expoy==b->expoy)){
            // insert_rear(c, a->coeff, a->expox, a->expoy, a->expoz);
            a = a->link;
        else if((a->expox==b->expox)&&(a->expoz==b->expoz)&&(a->expoz>b->expoz)){
            insert_rear(c, a->coeff, a->expox, a->expoy, a->expoz);
            a = a->link;
        }
        else{
            insert_rear(c, b->coeff, b->expox, b->expoy, b->expoz);
            b = b->link;
        }
           
    }
    while(a!=starta){
        insert_rear(c, a->coeff, a->expox, a->expoy, a->expoz);
        a = a->link;
    }
}

void main(){
    NODE poly1, poly2, poly3;
    int x, y, z;
    poly1 = createheadnode();
    poly2 = createheadnode();
    printf("Enter the first polynomial: ");
    createpoly(poly1);
    printf("Enter the second polynomial: ");
    createpoly(poly2);
    printf("The first polynomial is: ");
    display(poly1);
    printf("The second polynomial is: ");
    display(poly2);
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of y: ");
    scanf("%d", &y);
    printf("Enter the value of z: ");
    scanf("%d", &z);
    printf("The value of the first polynomial is: %f \n", evaluate(poly1, x, y, z));
    printf("The value of the second polynomial is: %f \n", evaluate(poly2, x, y, z));
    poly3 = polyadd(poly1, poly2);
    printf("The sum of the two polynomials is: ");
    display(poly3);
}