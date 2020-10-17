
class Node:  
    def __init__(self, new_data):  
        self.data = new_data  
        self.next = None
  
# Function to delete the last occurrence 
def deleteLast(head, x): 
  
    temp = head 
    ptr = None
    while (temp!=None):  
  
        # If found key, update 
        if (temp.data == x) : 
            ptr = temp      
        temp = temp.next
    print(ptr)
    # If the last occurrence is the last node 
    if (ptr != None and ptr.next == None):  
        temp = head 
        while (temp.next != ptr) : 
            temp = temp.next    
        temp.next = None
      
    # If it is not the last node 
    if (ptr != None and ptr.next != None):  
        ptr.data = ptr.next.data 
        temp = ptr.next
        ptr.next = ptr.next.next
          
    return head 
      
# Utility function to create a new node with 
# given key  
def newNode(x): 
  
    node = Node(0) 
    node.data = x 
    node.next = None
    return node 
  
# This function prints contents of linked list 
# starting from the given Node 
def display( head): 
  
    temp = head 
    if (head == None):  
        print("None\n") 
        return
      
    while (temp != None):  
        print( temp.data," -> ",end="") 
        temp = temp.next
      
    print("None") 
  
# Driver code 
  
head = newNode(1) 
head.next = newNode(2) 
head.next.next = newNode(3) 
head.next.next.next = newNode(4) 
head.next.next.next.next = newNode(5) 
head.next.next.next.next.next = newNode(4) 
head.next.next.next.next.next.next = newNode(4) 
print("Created Linked list: ") 
display(head) 
head = deleteLast(head, 4) 
print("List after deletion of 4: ") 
display(head)