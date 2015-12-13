void LevelOrder(Node root) {
    int h = height(root);

    for (int i = 1; i <= h; i++) {
        print(root, 1, i);
        }
}

int height(Node root) {
    if (null == root) {
        return 0;
    }
    return Math.max(height(root.left), height(root.right)) + 1;
}

void print(Node n, int currentLevel, int level) {
    if (null == n) {
        return;
    }

    if (currentLevel == level) {
        System.out.print(n.data + " ");
        return;
    }

    print(n.left, currentLevel + 1, level);
    print(n.right, currentLevel + 1, level);
}