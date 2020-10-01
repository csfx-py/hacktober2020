## Binary Search Tree basic operations

class Node:
  def __init__(self,data):
    self.data = data
    self.left = None
    self.right = None 


// Add node in BST
def add_child(node,val):
  root = node
  if val == root.data:
    return

  if root.data > val:
    #add left subtree
    if root.left:
      add_child(root.left,val)
    else:
      root.left = Node(val)
  else:
    #add right subtree
    if root.right:
      add_child(root.right,val)
    else:
      root.right = Node(val)


In order traversal - Ascending to Descending Traversal
def inorder_trav(node,ele):
  root = node
  #ele = []
  if not root:
    return
  
  inorder_trav(root.left,ele)
  ele.append(root.data)
  inorder_trav(root.right,ele)

  return ele


// Search Element in BST O(LogN)
def search_tree(node,el):
  root = node
  #print(root.data)
  if not root:
    return False

  if el > root.data:
    root = root.right
    return search_tree(root,el)
  
  elif el < root.data:
    root = root.left
    return search_tree(root,el)

  else:
    return True

  
  #return True


// Minimum Node (Right sub tree's Minimum Element)
def minNode(node):
  current = node
  
  while current.left is not None:
    current = current.left
  
  return current


// Delete Node in BST 
def delete(node,el): 
  root = node

  if el < root.data:
    if root.left:
      root.left = delete(root.left,el)
  
  elif el > root.data:
    if root.right:
      root.right = delete(root.right,el)
  
  else:
    if root.left is None and root.right is None:
      return None
    
    elif root.left is None:
      root = root.right
      return root
    
    elif root.right is None:
      root = root.left
      return root

    
    else:
      minVal = minNode(root.right)
      root.data = minVal.data
      root.right = delete(root.right,minVal.data)

  return root


ele = [17,8,2,34,1,4,6,9]
node = Node(ele[0])


for i in range(1,len(ele)):
  add_child(node,ele[i])

print(inorder_trav(node,[]))
print(search_tree(node,6))
print(inorder_trav(delete(node,6),[]))
