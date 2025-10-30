import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
        left = null;
        right = null;
    }
}

public class ZigzagTraversal {

    public static List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        boolean leftToRight = true;

        while (!queue.isEmpty()) {
            int size = queue.size();
            List<Integer> level = new ArrayList<>(Collections.nCopies(size, 0));

            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                int index = leftToRight ? i : size - 1 - i;
                level.set(index, node.val);

                if (node.left != null) queue.offer(node.left);
                if (node.right != null) queue.offer(node.right);
            }

            leftToRight = !leftToRight;
            result.add(level);
        }

        return result;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);

        List<List<Integer>> zigzag = zigzagLevelOrder(root);

        System.out.println("Zigzag Traversal:");
        for (List<Integer> level : zigzag) {
            for (int val : level) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}
