import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class ThreeSum {
	static void threeSumBest(int a[],int n)
	{
		boolean flag = false;
		for(int i = 0; i < n-1; i++)
		{
			int l = i+1;
			int r = n-1;
			int x= a[i];
			while(l < r)
			{
				if(a[l]+a[r]+x == 0)
				{
					flag = true;
					System.out.println(a[l]+ " "+ a[r] +" "+x);
					l++;
					r--;
				}
				else if(a[l] + a[r] +x < 0)
				{
					l++;
				}
				else
				{
					r--;
				}
			}
		}
		if(flag == false)
		{
			System.out.println("Dont exit");
		}
	}
	static void threeSumOn2(int a[], int n)
	{
		System.out.println("O(n*2) Approach");
		boolean flag = false;
		for(int i = 0; i < n-1; i++)
		{
			HashSet<Integer> m = new HashSet<Integer>();
			for(int j= i+1; j < n; j++)
			{
				int sum = -(a[i]+a[j]);
				if(m.contains(sum))
				{
					System.out.println(a[i] + " " + a[j] +" "+ sum);
					flag = true;
				}
				else
				{
					m.add(a[j]);
				}
			}
		}
		if(flag == false)
		{
			System.out.println("Dont exist");
		}
	}
	static void threeSumBf(int a[],int n)
	{
		boolean flag = false;
		for(int i = 0; i < n-2; i++)
		{
			for(int j = i+1; j < n-1; j++)
			{
				for(int k = j+1; k < n; k++)
				{
					if(a[i] + a[j] + a[k] == 0)
					{
						System.out.println(a[i] + " " + a[j] + " " + a[k]);
						flag = true;
					}
				}
			}
		}
		if(flag == false)
		{
			System.out.println("Doesnt exist any triplet");
		}
	}
	public static void main(String[] args) {
		FastScanner fs = new FastScanner();
		int n = fs.nextInt();
		int []a = new int[n];
		for(int i = 0; i < n; i++)
		{
			a[i] = fs.nextInt();	
		}
		threeSumBf(a,n);
		threeSumOn2(a,n);
		threeSumBest(a,n);
	}
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}	
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}
}
