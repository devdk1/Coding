import java.util.LinkedList;
import java.util.Queue;

public class BinaryTree {

    public static class Node {
    
        int key;
        Node left, right;

        Node(int key) {
            this.key = key;
            this.left = null;
            this.right = null;
        }
    }

    public static Node root;
    public static Node temp;

    public static void inOrder(Node temp) {
        if(temp == null)
            return;
        inOrder(temp.left);
        System.out.print(temp.key+" ");
        inOrder(temp.right);
    }

    public static void insert(Node temp, int data) {
        Queue<Node> que = new LinkedList<>();
        que.add(temp);

        while (!que.isEmpty()) {
            temp = que.peek();
            que.remove();

            if(temp.left == null) {
                temp.left = new Node(data);
                break;
            }
            else {
                que.add(temp.left);
            }

            if(temp.right == null) {
                temp.right = new Node(data);
                break;
            }
            else
                que.add(temp.right);
        }
    }

    public static void deleteDeepest(Node temp, Node deepest) {
        Queue<Node> que = new LinkedList<>();
        que.add(temp);

        while (!que.isEmpty()) {
            temp = que.peek();
            que.remove();

            if(temp == deepest) {
                temp = null;
                return;
            }
            if(temp.left != null) {
                if(temp.left == deepest) {
                    temp.left = null;
                    return;
                }
                else
                    que.add(temp.left);
            }
            if(temp.right != null) {
                if(temp.right == deepest) {
                    temp.right = null;
                    return;
                }
                else
                    que.add(temp.right);
            }
        }
    }

    public static Node deletion(Node root, int data) {
        if(root == null)
            return null;
        if(root.left == null && root.right == null) {
            if(root.key == data) {
                return null;
            }
            else {
                return root;
            }
        }

        Node temp = root;
        Queue<Node> que = new LinkedList<>();
        que.add(temp);
        Node key_node = null;

        while (!que.isEmpty()) {
            temp = que.peek();
            que.remove();

            if(temp.key == data)
                key_node = temp;
            if(temp.left != null)
                que.add(temp.left);
            if(temp.right != null)
                que.add(temp.right);
        }

        if(key_node != null) {
            int x = temp.key;
            deleteDeepest(root, temp);
            key_node.key = x;
        }
        return root;
    }

    public static void main(String args[]) {
        root = new Node(1);
        root.left = new Node(2);
        root.left.left = new Node(4);
        root.left.right = new Node(5);

        root.right = new Node(3);

        System.out.println( "Inorder traversal before insertion:"); 
        inOrder(root);
        System.out.println();
        insert(root, 6);
        insert(root, 7);
        System.out.println( "Inorder traversal after insertion:"); 
        inOrder(root);
        System.out.println();

        
        System.out.println( "Inorder traversal before deletion:"); 
        inOrder(root);
        System.out.println();

        Node node = deletion(root, 3);
        System.out.println( "Inorder traversal after deletion:");
        inOrder(node);
        System.out.println();
    }
}