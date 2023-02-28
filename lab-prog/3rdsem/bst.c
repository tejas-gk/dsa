#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char name[20],phno[10];
    struct node *leftchild,*rightchild;
};
typedef struct node *NODE;
int delflag=0;
NODE createnode();
void insertBST(Node root,NODE newnode);
int searchBST(NODE root,char key[]);
NODE getrightmin(NODE root);
NODE delete(NODE root,char key[]);
void inorder(NODE root);
void preorder(NODE root);
void postorder(NODE root);
void main(){
    NODE root=NULL,newnode;
    int ch;
    char key[20];
    for(;;){
        printf("1.Insert 2.Search 3.Delete 4.Inorder 5.Preorder 6.Postorder 7.Exit \n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: newnode=createnode();
                    if(root==NULL)
                        root=newnode;
                    else
                        insertBST(root,newnode);
                    break;
            case 2: printf("Enter the key to be searched: ");
                    scanf("%s",key);
                    if(searchBST(root,key))
                        printf("Key found \n");
                    else
                        printf("Key not found \n");
                    break;
            case 3: printf("Enter the key to be deleted: ");
                    scanf("%s",key);
                    root=delete(root,key);
                    if(delflag)
                        printf("Key deleted \n");
                    else
                        printf("Key not found \n");
                    break;
            case 4: inorder(root);
                    break;
            case 5: preorder(root);
                    break;
            case 6: postorder(root);
                    break;
            case 7: exit(0);
            default: printf("Invalid choice \n");
        }
    }
}
