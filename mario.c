#include <stdio.h>
#include <cs50.h>

int pos(void);

int main(void)
{

int r=pos(); // to store positive value 

for( int i = 0; i<r;i++)
{ for( int c= r-1; c>i;c--)
   printf(" ");
{ 
    for(int j = 0; j<=i;j++)

     printf("#");
}
    printf("\n");

}

}

//prompt user for value
int pos(void)
{
    int x;
    do
    {
        x=get_int("Positive Number: ");
    }while(x<1 || x>8);
    return x;
}
