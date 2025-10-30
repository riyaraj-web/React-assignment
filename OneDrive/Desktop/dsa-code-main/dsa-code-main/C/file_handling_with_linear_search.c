#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student
{
    char name[20];
    char class[10];
}record;
record std[100];
int read_file(record *a)
{
    int i=0;
    FILE *fp;
    if((fp=fopen("student.txt","r"))!=NULL)
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s%s",a[i].name,a[i].class);
            i++;
        }
    }
    return (i-1);
}
void l_search(record *a,int n,char name[20])
{
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(a[i].name,name)==0)
        {
            printf("\nName=%s\nClass=%s\n",a[i].name,a[i].class);
            break;
        }
    }
    if(i==n)
        printf("\nStudent %s is not in the list\n",name);
}
int main()
{
    char name[20];
    int n;
    n=read_file(std);
    printf("\nEnter Student name\n");
    gets(name);//sacnf("%s",name);
    l_search(std,n,name);
    return 0;
}