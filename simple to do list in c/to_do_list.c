#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    //declaring i for loops and taskcount to track the number of tasks. 
    int i,taskcount;

    //taking the no of tasks from user 
    printf("enter how many tasks you want to add: ");
    scanf("%d",&taskcount);

    //for consuming the newline after scanf
    getchar();

    //to allocate the memory based on user input
    char (*task)[100]=malloc(taskcount * sizeof(*task));

    //loop to get the taks
    for(i=0;i<taskcount;++i){
        printf("enter your %d task:\n",i+1);

        //fgets to read a line of input and sizeof(tak[i]) to stop the overflow of allocated memory
        fgets(task[i],sizeof(task[i]),stdin);

        //to find the newline character'\n' and replace it with '\0' , removing the new line
        strtok(task[i],"\n");
    }
    //to display tasks
    printf("your tasks are: \n");
    for(i=0;i<taskcount;++i){
        printf("%s\n",task[i]);
    }
    //to free the allocated memory so there willn't be any memory leak 
    free(task);
    return 0;
}