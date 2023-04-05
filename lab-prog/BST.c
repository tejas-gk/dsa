#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char name[20],phno[20];
    struct node* leftchild;
    struct node* rightchild;
};
int delflag;
typedef struct node* NODE;

NODE createnode(){
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    printf("Enter your name\n");
    scanf("%s",temp->name);
    printf("Enter your phno\n");
    scanf("%s",temp->phno);
    temp->leftchild=NULL;
    temp->rightchild=NULL;
    return temp;
}

void insertBST(NODE root,NODE newNode){
    if(strcmp(newNode->name,root->name)==0){
        printf("Key already exists\n");
        return;
    }else if(strcmp(newNode->name,root->name)<0){ // if newnode is less than root
        if(root->leftchild==NULL){ // then  if leftchild is null then insert
            root->leftchild=newNode;
        }else{
            insertBST(root->leftchild,newNode);
        }
    }
    else if(strcmp(newNode->name,root->name)>0){
        if(root->rightchild==NULL){
            root->rightchild=newNode;
        }else{
            insertBST(root->rightchild,newNode);
        }
    }
}

int search(NODE root,char keyname[]){
     if(!root){
        return -1;
     }
     if(strcmp(keyname,root->name)==0){
         return 1;
     }else if(strcmp(keyname,root->name)<0){
        return search(root->leftchild,keyname);
     }else{
         return search(root->rightchild,keyname);
     }   
}

NODE getRightMin(NODE root){
    NODE temp=root;
    while(temp->leftchild!=NULL){
        temp=temp->leftchild;
    }return temp;
}
NODE deleteBST(NODE root,char keyname[]){
    if(!root){
        delflag=-1;
        return NULL;
    }
    if(strcmp(keyname,root->name)<0){
        root->leftchild=deleteBST(root->leftchild,keyname);
    }else if(strcmp(keyname,root->name)>0){
        root->rightchild=deleteBST(root->rightchild,keyname);
    }else{
        if(root->leftchild==NULL && root->rightchild==NULL){
            free(root);
            return NULL;
        }
        else if(root->leftchild==NULL){
            NODE temp=root->rightchild;
            free(root);
            return temp;
        }else if(root->rightchild==NULL){
            NODE temp=root->leftchild;
            free(root);
            return temp;
        }else{
            NODE rightmin=getRightMin(root->rightchild);
            strcpy(root->name,rightmin->name);
            strcpy(root->phno,rightmin->phno);
            root->rightchild=deleteBST(root->rightchild,rightmin->name);
        }
    }return root;
}

void preorder(NODE temp){
    if(temp!=NULL){
        printf("|%s|%s|\t",temp->name,temp->phno);
        preorder(temp->leftchild);
        preorder(temp->rightchild);
    }
}
void inorder(NODE temp){
    if(temp!=NULL){
        preorder(temp->leftchild);
        printf("|%s|%s|\t",temp->name,temp->phno);
        preorder(temp->rightchild);
    }
}
void postorder(NODE temp){
    if(temp!=NULL){
        preorder(temp->leftchild);
        preorder(temp->rightchild);
        printf("|%s|%s|\t",temp->name,temp->phno);
    }
}

void main(){
    int n,keyFound=0,choice;
    char keychoice[25];
    NODE root=NULL,newNode;
    printf("Enter the total number of records\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
       newNode=createnode();
       if(root==NULL){
        root=newNode;
       }else{
        insertBST(root,newNode);
       }
    }
    while(1){
      choice=0;
      printf("----------------MENU-------------------------\n");
      printf("1. Search\n");
      printf("2. Insert\n");
      printf("3. delete\n");
      printf("4. traverse\n");
      printf("5. Exit\n");
      printf("----------------------------------------------\n");
      printf("Enter choice\n");
      scanf("%d",&choice);
      switch (choice)
      {
         case 1:printf("Enter the name to be searched\n");
                scanf("%s",keychoice);
                keyFound=search(root,keychoice);
                if(keyFound==1){
                    printf("Name :%s is found in the BST\n",keychoice);
                }else{
                     printf("Name :%s is not found in the BST\n",keychoice);
                }
                break;
         case 2:newNode=createnode();
                if(root==NULL){
                    root=newNode;
                }else{
                    insertBST(root,newNode);
                }
                break;
         case 3:if(root==NULL){
                printf("Tree is empty\n");
                }else{
                   delflag=0;
                   printf("Enter the name to be deleted\n");
                   scanf("%s",keychoice);
                   root=deleteBST(root,keychoice);
                   if(delflag==-1){
                    printf("Name %s is not found in the BST\n",keychoice);
                   }else{
                    printf("Name %s is deleted from the BST\n",keychoice);
                   }
                }break;
          case 4: if(root==NULL){
                 printf("Tree is empty\n");
                  }else{
                    printf("BST Preorder Travesal\n");
                    preorder(root);
                    printf("BST Inorder Travesal\n");
                    inorder(root);
                    printf("BST Postorder Travesal\n");
                    postorder(root);

                  }break;
           case 5:return;
           default:printf("Invalid\n");
                  return;
      }
    }
}










