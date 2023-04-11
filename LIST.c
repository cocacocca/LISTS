#include <stdio.h>
#include "GLISTYS.h"
#include "BHCLEAR.h"

typedef struct node
{
    int tag;
    union 
    {
        char data;
        struct node * sublink;
    }element;
    struct node * next;
}glists;



void main()
{
    char * sa = {"(a,(b,c,q,j,p))$"};
    glists * pcopy , *p, *ga=NULL;
    clear();
    printf("\n\n\t\t广义表的基本运算");
    printf("\n\n\t输入的字符串是:sa=%s",sa);
    ga=glistcreate(sa);
    printf("\n\n\t建立的广义表是:pa=");
    writeglist(ga);
    pcopy=glistcopy(ga);
    printf("\n\n\t复制的广义表是:pa=");
    writeglist(pcopy);
    p=headglist(ga);
    printf("\n\n\t表头运算结果是:head=%c",p->element.data);
    p=tailglist(ga);
    printf("\n\n\t表尾运算结果是:tail=");
    writeglist(p);
}