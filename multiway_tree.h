#ifndef MULTIWAY_TREE_H_INCLUDED
#define MULTIWAY_TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define M 4
#define MIN_KEYS (M / 2)

struct node
{
    int num_keys;
    int keys[M - 1];
    struct node *children[M];
};

struct node* createNode(int x);
struct node* insert(struct node *root, int x);
void deleteKeyFromLeaf(struct node *leaf, int index);
int findKeyIndex(struct node *root, int x);
struct node* deleteValue(struct node *root, int x);
void inorderTraversal(struct node *root);
int search(struct node *root, int x);
void printTree(struct node *root);
void printTreeNode(struct node *root, int depth);

#endif // MULTIWAY_TREE_H_INCLUDED
