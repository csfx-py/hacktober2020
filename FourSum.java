import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.Vector;

public class FourSum {
	static class Pair{
		int first, second;
		public Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
	}
	static void fourSumClement(int a[], int n, int x)
	{
		HashMap<Integer, Vector<Pair> > m = new HashMap<Integer, Vector<Pair>>();
		for(int i= 0; i < n-1;  i++)
		{
			for(int j = i+1; j < n; j++)
			{
				int sum = a[i] + a[j];
				int diff = x - sum;
				if(m.containsKey(diff))
				{
					Vector<Pair> s = m.get(diff);
					for(int k = 0; k < s.size(); k++)
					{
						Pair p = s.get(i);
						System.out.println(a[i]+" " +a[j] + " "+p.first+" "+p.second);
					}
				}
				else
				{
					if(!m.containsKey(sum))
					{
						Vector<Pair> t = new Vector<Pair>();
						Pair o = new Pair(a[i], a[j]);
						t.add(o);
						m.put(sum, t);
					}
					else
					{
						Vector<Pair> t = m.get(sum);
						Pair o = new Pair(a[i], a[j]);
						t.add(o);
						m.put(sum, t);
					}
				}
			}
		}
	}
	static void fourSumhashmap(int a[],int n,int x)
	{
		HashMap<Integer, Pair> mp = new HashMap<Integer, Pair>();
		for(int i = 0; i < n-1; i++)
		{
			for(int j = i+1; j < n; j++)
			{
				mp.put(a[i]+a[j], new Pair(i,j));
			}
		}
		for(int i = 0; i < n-1; i++)
		{
			for(int j = i+1; j < n; j++)
			{
				int diff= x-(a[i]+a[j]);
				if(mp.containsKey(diff))
				{
					Pair p = mp.get(diff);
					if((p.first != i && p.second!=j )|| (p.second!=i  && p.first!=j))
					{
						System.out.println(a[i]+ " "+a[j]+" "+a[p.first]+" "+a[p.second]);
					}
				}
			}
		}
	}
	static void fourSumSortThearray(int a[], int n, int x)
	{
		Arrays.sort(a);
		for(int i= 0; i < n-3; i++)
		{
			for(int j= i+1; j < n-2; j++)
			{
				int l = j+1;
				int r = n-1;
				while( l < r )
				{
					if(a[l]+a[r]+a[j]+a[i]==x)
					{
						System.out.println(a[i]+" " + a[j] + " " + a[l] + " "+a[r]);
						l++;
						r--;
					}
					else if(a[l]+a[r]+a[i]+a[j] < x)
					{
						l++;
					}
					else
					{
						r--;
					}
				}
			}
		}
	}
	static void fourSumbf(int a[], int n, int x)
	{
		boolean found = false;
		for(int i = 0; i < n-3; i++)
		{
			for(int j= i+1; j < n-2; j++)
			{
				for(int k = j+1; k < n-1; k++)
				{
					for(int l = k+1; l < n; l++)
					{
						if(a[i]+a[j]+a[k]+a[l] == x)
						{
							found = true;
							System.out.println(a[i] + " " + a[j] +" "+a[k]+" "+a[l]);
						}
					}
				}
			}
		}
		if(!found)
		{
			System.out.println("Dont exist");
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
			FastScanner fs = new FastScanner();
			int n = fs.nextInt();
			int  a[] = new int[n];
			for(int i = 0; i < n; i++)
			{
				a[i] = fs.nextInt();
			}
			int x = fs.nextInt();
			//fourSumbf(a,n, x);
			//fourSumSortThearray(a,n,x);
			//fourSumhashmap(a,n,x);
			fourSumClement(a,n,x);
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
