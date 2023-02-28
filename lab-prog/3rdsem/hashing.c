#include<stdio.h>
#include<stdlib.h>
int key, n, m, *ht, hi, elec, flag;
void create();
void insert(int key);
void display();

int main()
{
    int ch;
    printf("Enter the size of the hash table: ");
    scanf("%d", &n);
    ht = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        ht[i] = -1;
    while (1)
    {
        printf("1. Create\n2. Insert\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            printf("Enter the element to be inserted: ");
            scanf("%d", &key);
            insert(key);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

// This function creates a hash table of size n
void create(){
    // Initialize an integer variable i
    int i;
    // Allocate the memory to the hash table
    ht=(int *)malloc(n*sizeof(int));
    // Check if the size of the hash table is 0
    if(m==0){
        // If so, print the message "unable"
        printf("unable");
        // Return from the function
        return;
    }
    // Loop from i=0 to i=n-1
    for(i=0;i<n;i++)
        // Initialize each element of the hash table to -1
        ht[i]=-1;
}

void insert(int key){
    hi=key%m; // calculate the hash index
    while(ht[hi]!=-1){ // check if the index is empty
        hi=(hi+1)%n; // if not, calculate the next index
        flag = 1; // set collision flag to 1
    }
    if(flag == 1){
        printf("Collision occured\n"); // if collision occured
        flag = 0; // reset collision flag to 0
    }
    ht[hi]=key; // insert the element
    elec++; // increment the element count
}

void display(){
    int i;
    if(elec==0){
        printf("Empty");
        return;
    }
    for(i=0;i<n;i++)
        printf("%d ",ht[i]);
}