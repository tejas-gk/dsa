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

NODE createnode(){
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    printf("Enter the name: ");
    scanf("%s",newnode->name);
    printf("Enter the phone number: ");
    scanf("%s",newnode->phno);
    newnode->leftchild=NULL;
    newnode->rightchild=NULL;
    return newnode;
}

void insertBST(NODE root,NODE newnode){
    if(strcmp(newnode->name,root->name)<0){
        if(root->leftchild==NULL)
            root->leftchild=newnode;
        else
            insertBST(root->leftchild,newnode);
    }
    if(strcmp(newnode->name,root->name)>0){
        if(root->rightchild==NULL)
            root->rightchild=newnode;
        else
            insertBST(root->rightchild,newnode);
    }
}

int searchBST(NODE root,char key[]){
    if(root==NULL)
        return 0;
    if(strcmp(key,root->name)==0)
        return 1;
    if(strcmp(key,root->name)<0)
        return searchBST(root->leftchild,key);
    else
        return searchBST(root->rightchild,key);
}

NODE getrightmin(NODE root){
    if(root->leftchild==NULL)
        return root;
    else
        return getrightmin(root->leftchild);
}

NODE delete(NODE root,char key[]){
    NODE temp;
    if(root==NULL){
        delflag=0;
        return root;
    }
    if(strcmp(key,root->name)<0)
        root->leftchild=delete(root->leftchild,key);
    else if(strcmp(key,root->name)>0)
        root->rightchild=delete(root->rightchild,key);
    else{
        delflag=1;
        if(root->leftchild==NULL){
            temp=root->rightchild;
            free(root);
            return temp;
        }
        else if(root->rightchild==NULL){
            temp=root->leftchild;
            free(root);
            return temp;
        }
        else{
            temp=getrightmin(root->rightchild);
            strcpy(root->name,temp->name);
            strcpy(root->phno,temp->phno);
            root->rightchild=delete(root->rightchild,temp->name);
        }
    }
    return root;
}

void preorder(NODE root){
    if(root!=NULL){
        printf("%s %s \t",root->name,root->phno);
        preorder(root->leftchild);
        preorder(root->rightchild);
    }
}

void inorder(NODE root){
    inorder(root->leftchild);
    printf("%s %s \t",root->name,root->phno);
    inorder(root->rightchild);
}

void postorder(NODE root){
    postorder(root->leftchild);
    postorder(root->rightchild);
    printf("%s %s \t",root->name,root->phno);
}

void insertBST(NODE root,NODE newnode){
    if(strcmp(newnode->name,root->name)<0){
        if(root->leftchild==NULL)
            root->leftchild=newnode;
        else
            insertBST(root->leftchild,newnode);
    }
    if(strcmp(newnode->name,root->name)>0){
        if(root->rightchild==NULL)
            root->rightchild=newnode;
        else
            insertBST(root->rightchild,newnode);
    }
}
