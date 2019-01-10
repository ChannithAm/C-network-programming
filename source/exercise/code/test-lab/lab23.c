/**
 * File              : lab23.c
 * Author            : Channith Am <amcnith@gmail.com>
 * Date              : 13.12.2018
 * Last Modified Date: 13.12.2018
 * Last Modified By  : Channith Am <amcnith@gmail.com>
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
main()
{int M=0,n,i=0;
 char N[100];
 while(i!=-1) {printf(" Nhap vao so nguyen N>=0 he co so 2 : ");
               fflush(stdin);gets(N);
               n=strlen(N)-1;
               for(i=n;i>=0;i--) if(N[i]!='0'&&N[i]!='1') break;}
 i=n;
 while(i!=-1) {if (N[i]=='1') M=M+pow(2,n-i);
               i--;}
 printf("\n Gia tri so vua nhap o he co so 10 la : %d",M);
}
