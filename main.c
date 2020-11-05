#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Process: Each process has a name and has an execution time.
 *          We keep track of how long the process still needs
 *          to run on the processor. "remaining_time" is the
 *          remaining execution time of the process.
 */
typedef struct
{
    char *name;
    int starting_time;
    int remaining_time;
} Process;
/*
 *
 */
typedef struct Node
{
    Process data;
    struct Node* next;
} Node;
/*
 *
 */
typedef struct
{
    Node* head;
    Node* tail;

} Queue;
/*
 *
 */
Queue* init()
{
    Queue *q=malloc(sizeof(Queue));
    q->head=NULL;
    q->tail=NULL;
    return q;
}
Node *newNode(Process val)
{
    Node *n=malloc(sizeof(Node));
    n->data=val;
    n->next=NULL;
    return n;

}
/*
 *
 */
int isEmpty(Queue *q)
{
    if(q->head==NULL)
        return 1;
    else
        return 0;

}
/*
 *
 */
Process dequeue(Queue *q)
{
    if(!isEmpty(q))
    {
        Node *temp=q->head;
        Process val =q->head->data;
        q->head=q->head->next;
        free(temp);
        if(q->head==NULL)  //One node
            q->tail=NULL;

        return val;

    }
    else
    {
        printf("\nQueue is empty you can't delete\n");

    }


}
/*
 *
 */
void enqueue(Queue *q, Process val)
{
    Node *n=newNode(val);
    if(isEmpty(q))
    {
        q->head=q->tail=n;
    }
    else
    {
        q->tail->next=n;
        q->tail=n;
    }

}
/*
 *
 */
void destroy(Queue *q)
{
    while(!isEmpty(q))
        dequeue(q);
}
/*
 * RoundRobin Scheduling
 */

void RoundRobin(char* filename)
{
    FILE *fp=fopen(filename,"r");
    Queue *q=init();
    char *a=malloc(60);
    char *token;
    fgets(a,260,fp);
    token = strtok(a,"=");
    token = strtok(NULL," \n");
    int TotalTime=atoi(token);
    Process p[20];
    int i=0,c=0;
    while(fgets(a,260,fp)!=NULL)
    {
        token=strtok(a," ");
        p[i].name=malloc(10);
        strcpy(p[i].name,token);
        token= strtok(NULL," ");
        p[i].starting_time=atoi(token);
        token=strtok(NULL," ");
        p[i].remaining_time=atoi(token);
        i++;
        c++;
    }

    int j=0;
    for (i=0; i<TotalTime; i++)
    {
        for(j=0; j<c; j++) //until count
        {
            int x = p[j].starting_time==i;
            if(x)
            {
                enqueue(q,p[j]);


            }
        }
        if(!isEmpty(q))
        {
            Process m =dequeue(q);
            printf("%s   (%d --> %d) \n",m.name,i,i+1);
            m.remaining_time--;
            int k = m.remaining_time>0;
            if(k)
            {

                enqueue(q,m); //print
            }

            else //aborts
            {
                printf("%s aborts \n",m.name);
            }
        }


        else
        {
            printf("Idle (%d --> %d)  \n",i,i+1);
        }



    }



    fclose(fp);


}
/*
 *
 */
int main()
{
    char filename[261];
    puts("Enter file name or Ctrl+Z to exit:");
    puts("----------------------------------");
    while(fgets(filename, 260, stdin) != NULL)
    {
        filename[strlen(filename)-1]='\0';
        if(fopen(filename,"r"))
            RoundRobin(filename);
        else
        {
            puts("File Not Found!");
            puts("----------------------------------");
        }
        puts("Enter file name or Ctrl+Z to exit:");
        puts("----------------------------------");
    }

    return 0;
}
