import java.util.Scanner;

public class CelebProblem {

    int top=-1,topi=-1;
    int max=1000;
    int[] stack= new int[1000];
    int[][] Ar;

    void push(int x) {
        if(top==(max-1)) {
            System.out.println("Stack Overflow");
        } else {
            stack[++top]=x;
        }
    }

    int pop() {
        int elem=stack[top--];
        return elem;
    }

    int assume() {
        return(stack[top]);
    }

    void main() {
        Scanner sc = new Scanner(System.in);
        CelebProblem obj= new CelebProblem();
        int i,j,topi=-1;
        int n=sc.nextInt();
        int[][] Ar=new int[n][n];

        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                Ar[i][j]=sc.nextInt();
            }
        }

        for(i=0;i<n;i++) {
            obj.push(i);
        }

        for(i=0;i<(n-1);i++) {
            int ele1 = obj.pop();
            int ele2 = obj.pop();
            if(Ar[ele1][ele2]==0) {
                obj.push(ele1);
            }
            else if(Ar[ele1][ele2]==1) {
                obj.push(ele2);
            }
        }

        int assumed= obj.assume();
        int found=1;

        for (i=0;i<n;i++) {
            if(Ar[assumed][i]!=0) {
                found=0;
                break;
            }
            if(i!=assumed && Ar[i][assumed]!=1) {
                found=0;
                break;
            }
        }

        if(found==0) {
            System.out.println("-1");
        } else {
            System.out.println(assumed);
        }
    }
}
