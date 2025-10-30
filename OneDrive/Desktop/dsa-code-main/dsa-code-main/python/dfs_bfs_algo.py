import collections

class Node:
    """
    A simple class for a binary tree node.
    """
    def __init__(self, key):
        self.val = key
        self.left = None
        self.right = None

# --- Depth-First Search (DFS) Traversal Algorithms ---

def print_preorder(root):
    """
    Performs Pre-order traversal (Root -> Left -> Right).
    """
    if root:
        # 1. Visit the root node
        print(root.val, end=" ")
        
        # 2. Recursively visit the left subtree
        print_preorder(root.left)
        
        # 3. Recursively visit the right subtree
        print_preorder(root.right)

def print_inorder(root):
    """
    Performs In-order traversal (Left -> Root -> Right).
    For a Binary Search Tree (BST), this prints nodes in sorted order.
    """
    if root:
        # 1. Recursively visit the left subtree
        print_inorder(root.left)
        
        # 2. Visit the root node
        print(root.val, end=" ")
        
        # 3. Recursively visit the right subtree
        print_inorder(root.right)

def print_postorder(root):
    """
    Performs Post-order traversal (Left -> Right -> Root).
    Useful for operations like deleting nodes.
    """
    if root:
        # 1. Recursively visit the left subtree
        print_postorder(root.left)
        
        # 2. Recursively visit the right subtree
        print_postorder(root.right)
        
        # 3. Visit the root node
        print(root.val, end=" ")

# --- Breadth-First Search (BFS) Traversal Algorithm ---

def print_level_order(root):
    """
    Performs Level-order (BFS) traversal, visiting nodes level by level.
    Uses a queue to keep track of nodes.
    """
    if not root:
        return
    
    # Use a deque (double-ended queue) for efficient pop(0)
    queue = collections.deque([root])
    
    while queue:
        # Dequeue the first node in the queue
        node = queue.popleft()
        
        print(node.val, end=" ")
        
        # Enqueue the left child if it exists
        if node.left:
            queue.append(node.left)
            
        # Enqueue the right child if it exists
        if node.right:
            queue.append(node.right)


# --- Main function to run the example ---
if __name__ == "__main__":
    
    # Let's manually create a simple binary tree:
    #
    #        1
    #       / \
    #      2   3
    #     / \   \
    #    4   5   6

    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.right = Node(6)

    print("Pre-order traversal (Root, Left, Right):")
    print_preorder(root)
    # Expected: 1 2 4 5 3 6
    print("\n")

    print("In-order traversal (Left, Root, Right):")
    print_inorder(root)
    # Expected: 4 2 5 1 3 6
    print("\n")

    print("Post-order traversal (Left, Right, Root):")
    print_postorder(root)
    # Expected: 4 5 2 6 3 1
    print("\n")
    
    print("Level-order traversal (BFS):")
    print_level_order(root)
    # Expected: 1 2 3 4 5 6
    print("\n")
