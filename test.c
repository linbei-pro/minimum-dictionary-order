#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//输入样例 3 000 011 111
int cmp(const void*a,const void* b)
{
    char s1[200000],s2[200000];
    strcpy(s1,*(char**)a);
    strcpy(s2,*(char**)b);
    return strcmp(strcat(s1,s2),strcat(s2,s1));
//虽然strcat时改变了s1,s2的值，但可以论证出这与不改变的情况是等价的
}
int main(int argc, char *argv[])
{
  int n,i;
    scanf("%d",&n);
    char buffer[200000];//缓冲数组
    char **a=(char**)malloc(sizeof(char**)*n);//指针数组，可以理解为字符串数组
    for(i=0;i<n;i++)
    {
        scanf("%s",buffer);
        a[i]=(char*)malloc(sizeof(char*)*(strlen(buffer)+1));//动态内存
        strcpy(a[i],buffer);
    }
    qsort(a,n,sizeof(char**),cmp);//快排
    for(i=0;i<n;i++)
        printf("%s",a[i]);
  return 0;
}
