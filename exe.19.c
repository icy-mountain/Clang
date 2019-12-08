#include<stdio.h>


 int isCapital(char x)
   { 
       if(x<=90)
     {
	 return(1);}
       else
     {
	 return(0);} 
     
   }
main (void){


 printf("%d\n",isCapital('a'));

 printf("%d\n",isCapital('B'));

    return 0;
}
