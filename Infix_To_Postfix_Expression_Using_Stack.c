#include <stdio.h>

char ifx[50],pfx[50],opst[50];
int i,j=0,k=0;
char a;
char oppr[4][3]={{'(','.','.'},{'+','-','.'},{'*','/','%'},{'^','.','.'}};

void operator_stack(char);
void push(char);
char pop();
int oper_pred(char);

void operator_stack(char op)
{
    int m;
    if(k==0) //empty
    {
        push(op);
    }
    else if(op=='(')
    {
        push(op);
    }
    else if(op==')')
    {
        for(m=(k-1);opst[m]!='(';--m)
        {
            a=pop();
            pfx[j++]=a;
        }
        k--;
        //printf("%d",k);
    }
    else
    {
        while(oper_pred(op)<= oper_pred(opst[k-1]))
        {
            a=pop();
            pfx[j++]=a;
        }
        push(op);
    }
}

void push(char op)
{
    opst[k++]=op;
}

char pop()
{
    k=k-1;
    a=opst[k];
    return(a);
}

int oper_pred(char ch)
{
    int m,n;
    for(m=0;m<3;++m)
    {
        for(n=0;n<3;++n)
        {
            if(oppr[m][n]==ch)
            {
                return m;
            }
        }
    }
}

int main()
{
    printf("Enter the infix expression:");
    gets(ifx);

    for(i=0;ifx[i]!='\0';++i)
    {
        if(ifx[i]!='+' && ifx[i]!='-' && ifx[i]!='*' && ifx[i]!='/' && ifx[i]!='%' && ifx[i]!='(' && ifx[i]!=')' )
        {
            pfx[j++]=ifx[i];
        }
        else
        {
            operator_stack(ifx[i]);
        }
    }
    while(k>0)
    {
        a=pop();
        pfx[j++]=a;
    }
    pfx[j]='\0';
    printf("The corresponding postfix expression is: ");
    puts(pfx);
    return 0;


}

/*
else if(op=='^')
    {
        push(op);
    }
    else if((op=='*' || op=='/' || op=='%') && (opst[k-1]=='+' || opst[k-1]=='-'))
    {
        push(op);
    }
    else if((op=='+' || op=='-') && (opst[k-1]=='('))
    {
        push(op);
    }
*/
