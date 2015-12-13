int height(Node root) {
    if (null == root) {
        return 0;
    }
    return Math.max(height(root.left), height(root.right)) + 1;
}