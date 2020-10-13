import java.util.*;
class doublelettersequences
{
 public static void main(String[]args)
 {
     Scanner sc=new Scanner(System.in);
     System.out.println("Input a sentence");
     String str=sc.nextLine();
     str=str+" ";
     String word="";int count=0;
     for(int x=0;x<str.length();x++)
     {
         char ch=str.charAt(x);
         if(ch!=' ')
         word=word+ch;
         else
         {
            for(int y=0;y<word.lengh()-2;y++)
            {
                char c1=word.charAt(y);
                char c2=word.charAt(y+1);
                if(c1==c2)
                count++;
            }
            word="";
        }
    }
    System.out.println("No.of double letter sequences-"+count);
}
}
