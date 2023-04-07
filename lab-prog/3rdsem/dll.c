#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int count;
struct node
{
    float mark1, mark2, mark3;
    char usn[10], name[20];
    struct node *next;
    struct node *prev;
};
 

NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("Memory full\n");
        exit(0);
    }
    return x;
}

NODE createnode()
{
    NODE temp;
    temp = getnode(); // getnode() function returns the address of a node
    printf("Enter the usn: ");
    scanf("%s", temp->usn); // temp is a pointer to a node
    printf("Enter the name: ");
    scanf("%s", temp->name);
    printf("Enter the mark1: ");
    scanf("%f", &temp->mark1);
    printf("Enter the mark2: ");
    scanf("%f", &temp->mark2);
    printf("Enter the mark3: ");
    scanf("%f", &temp->mark3);
    // create a new node
    temp->next = NULL;
    temp->prev = NULL;
    return temp; // return the address of the node
}

void disp_deleted(NODE temp){
    printf("The deleted node is: ");
    printf("usn: %s name: %s mark1: %f mark2: %f mark3: %f \n", temp->usn, temp->name, temp->mark1, temp->mark2, temp->mark3);
    count--;
}

void insert_front(){
    NODE temp;
    temp = createnode(); // create a new node
    if(first == NULL){ // if the list is empty
        first = temp; // first points to the new node
    }
    else{ // if the list is not empty
        temp->next = first; // the new node points to the first node
        first->prev = temp; // the first node points to the new node
        first = temp; // first points to the new node
    }
}

void delete_front(){
    NODE temp; //create a temp node
    if(first == NULL){ // if the list is empty
        printf("List is empty \n");
        return;
    }
    else if(first->next==NULL){ //if there is only one node in the list
        disp_deleted(first); //display node that is deleted
        free(first); //free the node
        first = NULL; //set the pointer to null
    }else{
        temp=first; //set the temporary node to the first node
        disp_deleted(temp); //display node that is deleted
        first=first->next; //set the first to the next node
        first->prev=NULL; //set the previous node to null
        first->next=NULL; //set the next node to null
        free(temp); //free the temp node
        temp = NULL; //set the temp node to null
    }
}

void insert_rear(){
    NODE temp,cur;
    temp = createnode(); // create a new node
    if(first == NULL){ // if the list is empty
        first = temp; // first points to the new node
    }
    else{ // if the list is not empty
        cur = first; // set the current node to the first node
        while(cur->next != NULL){ // while the current node is not the last node
            cur = cur->next; // set the current node to the next node
        }
        cur->next = temp; // the current node points to the new node
        temp->prev = cur; // the new node points to the current node
    }
}

void delete_rear(){
    NODE cur;
    if(first == NULL){ // if the list is empty
        printf("List is empty \n");
        return;
    }
    else if(first->next==NULL){ //if there is only one node in the list
        disp_deleted(first); //display node that is deleted
        free(first); //free the node
        first = NULL; //set the pointer to null
    }else{
        cur = first; // set the current node to the first node
        while(cur->next != NULL){ // while the current node is not the last node
            cur = cur->next; // set the current node to the next node
        }
        disp_deleted(cur); //display node that is deleted
        cur->prev->next = NULL; //set the next node to null
        cur->prev = NULL; //set the previous node to null
        free(cur); //free the current node
        cur = NULL; //set the current node to null
    }
}

void display(){
    NODE temp;
    float total, avg;
    if(first == NULL){ // if the list is empty
        printf("List is empty \n");
        return;
    }
    temp = first; // set the temp node to the first node
    while(temp != NULL){ // while the temp node is not null
        total = temp->mark1 + temp->mark2 + temp->mark3;
        avg = total/3;
        printf("usn: %s name: %s mark1: %f mark2: %f mark3: %f total: %f avg: %f \n", temp->usn, temp->name, temp->mark1, temp->mark2, temp->mark3, total, avg);
        temp = temp->next; // set the temp node to the next node
    }

}

void main(){
    int choice, i, n;
    while(1){
        printf("1. Insert front \n");
        printf("2. Delete front \n");
        printf("3. Insert rear \n");
        printf("4. Delete rear \n");
        printf("5. Display \n");
        printf("6. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: insert_front();
                    break;
            case 2: delete_front();
                    break;
            case 3: insert_rear();
                    break;
            case 4: delete_rear();
                    break;
            case 5: display();
                    break;
            case 6: exit(0);
            default: printf("Invalid choice \n");
        }
    }
}