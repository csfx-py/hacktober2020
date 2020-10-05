import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class TwoSum {
	static void twoPointersApproach(int []a ,int n, int x)
	{
		Arrays.sort(a);
		int left = 0;
		int right = n-1;
		while( left < right)
		{
			if(a[left]  + a[right] == x)
			{
				System.out.println(a[left]+ " " + a[right]);
				break;
			}
			else if(a[left] + a[right] < x)
			{
				left++ ;
			}
			else
			{
				right--;
			}
		}
	}
	static void findpairsumtox(int []a ,int n, int x)
	{
		HashMap<Integer,Integer> m = new HashMap<Integer,Integer>();
		int []res = new int[2];
		for(int i = 0; i < n; i++)
		{
			int diff = x - a[i];
			if(m.containsKey(diff))
			{
				res[0] = i;
				res[1] = m.get(diff);
			}
			m.put(a[i], i);
		}
		System.out.println(a[res[0]] + " " + a[res[1]]);
	}
	public static void main(String[] args) {
		FastScanner fs = new FastScanner();
		
		int n = fs.nextInt();
		int []a = new int[n];
		for(int i= 0; i < n; i++)
		{
			a[i] = fs.nextInt();
		}
		int x = fs.nextInt();
		//findpairsumtox(a,n,x);
		twoPointersApproach(a,n,x);
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
