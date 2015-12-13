void top_view(Node root) {
    print(root.left, true);
    System.out.print(root.data + " ");
    print(root.right, false);
}

void print(Node n, boolean left) {
    if (null == n) {
        return;
    }

    if (left) {
        print(n.left, true);
        System.out.print(n.data + " ");
    } else {
        System.out.print(n.data + " ");
        print(n.right, false);
    }
}
