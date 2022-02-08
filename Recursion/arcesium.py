from collections import deque
 
# Node class for holding the Binary Tree
class node:
    def __init__(self, data = None):
        self.data = data
        self.left = None
        self.right = None
 
Q = deque()
 

def insertValue(data, root):
    newnode = node(data)
    if Q:
        temp = Q[0]
    if root == None:
        root = newnode
         
    # The left child of the current Node is
    # used if it is available.
    elif temp.left == None:
        temp.left = newnode

    elif temp.right == None:
        temp.right = newnode
        atemp = Q.popleft()
     
 
    Q.append(newnode)
    return root
 

def createTree(a, root):
    for i in range(len(a)):
        root = insertValue(a[i], root)
    return root
 

def solve(root,arr1):
    global i
    if root is None:
        a = arr1[i]
        i+=1
        return a
    
    l1 = solve(root.left,arr1)
    r1 = solve(root.right,arr1)

    if(root.data ==0):
        return l1+r1
    else:
        ans = []
        for k,j in zip(l1,r1):
            ans.append(k)
            ans.append(j)
        return ans
i = 0
a = [1,0,0]
root = None
root = createTree(a, root)
print(solve(root,[[10],[20],[30],[40]]))

