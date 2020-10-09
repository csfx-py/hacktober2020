

import java.util.*;
class Node
{
  int data;
  Node prev;
  Node next;
  int size=0;
  Node(int d,Node p,Node n)
  {
    data=d;
    next=n;
    prev=p;
  }
  public void setData(int d)
  {
    data=d;
  }
  public void setLinknext(Node n)
  {
   next=n;
  }
  public void setLinkprev(Node p)
  {
   prev=p;
  }
  public int getData()
  {
    return data;
  }
  public Node getLinknext()
  {
    return next;
  }
  public Node getLinkprev()
  {
    return prev;
  }
   
}
class LinkedList
{
  Node start;
  Node end;
  int size;
  LinkedList()
  {
    start=null;
    end=null;
    size=0;
  }
  public void InsertAtFirst(int d)
  {
  Node nptr=new Node(d,null,null);
   if(start==null)
   {
     start=nptr;
     end=nptr;
     size++;
   }
   else
   {
     nptr.setLinknext(start);
     start.setLinkprev(nptr);
     start=nptr;
     size++;
   }
  }
  public void InsertAtEnd(int d)
  {
  Node nptr=new Node(d,null,null);
   if(start==null)
   {
     start=nptr;
     end=nptr;
     size++;
   }
   else
   {
     end.setLinknext(nptr);
     nptr.setLinkprev(end);
     end=nptr;
     size++;
   }
  }
  public void InsertAtPos(int d,int pos)
  {
   Node nptr=new Node(d,null,null);
   pos=pos-1;
   if(start==null)
   {
     start=nptr;
     end=nptr;
     size++;
   }
   else 
   {
    Node ptr=start;
    for(int i=1;i<=size;i++)
     {
       if (i==pos)
        {
          Node tmp=ptr.getLinknext();
          ptr.setLinknext(nptr);
          nptr.setLinkprev(ptr);
          nptr.setLinknext(tmp);
          tmp.setLinkprev(nptr);
        }
       ptr=ptr.getLinknext();
     }
     size++;
   }
  }
  public void DeleteAtEnd()
  {
   Node ptr=start;
   if(start==null)
    {
      System.out.println("Linked List is Empty");
    }
   else
    {
      end=end.getLinkprev();
      end.setLinknext(null);
      size--;
    }
  }
  public void Display()
  {
   Node ptr=start;
   if(start==null)
    {
      System.out.println("Linked list is Empty");
    }
   else
   {
     while(ptr!=null)
      {
        System.out.println("Linked list is:");
       for(int i=0;i<size;i++)
        { 
        System.out.println(ptr.getData() + " ");
         ptr=ptr.getLinknext();
        }
      }
   }
  }
}
class DoublyLinkedList
{
 public static void main(String args[])
  { 
    Scanner sc=new Scanner(System.in);
    LinkedList list=new LinkedList();
    while(true)
    {
    System.out.println("Enter the choice :\n 1.Insert at first \n 2.Delete at end \n 3.Insert at any position\n 4.Insert at end\n 5.Exit");
    int ch=sc.nextInt();
    switch(ch)
     {
       case 1: System.out.println("Enter the element to be inserted");
               list.InsertAtFirst(sc.nextInt());
               list.Display();
               break;
       case 2: list.DeleteAtEnd();
               list.Display();
               break;
       case 3: System.out.println("Enter the element to be inserted");
               int num=sc.nextInt();
               System.out.println("Enter the positon");
               int p=sc.nextInt();
               list.InsertAtPos(num,p);
               list.Display();
               break;
       case 4: System.out.println("Enter the element to be inserted");
               list.InsertAtEnd(sc.nextInt());
               list.Display();
               break;
       case 5: System.exit(0);
               break;
       default:System.out.println("Invalid option");
    }
   }
  }
}
