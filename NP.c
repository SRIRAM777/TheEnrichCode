#include<stdio.h>
#include<string.h>
int main()
{
  char a[100];
  int len,i;
  printf("Enter a number:\t");
  scanf("%s",a);
  len=strlen(a);
  for(i=0;i<=len/2;i++)
  {
    if(a[len-1-i]>a[i])
    {
      a[len-2-i]++;
    }
    a[len-1-i]=a[i];
  }
  for(i=0;i<len-1;i++)
  {
    if(a[i]>=':')
    {
      a[i]='0';
      if(a[i-1]!='0')
      {
        a[i-1]++;
      }
      a[i+1]++;
    }
  }
  printf("Next palindrome:\t%s\n",a);
  return 0;
}