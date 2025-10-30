class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string."""
        def recur(node):
            if not node:
                vals.append('null')
                return
            vals.append(str(node.val))
            recur(node.left)
            recur(node.right)

        vals = []
        recur(root)
        return ','.join(vals)

    def deserialize(self, data):
        """Decodes your encoded data to tree."""
        def recur():
            if self.vals[0] == 'null':
                self.vals.pop(0)
                return None
            node = TreeNode(int(self.vals[0]))
            self.vals.pop(0)
            node.left = recur()
            node.right = recur()
            return node

        self.vals = data.split(',')
        return recur()
