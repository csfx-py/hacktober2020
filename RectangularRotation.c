#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,result;
    scanf("%lf %lf",&a,&b);
    //for even integers only
    double ahalfb, bhalfb;
    ahalfb= (a/sqrt(2))/2; //calculating length of bisect from origin
    bhalfb= (b/sqrt(2))/2;
    int rect1[2];
    rect1[0]=floor(ahalfb)*2+1; //Divided the dots, in arrangement of 2 rectangles 

    rect1[1]=(floor(bhalfb)*2)+1; //elements of rectangle is number of dots in row and coloumn
    int rect2[2];
    if((ahalfb-floor(ahalfb))<0.5) // for second rectangle, calculating possible value of dots it will accomodate
    {
        rect2[0]=rect1[0]-1;
    }
    else
    {
        rect2[0]=rect1[0]+1;
    }
    if((bhalfb-floor(bhalfb))<0.5)
    {
        rect2[1]=rect1[1]-1;
    }
    else
    {
        rect2[1]=rect1[1]+1;
    }
    result = (rect1[0]*rect1[1])+(rect2[0]*rect2[1]); // area of both the rectangle, is total number of dots, as length and breath
    // is number of dots.
    printf("%lf\n",result);
    
}
    
