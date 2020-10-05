import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class RemoveDuplicateFromArray {
	static void removeDuplicatesS(int a [], int n) {
		Map<Integer, Integer> m = new HashMap<>();
		for(int i = 0; i < n; i++)
		{
			if(m.containsKey(a[i]))
			{
				continue;
			}
			else
			{
				System.out.println(a[i]);
				m.put(a[i],1);
			}
		}
	}
	static void removeDuplicates(int a[], int n)
	{
		Map<Integer, Integer> m = new HashMap<>();
		int len = a.length;
		for(int i = 0; i < len -1; i++)
		{
			if(m.containsKey(a[i]))
			{
				m.put(a[i],i);
			}
		}
		int f = m.size();
		System.out.println("Size of the Map "+ f);
		m.forEach((k,v) -> System.out.print(k+ " "));
	}
	public static void main(String[] args) {
		FastScanner fs = new FastScanner();
		int n = fs.nextInt();
		int []a =new int[n];
		for(int i =0 ; i < n; i++)
		{
			a[i] = fs.nextInt();
		}
		removeDuplicatesS(a, n);
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
