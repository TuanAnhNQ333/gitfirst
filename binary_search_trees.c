#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// dinh nghia cau truc cho node trong binary search tree
struct Node
{
    int key;
    struct Node * left;
    struct Node * right;
};
// ham tao 1 node moi
struct Node * newNode(int item)
{
    struct Node*temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
// ham chen 1 khoa vao binary search tree
struct Node* insert(struct Node*node, int key)
{
    // neu cay rong, tra ve nut moiz
    if(node == NULL) return newNode(key);
    // duyet cay de chen
    if(key < node->key)
    {
        node -> left = insert(node->left, key);
    }
    else if (key > node->key) 
    {
        node -> right = insert(node->right, key);
    }
    return node;
}
// ham duyet pre-order binary search
void preOrder(struct Node* root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
    struct Node * root = NULL;
    char command[50];
    int key;
    while(1)
    {
        fgets(command, sizeof(command), stdin);
        // kiem tra dong #
        if(command[0] == '#')
        {
            break;
        }
        // kiem tra dong lenh insert
        if(strncmp(command, "insert", 6) == 0)
        {
            int key;
            // xuat gia tri k 
            sscanf(command + 7, "%d", &key);
            root = insert(root, key);
        }
    }
    preOrder(root);
    return 0;
}