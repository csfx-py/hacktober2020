import java.io.*;

public class maqbst {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String []Input = br.readLine().split(",");
		int cur1 = 1, cur2 = 1;
		int n = Input.length;
		for(int i = 0; i < n; i++)
		{
			if(Input[i].equals("Left"))
			{
				cur1 = 2*cur1;
				cur2 = 2*cur2;
			}
			else if(Input[i].equals("Right"))
			{
				cur1 = 2*cur1+1;
				cur2 = 2*cur2+1;
			}
			else {
				cur1 = 2*cur1;
				cur2 = 2*cur2 + 1;
			}
		}
		int ans = 0;
		if(cur1 != cur2)
		{
			if(Input[n-1].equals("Any"))
				{
					for(int i = cur1; i<=cur2; i++)
					{
						ans+=i;
					}
				}
			else
			{
				ans = cur1+cur2;
			}
		}
		else
		{
			ans = cur1;
		}
		System.out.println(ans);
	}

}
