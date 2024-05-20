#include "multiway_tree.h"

struct node* createNode(int x)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->num_keys = 1;
    newNode->keys[0] = x;
    for (int i = 0; i < M; i++)
    {
        newNode->children[i] = NULL;
    }
    return newNode;
}

struct node* insert(struct node *root, int x)
{
    if (root == NULL)
    {
        return createNode(x);
    }
    int childIndex = 0;
    while (childIndex < root->num_keys && x > root->keys[childIndex])
    {
        childIndex++;
    }
    root->children[childIndex] = insert(root->children[childIndex], x);
    return root;
}

void deleteKeyFromLeaf(struct node *leaf, int index)
{
    for (int i = index; i < leaf->num_keys - 1; i++)
    {
        leaf->keys[i] = leaf->keys[i + 1];
    }
    leaf->num_keys--;
}

int findKeyIndex(struct node *root, int x)
{
    int i;
    for (i = 0; i < root->num_keys; i++)
    {
        if (root->keys[i] == x)
        {
            return i;
        }
        else if (root->keys[i] > x)
        {
            break;
        }
    }
    return -1;
}

struct node* deleteValue(struct node *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    int keyIndex = findKeyIndex(root, x);
    if (keyIndex != -1)
    {
        if (root->children[0] == NULL)
        {
            deleteKeyFromLeaf(root, keyIndex);
            root->num_keys--;
            return root;
        }
        else
        {
            struct node *predNode = root->children[keyIndex];
            while (predNode->children[predNode->num_keys] != NULL)
            {
                predNode = predNode->children[predNode->num_keys];
            }
            int predKey = predNode->keys[predNode->num_keys - 1];

            root->keys[keyIndex] = predKey;
            root->children[keyIndex] = deleteValue(root->children[keyIndex], predKey);

            return root;
        }
    }

    int childIndex;
    for (childIndex = 0; childIndex < root->num_keys; childIndex++)
    {
        if (x < root->keys[childIndex])
        {
            break;
        }
    }
    root->children[childIndex] = deleteValue(root->children[childIndex], x);
    return root;
}

int search(struct node *root, int x)
{
    if (root == NULL)
    {
        return 0;
    }
    int i;
    for (i = 0; i < root->num_keys; i++)
    {
        if (root->keys[i] == x)
        {
            return 1;
        }
        else if (root->keys[i] > x)
        {
            break;
        }
    }
    if (i < root->num_keys && root->children[i] != NULL)
    {
        int result = search(root->children[i], x);
        if (result != 0)
        {
            return result;
        }
    }
    else
    {
        if (root->children[root->num_keys] != NULL)
        {
            int result = search(root->children[root->num_keys], x);
            if (result != 0)
            {
                return result;
            }
        }
    }

    return 0;
}

void printTree(struct node *root)
{
    if (root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }
    printf("Printing Tree:\n");
    printTreeNode(root, 0);
}

void printTreeNode(struct node *root, int depth)
{
    if (root == NULL)
        return;
    int i;
    for (i = 0; i < root->num_keys; i++)
    {
        printTreeNode(root->children[i], depth + 1);
        for (int j = 0; j < depth; j++)
            printf("    ");
        printf("%d\n", root->keys[i]);
    }
    printTreeNode(root->children[i], depth + 1);
}
