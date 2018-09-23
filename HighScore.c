#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct prio{
char name[20];    
int pr;
    struct prio *next;
};
struct prio *first;

void insert();
void displayHS();

void HS()
{
    FILE *fp,*fq;
    int i;
    char name[30],score[20];
    fp=fopen("player.txt","a+");
    fq=fopen("score.txt","a+");

    while(fgetc(fp)!=EOF)
    {

    fscanf(fp,"%s",name);
    fscanf(fq,"%s",score);
    //printf("%s - %d\n",name,atoi(score));
    insert(name,atoi(score));
    

}

   
   displayHS();
   write();
   

    fclose(fp);
}





void insert(char *nm, int pri)
{
struct prio *p,*temp,*prev;
    p=(struct prio *)malloc(sizeof(struct prio));
    //int pri;
	//char nm[20];


    
    //printf("enter name and element");
    //scanf("%s %d",nm,&pri);
    strncpy(p->name,nm,20);
    p->pr=pri;

    if(first==NULL)
        {
            first=p;
            first->next=NULL;
        }


    else if(p->pr<=first->pr)
    {
        p->next=first;
        first=p;
    }
    
    else{
        prev=NULL;
        temp=first;
        while(temp!=NULL && temp->pr<=p->pr)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next = p;
        p->next=temp;

    }


}

void displayHS()
{
    if(first==NULL)
        printf("empty queue");
    else{
        struct prio *temp;
        temp=first;
        while(temp!=NULL)
        {
            printf("|%s|%d   ",temp->name,temp->pr);
            temp=temp->next;
        }
    }

}

write()
{
    FILE *fp,*fq;
    fp=fopen("player.txt","w");
    fq=fopen("score.txt","w");
    if(first==NULL)
        printf("empty queue");
    else{
        struct prio *temp;
        temp=first;
        while(temp!=NULL)
        {
            //printf("|%s|%d   ",temp->name,temp->pr);
            fprintf(fp,"%s\n",temp->name);
            fprintf(fq,"%d\n",temp->pr);
            temp=temp->next;
        }
    }

}
