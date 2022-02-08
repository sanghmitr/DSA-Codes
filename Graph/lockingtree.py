# N_ary_Tree Python program
class Node:
    def __init__(self, data, children=None,parent=None):
        self.data = data
        self.children = children or []
        self.parent = parent or []
        self.locked = False
        self.uid = None
    def __str__(self):
        return str(self.data)
class N_ary_Tree:
    def __init__(self):
        self.root = None
    
    def add(self,data,parent=None):
        new_node = Node(data)
        if self.root is None:
            self.root = new_node
        else:
            parent_node = self.find_node(self.root,parent)
            parent_node.children.append(new_node)
            new_node.parent = parent_node
    
    def lock(self, val, uid):
        node = self.find_node(self.root, val)
        parent_node = node.parent
        if node.locked == False and parent_node.locked == False:
            for child in node.children:
               if child.locked == False:
                   continue
               else:
                   return False
            node.locked = True
            node.uid = uid
            return True
        else:
            return False
    
    def unlock(self, val, uid):
        node = self.find_node(self.root, val)
        if node.uid == uid:
            node.locked = False
            return True
        else:
            return False
    
    # def upgrade(self, val, uid):
    #     node = self.find_node(self.root, val)
    #     for child in node.children:
    #         if child.locked == True and child.uid == uid:
    #             continue
    #         else:
    #             return False
    #     node.locked = True
    #     node.uid = uid
    #     for child in node.children:
    #         child.locked = False
    #         child.uid = None
    #     return True

    def upgrade(self, val, uid):
        node = self.find_node(self.root, val)
        for child in node.children:
            if child.locked == True and child.uid != uid:
                return False
            # else:
            #     return False
        node.locked = True
        node.uid = uid
        for child in node.children:
            child.locked = False
            child.uid = None
        return True
    
    def find_node(self, node, key):
        if node is None or node.data == key:
            return node
        for child in node.children:
            return_node = self.find_node(child, key)
            if return_node:
                return return_node
        return None
    
    def print_tree(self, node, str_aux):
        if node is None:
            return ""
        str_aux += str(node) + " Locked= " +str(node.locked)+ "UID: "+ str(node.uid) + '( '
        for i in range(len(node.children)):
            child = node.children[i]
            end = ' ,' if i < len(node.children) - 1 else ' '
            str_aux = self.print_tree(child, str_aux) + end
        str_aux += ' )'
        return str_aux
    
    def __str__(self):
        return self.print_tree(self.root, "")

# main method
if __name__ == "__main__":
    n = int(input())
    m = int(input())
    que = int(input())
    lt = []
    for i in range(n):
        st = input()
        lt.append(st)
    tree = N_ary_Tree()
    tree.add(lt[0])
    i = 1
    key = [lt[0]]
    while i < n:
        temp = []
        for ele in key:
            if i < n:
                j = 0
                for j in range(m):
                    tree.add(lt[i], ele)
                    temp.append(lt[i])
                    i += 1
            else:
                break
        key.clear()
        key = temp
    print(tree)
    for i in range(que):
        temp = input().split()
        op_type = int(temp[0])
        node = temp[1]
        user_id = int(temp[2])
        if op_type == 1:
            print(tree.lock(node,user_id))
        elif op_type == 2:
            print(tree.unlock(node, user_id))
        elif op_type == 3:
            print(tree.upgrade(node, user_id))
