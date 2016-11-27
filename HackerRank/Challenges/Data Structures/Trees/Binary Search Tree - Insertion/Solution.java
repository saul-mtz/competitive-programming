/**
 * @see https://www.hackerrank.com/challenges/binary-search-tree-insertion
 */
static Node Insert(Node n, int value) {
    if (null == n) {
        n = new Node();
        n.data = value;
    } else if (value > n.data) {
        n.right = Insert(n.right, value);
    } else if (value < n.data) {
        n.left= Insert(n.left, value);
    }

    return n;
}