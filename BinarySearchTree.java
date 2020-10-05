import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BinarySearchTree {
	class Node{
		int data;
		Node left, right;
		public Node(int value)
		{
			data = value;
			left = right = null;
		}
	}
	Node root;
	BinarySearchTree()
	{
		root = null;
	}
	void insert(int data)
	{
		root = insertRec(root, data);
	}
	Node insertRec(Node root, int data)
	{
		if(root == null)
		{
			root = new Node(data);
			return root;
		}
		else {
			if(root.data > data)
			{
				root.left = insertRec(root.left, data);
			}
			else if(root.data < data)
			{
				root.right = insertRec(root.right,data);
			}
		}
		return root;
	}
	void delete(int data)
	{
		root =deleteRec(root, data);
	}
	int minvalue(Node root)
	{
		int minv = root.data;
		while(root.left != null)
		{
			minv = root.left.data;
			root = root.left;
		}
		return minv;
	}
	Node deleteRec(Node root, int data)
	{
		if(root == null)
		{
			return root;
		}
		if(root.data > data)
		{
			root.left = deleteRec(root.left, data);
		}
		else if(root.data < data)
		{
			root.right = deleteRec(root.right, data);
		}
		else
		{
			if(root.left == null)
			{
				return root.right;
			}
			else if(root.right==null)
			{ 
				return root.left;
			}
			root.data = minvalue(root.right);
			root.right = deleteRec(root.right, root.data);
		}
		return root;
	}
	void inorder()
	{
		inorderRect(root);
	}
	void inorderRect(Node root) {
		if(root != null)
		{
			inorderRect(root.left);
			System.out.println(root.data+ " ");
			inorderRect(root.right);
		}
	}
	
	public static void main(String[] args) {
		FastScanner fs = new FastScanner();
		BinarySearchTree tree = new BinarySearchTree();
		int n = fs.nextInt();
		for(int i = 0; i< n; i++)
		{
			int a = fs.nextInt();
			tree.insert(a);
		}
		tree.inorder();
	}
	static class FastScanner{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
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
