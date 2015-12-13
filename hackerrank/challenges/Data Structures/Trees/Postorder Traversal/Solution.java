void Postorder(Node root) {
    if (null == root) {
        return;
    }

    Postorder(root.left);
    Postorder(root.right);
    System.out.print(root.data + " ");
}