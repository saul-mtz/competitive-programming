void Preorder(Node root) {
    if (null == root) {
        return;
    }

    System.out.print(root.data + " ");
    Preorder(root.left);
    Preorder(root.right);
}