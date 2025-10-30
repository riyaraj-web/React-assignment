public class BinarySearchTreeTest {
    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree();
        
        bst.insert(50);
        bst.insert(30);
        bst.insert(70);
        bst.insert(20);
        bst.insert(40);
        bst.insert(60);
        bst.insert(80);
        
        bst.inorderTraversal();
        
        bst.delete(20);
        bst.inorderTraversal();
        
        bst.delete(30);
        bst.inorderTraversal();
        
        bst.delete(50);
        bst.inorderTraversal();
    }
}