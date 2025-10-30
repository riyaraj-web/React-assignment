"""Complexity: Insert/Delete/Search: O(log n), Space: O(n)"""

RED = True
BLACK = False

class Node:
    def __init__(self, data):
        self.data = data
        self.color = RED
        self.left = None
        self.right = None
        self.parent = None

class RedBlackTree:
    def __init__(self):
        self.TNULL = Node(0)
        self.TNULL.color = BLACK
        self.root = self.TNULL

    def _left_rotate(self, x):
        y = x.right
        x.right = y.left
        if y.left != self.TNULL:
            y.left.parent = x
        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def _right_rotate(self, x):
        y = x.left
        x.left = y.right
        if y.right != self.TNULL:
            y.right.parent = x
        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x == x.parent.right:
            x.parent.right = y
        else:
            x.parent.left = y
        y.right = x
        x.parent = y

    def insert(self, key):
        """Insert a key into the Red-Black Tree"""
        if not isinstance(key, (int, float)):
            raise ValueError("Key must be a number")
            
        node = Node(key)
        node.left = self.TNULL
        node.right = self.TNULL

        y = None
        x = self.root

        while x != self.TNULL:
            y = x
            if node.data < x.data:
                x = x.left
            else:
                x = x.right
        node.parent = y
        if y is None:
            self.root = node
        elif node.data < y.data:
            y.left = node
        else:
            y.right = node

        if node.parent is None:
            node.color = BLACK
            return

        if node.parent.parent is None:
            return

        self._fix_insert(node)

    def _fix_insert(self, k):
        while k.parent and k.parent.color == RED:
            if k.parent == k.parent.parent.right:
                u = k.parent.parent.left  # uncle
                if u and u.color == RED:
                    u.color = BLACK
                    k.parent.color = BLACK
                    k.parent.parent.color = RED
                    k = k.parent.parent
                else:
                    if k == k.parent.left:
                        k = k.parent
                        self._right_rotate(k)
                    k.parent.color = BLACK
                    k.parent.parent.color = RED
                    self._left_rotate(k.parent.parent)
            else:
                u = k.parent.parent.right
                if u and u.color == RED:
                    u.color = BLACK
                    k.parent.color = BLACK
                    k.parent.parent.color = RED
                    k = k.parent.parent
                else:
                    if k == k.parent.right:
                        k = k.parent
                        self._left_rotate(k)
                    k.parent.color = BLACK
                    k.parent.parent.color = RED
                    self._right_rotate(k.parent.parent)
            if k == self.root:
                break
        self.root.color = BLACK

    def search(self, key):
        """Search for a key in the tree. Returns Node if found, None otherwise."""
        if not isinstance(key, (int, float)):
            raise ValueError("Key must be a number")
        return self._search_helper(self.root, key)
    
    def _search_helper(self, node, key):
        if node == self.TNULL or key == node.data:
            return node if node != self.TNULL else None
        if key < node.data:
            return self._search_helper(node.left, key)
        return self._search_helper(node.right, key)

    def delete(self, key):
        """Delete a key from the tree"""
        if not isinstance(key, (int, float)):
            raise ValueError("Key must be a number")
            
        node = self.search(key)
        if node is None:
            print(f"Key {key} not found in the tree")
            return
        
        self._delete_node(node)

    def _delete_node(self, node):
        # Find the node to delete
        z = node
        y = z
        y_original_color = y.color
        
        if z.left == self.TNULL:
            x = z.right
            self._rb_transplant(z, z.right)
        elif z.right == self.TNULL:
            x = z.left
            self._rb_transplant(z, z.left)
        else:
            y = self._minimum(z.right)
            y_original_color = y.color
            x = y.right
            
            if y.parent == z:
                if x != self.TNULL:
                    x.parent = y
            else:
                self._rb_transplant(y, y.right)
                y.right = z.right
                y.right.parent = y
            
            self._rb_transplant(z, y)
            y.left = z.left
            y.left.parent = y
            y.color = z.color
        
        if y_original_color == BLACK:
            self._fix_delete(x)

    def _rb_transplant(self, u, v):
        if u.parent is None:
            self.root = v
        elif u == u.parent.left:
            u.parent.left = v
        else:
            u.parent.right = v
        if v != self.TNULL:
            v.parent = u.parent

    def _minimum(self, node):
        while node.left != self.TNULL:
            node = node.left
        return node

    def _fix_delete(self, x):
        while x != self.root and x.color == BLACK:
            if x == x.parent.left:
                s = x.parent.right
                if s.color == RED:
                    s.color = BLACK
                    x.parent.color = RED
                    self._left_rotate(x.parent)
                    s = x.parent.right
                
                if s.left.color == BLACK and s.right.color == BLACK:
                    s.color = RED
                    x = x.parent
                else:
                    if s.right.color == BLACK:
                        s.left.color = BLACK
                        s.color = RED
                        self._right_rotate(s)
                        s = x.parent.right
                    
                    s.color = x.parent.color
                    x.parent.color = BLACK
                    s.right.color = BLACK
                    self._left_rotate(x.parent)
                    x = self.root
            else:
                s = x.parent.left
                if s.color == RED:
                    s.color = BLACK
                    x.parent.color = RED
                    self._right_rotate(x.parent)
                    s = x.parent.left
                
                if s.right.color == BLACK and s.left.color == BLACK:
                    s.color = RED
                    x = x.parent
                else:
                    if s.left.color == BLACK:
                        s.right.color = BLACK
                        s.color = RED
                        self._left_rotate(s)
                        s = x.parent.left
                    
                    s.color = x.parent.color
                    x.parent.color = BLACK
                    s.left.color = BLACK
                    self._right_rotate(x.parent)
                    x = self.root
        
        if x != self.TNULL:
            x.color = BLACK

    def get_min(self, node=None):
        """Get minimum value in the tree"""
        if node is None:
            node = self.root
        if node == self.TNULL:
            return None
        while node.left != self.TNULL:
            node = node.left
        return node.data

    def get_max(self, node=None):
        """Get maximum value in the tree"""
        if node is None:
            node = self.root
        if node == self.TNULL:
            return None
        while node.right != self.TNULL:
            node = node.right
        return node.data

    def height(self, node=None):
        """Calculate height of the tree"""
        if node is None:
            node = self.root
        if node == self.TNULL:
            return 0
        return 1 + max(self.height(node.left), self.height(node.right))

    def inorder(self, node=None):
        """Inorder traversal of the tree"""
        if node is None:
            node = self.root
        if node != self.TNULL:
            self.inorder(node.left)
            print(f"{node.data} ({'R' if node.color else 'B'})", end=" ")
            self.inorder(node.right)

    def preorder(self, node=None):
        """Preorder traversal of the tree"""
        if node is None:
            node = self.root
        if node != self.TNULL:
            print(f"{node.data} ({'R' if node.color else 'B'})", end=" ")
            self.preorder(node.left)
            self.preorder(node.right)

    def postorder(self, node=None):
        """Postorder traversal of the tree"""
        if node is None:
            node = self.root
        if node != self.TNULL:
            self.postorder(node.left)
            self.postorder(node.right)
            print(f"{node.data} ({'R' if node.color else 'B'})", end=" ")

    def level_order(self):
        """Level order traversal of the tree"""
        if self.root == self.TNULL:
            return
        
        queue = [self.root]
        while queue:
            node = queue.pop(0)
            print(f"{node.data} ({'R' if node.color else 'B'})", end=" ")
            if node.left != self.TNULL:
                queue.append(node.left)
            if node.right != self.TNULL:
                queue.append(node.right)

    def is_empty(self):
        """Check if the tree is empty"""
        return self.root == self.TNULL

    def size(self, node=None):
        """Get the number of nodes in the tree"""
        if node is None:
            node = self.root
        if node == self.TNULL:
            return 0
        return 1 + self.size(node.left) + self.size(node.right)

    def _print_tree(self, node, indent, last):
        """Helper function for pretty printing the tree"""
        if node != self.TNULL:
            print(indent, end="")
            if last:
                print("R----", end="")
                indent += "     "
            else:
                print("L----", end="")
                indent += "|    "
            
            color_str = "RED" if node.color else "BLACK"
            print(f"{node.data} ({color_str})")
            self._print_tree(node.left, indent, False)
            self._print_tree(node.right, indent, True)

    def print_tree(self):
        """Pretty print the tree structure"""
        if self.root != self.TNULL:
            self._print_tree(self.root, "", True)
        else:
            print("Tree is empty")

def demo_red_black_tree():
    """Demonstrate the Red-Black Tree functionality"""
    print("=== Red-Black Tree Demonstration ===\n")
    
    # Create tree
    bst = RedBlackTree()
    
    # Insert data
    data = [7, 3, 18, 10, 22, 8, 11, 26]
    print(f"Inserting data: {data}")
    for val in data:
        bst.insert(val)
    
    print("\n1. Tree Structure:")
    bst.print_tree()
    
    print("\n2. Tree Traversals:")
    print("Inorder:", end=" ")
    bst.inorder()
    print("\nPreorder:", end=" ")
    bst.preorder()
    print("\nPostorder:", end=" ")
    bst.postorder()
    print("\nLevel Order:", end=" ")
    bst.level_order()
    
    print("\n\n3. Tree Properties:")
    print(f"Height: {bst.height()}")
    print(f"Minimum value: {bst.get_min()}")
    print(f"Maximum value: {bst.get_max()}")
    print(f"Tree size: {bst.size()}")
    print(f"Is tree empty: {bst.is_empty()}")
    
    print("\n4. Search Operations:")
    search_keys = [10, 15, 22, 100]
    for key in search_keys:
        result = bst.search(key)
        if result:
            print(f"Key {key} found in tree")
        else:
            print(f"Key {key} not found in tree")
    
    print("\n5. Delete Operations:")
    delete_keys = [18, 3, 7]
    for key in delete_keys:
        print(f"Deleting {key}...")
        bst.delete(key)
        print(f"Inorder after deletion:", end=" ")
        bst.inorder()
        print()
    
    print("\n6. Final Tree Structure:")
    bst.print_tree()

if __name__ == "__main__":
    demo_red_black_tree()