
import java.util.*;

public class LinkCutTre {



    static class Node {

        Node left, right, parent;
        boolean rev;
        long val;
        long sum;
        int id;

        Node(int id, long val) {
            this.id = id;
            this.val = val;
            this.sum = val;
        }
    }

    private final Node[] nodes;

    public LinkCutTree(int n) {
        nodes = new Node[n + 1];
        for (int i = 1; i <= n; i++) {
            nodes[i] = new Node(i, 0);
        }
    }

    private void pull(Node x) {
        x.sum = x.val + (x.left != null ? x.left.sum : 0) + (x.right != null ? x.right.sum : 0);
    }

    private void push(Node x) {
        if (x == null) {
            return;
        }
        if (x.rev) {
            Node t = x.left;
            x.left = x.right;
            x.right = t;
            if (x.left != null) {
                x.left.rev ^= true;
            }
            if (x.right != null) {
                x.right.rev ^= true;
            }
            x.rev = false;
        }
    }

    private boolean isSplayRoot(Node x) {
        Node p = x.parent;
        return p == null || (p.left != x && p.right != x);
    }

    private void rotate(Node x) {
        Node p = x.parent;
        Node g = p.parent;
        if (!isSplayRoot(p)) {
            if (g.left == p) {
                g.left = x; 
            }else {
                g.right = x;
            }
        }
        x.parent = g;
        if (p.left == x) {
            p.left = x.right;
            if (x.right != null) {
                x.right.parent = p;
            }
            x.right = p;
            p.parent = x;
        } else {
            p.right = x.left;
            if (x.left != null) {
                x.left.parent = p;
            }
            x.left = p;
            p.parent = x;
        }
        pull(p);
        pull(x);
    }

    private void pushPath(Node x) {
        if (!isSplayRoot(x)) {
            pushPath(x.parent);
        }
        push(x);
    }

    private void splay(Node x) {
        if (x == null) {
            return;
        }
        pushPath(x);
        while (!isSplayRoot(x)) {
            Node p = x.parent;
            Node g = p.parent;
            if (!isSplayRoot(p)) {
                if ((p.left == x) == (g.left == p)) {
                    rotate(p); 
                }else {
                    rotate(x);
                }
            }
            rotate(x);
        }
    }

    private Node access(Node x) {
        Node last = null;
        for (Node y = x; y != null; y = y.parent) {
            splay(y);
            y.right = last;
            pull(y);
            last = y;
        }
        splay(x);
        return last;
    }

    private void makeRoot(Node x) {
        access(x);
        x.rev ^= true;
        push(x);
    }

    private Node findRoot(Node x) {
        access(x);
        while (true) {
            push(x);
            if (x.left == null) {
                break;
            }
            x = x.left;
        }
        splay(x);
        return x;
    }

    public boolean link(int ui, int vi) {
        Node u = nodes[ui], v = nodes[vi];
        makeRoot(u);
        if (findRoot(v) == u) {
            return false;
        }
        u.parent = v;
        return true;
    }

    public boolean cut(int ui, int vi) {
        Node u = nodes[ui], v = nodes[vi];
        makeRoot(u);
        access(v);
        if (v.left == u && u.right == null) {
            v.left.parent = null;
            v.left = null;
            pull(v);
            return true;
        }
        return false;
    }

    public boolean connected(int ui, int vi) {
        return findRoot(nodes[ui]) == findRoot(nodes[vi]);
    }

    public void update(int ui, long newVal) {
        Node u = nodes[ui];
        access(u);
        u.val = newVal;
        pull(u);
    }

    public long query(int ui, int vi) {
        Node u = nodes[ui], v = nodes[vi];
        makeRoot(u);
        access(v);
        return v.sum;
    }

    public static void main(String[] args) {
        LinkCutTree lct = new LinkCutTree(7);
        for (int i = 1; i <= 7; i++) {
            lct.update(i, i);
        }
        lct.link(1, 2);
        lct.link(2, 3);
        lct.link(3, 4);
        lct.link(5, 6);
        lct.link(6, 7);

        System.out.println(lct.connected(1, 4));
        System.out.println(lct.query(1, 4));
        System.out.println(lct.connected(1, 5));

        lct.link(4, 5);
        System.out.println(lct.connected(1, 7));
        System.out.println(lct.query(2, 7));

        lct.cut(3, 4);
        System.out.println(lct.connected(1, 7));
        System.out.println(lct.query(1, 3));

        lct.update(2, 20);
        System.out.println(lct.query(1, 3));
    }
}
