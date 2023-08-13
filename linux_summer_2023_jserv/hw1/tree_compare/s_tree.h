#ifndef S_TREE_H
#define S_TREE_H

#define st_root(r) (r->root)
#define st_left(n) (n->left)
#define st_right(n) (n->right)
#define st_rparent(n) (st_right(n)->parent)
#define st_lparent(n) (st_left(n)->parent)
#define st_parent(n) (n->parent)

/* S-Tree uses hints to decide whether to perform a balancing operation or not.
 * Hints are similar to AVL-trees' height property, but they are not
 * required to be absolutely accurate. A hint provides an approximation
 * of the longest chain of nodes under the node to which the hint is attached.
 */
struct st_node
{
    short hint;
    struct st_node *parent;
    struct st_node *left, *right;
};

struct st_root
{
    struct st_node *root;
};

enum st_dir
{
    LEFT,
    RIGHT
};

/* The process of insertion is straightforward and follows the standard approach
 * used in any BST. After inserting a new node into the tree using conventional
 * BST insertion techniques, an update operation is invoked on the newly
 * inserted node.
 */

void st_insert(struct st_node **root,
               struct st_node *p,
               struct st_node *n,
               enum st_dir d);

/* The process of deletion in this tree structure is relatively more intricate,
 * although it shares similarities with deletion methods employed in other BST.
 * When removing a node, if the node to be deleted has a right child, the
 * deletion process entails replacing the node to be removed with the first node
 * encountered in the right subtree. Following this replacement, an update
 * operation is invoked on the right child of the newly inserted node.
 *
 * Similarly, if the node to be deleted does not have a right child, the
 * replacement process involves utilizing the first node found in the left
 * subtree. Subsequently, an update operation is called on the left child of th
 * replacement node.
 *
 * In scenarios where the node to be deleted has no children (neither left nor
 * right), it can be directly removed from the tree, and an update operation is
 * invoked on the parent node of the deleted node.
 */
void st_remove(struct st_node **root, struct st_node *del);


int treeint_destroy();

struct treeint *treeint_insert(int a);
struct treeint *treeint_find(int a);
int treeint_remove(int a);
void treeint_dump();
struct st_node *st_first(struct st_node *n);
struct st_node *st_last(struct st_node *n);

#endif