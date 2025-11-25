#include<stdio.h>
int main (){
    int cp,sp;
    printf ("Enter Cost price: ");
    scanf ("%d",&cp);
     printf ("Enter Selling Price: ");
    scanf ("%d",&sp);
    if ((sp-cp)>0 || (sp-cp)==0)
    {
        printf ("The Profit is: %d",(sp-cp));
    
    }
    else {
        printf ("The loss is: %d",(cp-sp));
    }

    return 0;
}