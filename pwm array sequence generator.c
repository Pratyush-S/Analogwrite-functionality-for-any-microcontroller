#include<stdio.h>
int a[303];
void main()
{
    int i,b=0;
    for(i=1;i<=303;i++)
    {
        a[i]=b;
        if((i%3)==0)b++;
    }
    for(i=303;i>0;i--)printf("%d  ",a[i]);


}
