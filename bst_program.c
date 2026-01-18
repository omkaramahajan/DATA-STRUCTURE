#include <stdio.h>
#include <stdlib.h>

typedef struct bst {
    int data;
    struct bst *left, *right;
} BST;

BST* create() {
    int n, value;
    BST *root = NULL;

    printf("Enter how many nodes?: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &value);

        BST *temp = (BST*)malloc(sizeof(BST));
        temp->data = value;
        temp->left = temp->right = NULL;

        if(root == NULL) {
            root = temp;
        } else {
            BST *curr = root, *parent = NULL;
            while(curr != NULL) {
                parent = curr;
                if(value < curr->data)
                    curr = curr->left;
                else
                    curr = curr->right;
            }
            if(value < parent->data)
                parent->left = temp;
            else
                parent->right = temp;
        }
    }
    return root;
}

BST* insert(BST* root, int value) {
    if(root == NULL) {
        BST* temp = (BST*)malloc(sizeof(BST));
        temp->data = value;
        temp->left = temp->right = NULL;
        return temp;
    }
    if(value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

void search(BST *root, int t) {
    while(root != NULL) {
        if(t == root->data) {
            printf("Found!\n");
            return;
        }
        root = (t < root->data) ? root->left : root->right;
    }
    printf("Not Found!\n");
}

void inorder(BST *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(BST *root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(BST *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    BST *root = NULL;
    int ch, t;

    while(1) {
        printf("\n*WELCOME*\n");
        printf("1. create\n2. search\n3. insert\n4. inorder\n5. preorder\n6. postorder\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                root = create();
                printf("\nBST CREATED\n");
                break;
            case 2:
                printf("\nEnter data to search: ");
                scanf("%d", &t);
                search(root, t);
                break;
            case 3:
                printf("\nEnter data to insert: ");
                scanf("%d", &t);
                root = insert(root, t);
                break;
            case 4:
                printf("\nInorder:\n");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("\nPreorder:\n");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("\nPostorder:\n");
                postorder(root);
                printf("\n");
                break;
            default:
                printf("\nEnter valid option!!\n");
                exit(0);
        }
    }
    return 0;
}
