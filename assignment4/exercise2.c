#include <stdio.h>
#include <stdlib.h>

// cau truc node cua cay nhi phan
struct tnode {
    int data;              // du lieu
    struct tnode* left;    // con trai
    struct tnode* right;   // con phai
};

// (a) tao node moi
struct tnode* createNode(int data) {
    struct tnode* p = (struct tnode*)malloc(sizeof(struct tnode));

    if (p != NULL) {
        p->data = data;
        p->left = NULL;
        p->right = NULL;
    }

    return p;
}

// (b) them node vao cay (BST)
struct tnode* addnode(struct tnode* root, int data) {

    // neu cay rong -> tao node moi
    if (root == NULL) {
        return createNode(data);
    }

    // neu nho hon -> chen ben trai
    if (data < root->data) {
        root->left = addnode(root->left, data);
    }
    // neu lon hon -> chen ben phai
    else if (data > root->data) {
        root->right = addnode(root->right, data);
    }

    return root;
}

// (c) duyet cay inorder (in tang dan)
void inorder(struct tnode* root) {
    if (root == NULL) return;

    inorder(root->left);          // trai
    printf("%d ", root->data);    // goc
    inorder(root->right);         // phai
}

// (d) tim kiem node
struct tnode* search(struct tnode* root, int data) {

    if (root == NULL) return NULL;

    if (data == root->data) return root;

    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

// ham tim node nho nhat ben phai (dung cho delete)
struct tnode* findMin(struct tnode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// (e) xoa node
struct tnode* deleteNode(struct tnode* root, int data) {

    if (root == NULL) return NULL;

    // tim node can xoa
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        // DA TIM THAY NODE

        // case 1: khong co con
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // case 2: chi co 1 con ben phai
        else if (root->left == NULL) {
            struct tnode* temp = root->right;
            free(root);
            return temp;
        }

        // case 2: chi co 1 con ben trai
        else if (root->right == NULL) {
            struct tnode* temp = root->left;
            free(root);
            return temp;
        }

        // case 3: co 2 con
        else {
            // tim node nho nhat ben phai
            struct tnode* temp = findMin(root->right);

            // copy gia tri
            root->data = temp->data;

            // xoa node vua tim
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

// giai phong cay (postorder)
void freeTree(struct tnode* root) {
    if (root == NULL) return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// (f) ham main de test
int main() {
    struct tnode* root = NULL;

    // tao cay
    root = addnode(root, 50);
    root = addnode(root, 30);
    root = addnode(root, 70);
    root = addnode(root, 20);
    root = addnode(root, 40);
    root = addnode(root, 60);
    root = addnode(root, 80);

    printf("Cay (inorder): ");
    inorder(root);
    printf("\n");

    // tim kiem
    struct tnode* p = search(root, 40);
    if (p != NULL)
        printf("Tim thay: %d\n", p->data);
    else
        printf("Khong tim thay\n");

    // xoa node
    root = deleteNode(root, 30);

    printf("Sau khi xoa 30: ");
    inorder(root);
    printf("\n");

    // giai phong bo nho
    freeTree(root);

    return 0;
}
