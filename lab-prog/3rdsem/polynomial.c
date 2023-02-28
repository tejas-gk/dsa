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
    cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = temp;
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