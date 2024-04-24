#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

// Function to create a new node
node* createNode(int data) {
    node* newNode = malloc(sizeof(node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
node* insertNode(node* root, int data) {
    // If the tree is empty, assign a new node address to root
    if (root == NULL) {
        root = createNode(data);
    }
    // Else, decide to go left or right 
    else if (data < root->data) {
        // It's lesser. We need to go left!
        root->left = insertNode(root->left, data);
    }
    else {
        // It's greater. We need to go right!
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to search a node in the BST
node* searchNode(node* root, int data) {
    // Traverse until root reaches to NULL
    while (root != NULL) {
        // pass right subtree as new tree
        if (data > root->data)
            root = root->right;

        // pass left subtree as new tree
        else if (data < root->data)
            root = root->left;
        else
            return root; // data found
    }
    return root;
}

// Function to find the minimum value in a node
node* findMinimum(node* root) {
    while(root->left != NULL) root = root->left;
    return root;
}

// Function to delete a node in the BST
node* deleteNode(node* root, int data) {
    // Return if the tree is empty
    if (root == NULL) return root;

    // Find the node to be deleted
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // If the node is with only one child or no child
        if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }

        // If the node has two children
        node* temp = findMinimum(root->right);

        // Place the minimum data in the deleting node
        root->data = temp->data;

        // Delete the minimum node in right subtree
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to do inorder traversal
void inorderTraversal(node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to do preorder traversal
void preorderTraversal(node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to do postorder traversal
void postorderTraversal(node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    node* root = NULL;
    root = insertNode(root, 15);   // Inserting values in BST
    insertNode(root, 10);
    insertNode(root, 20);
    insertNode(root, 25);
    insertNode(root, 8);
    insertNode(root, 12);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    node* min = findMinimum(root);
    printf("Minimum element is %d\n", min->data);

    root = deleteNode(root, 10);
    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    node* search = searchNode(root, 20);
    printf("Searched element is %d\n", search->data);

    return 0;
}