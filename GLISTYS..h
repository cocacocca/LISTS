#include<stdlib.h>
#include<stdio.h>
#include "LIST.c"
glists * glistcopy(p)
{
    glists * p;
    glists * q;
    if(p==NULL)
        return NULL;
    else
    {
        q=(glists *)malloc(sizeof(glists));
        q->tag=p->tag;
        if(p->tag==1)
            q->element.sublink=glistcopy(p->element.sublink)
        else
            q->element.data=p->element.data;
        q->link=glistcopy(p->next);
        return q;
    }
}

glists * glistcreate(char * s)
{
    glists * p;
    char ch;
    ch = *s;
    s++;
    if(ch!='$')
    {
        p=(glists*)malloc(sizeof(glists));
        if(ch=='(')
        {
            p->tag=1;
            p->element.sublink=glistcreate(s);
        }
        else if (ch=')')
        {
            p->tag=1;
            p->element.sublink=NULL;
        }
        else
        {
            p->tag=0;
            p->element.data=ch;
        }
    }
    else 
    {
        p=NULL;
    }
    ch=*s;
    s++;
    if(p!=NULL)
    {
        if(ch==',')
            p->link=glistcreate(s);
        else
            p->link=NULL;
    }
    return p;
}

void writeglist(ha)
{
    glists * ha;
    if(ha!=NULL)
    {
        if(ha->tag==1)
        {
            printf("(");
            if(ha->element.sublink==NULL)
                printf("#");
            else
                writeglist(ha->element.sublink);
        }
        else
            printf("%c",ha->element.data);
        if(ha->tag==1)
            printf(")");
        if(ha->link!=NULL)
        {
            printf(",");
            writeglist(ha->link);
        }
    }
}

glists * headglist(glist * ha)
{
    glists * p = ha->element.sublink;
    glists*q,*t;
    if(p==NULL)
    {
        printf("空表不能求表头");
        exit(0);
    }
    else if(ha->tag==0)
    {
        printf("原子不能求表头");
        exit(0);
    }
    if(p->tag==0)
    {
        q=(glists*)malloc(sizeof(glists));
        q->tag=0;
        q->element.data=p->element.data;
        q->link=NULL;
    }
    else
    {
        t=(glists*)malloc(sizeof(glists));
        t->tag=1;
        t->element.sublink=p->element.sublink;
        t->link=NULL;
        q=qlistcopy(t);
        free(t);
    }
    return q;
}

glists * tailglist(glists * ha)
{
    glists * p = ha->element.sublink;
    glists * q,*t;
    if(p==NULL)
    {
        printf("空表不能求表尾");
        exit(0);
    }
    else if(ha->tag==0)
    {
        printf("原子不能求表尾");
        exit(0);
    }
    p=p->link;
    t=(glists*)malloc(sizeof(glists));
    t->tag=1;
    t->element.sublink=p;
    t->link=NULL;
    q=glistcopy(t);
    return q;
}