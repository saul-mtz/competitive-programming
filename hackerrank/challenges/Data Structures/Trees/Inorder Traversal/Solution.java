void Inorder(Node root) {
    if (null == root) {
        return;
    }

    Inorder(root.left);
    System.out.print(root.data + " ");
    Inorder(root.right);
}