#include <stdio.h>
#include <stdlib.h>

// khai bao cau truc node
struct node {
    int data;              // du lieu cua node
    struct node* next;     // con tro toi node tiep theo
};

// ham tao node moi (dua theo lecture 6)
struct node* nalloc(int data) {
    struct node* p = (struct node*)malloc(sizeof(struct node));

    if (p != NULL) {
        p->data = data;
        p->next = NULL;
    }

    return p;
}

// (a) hien thi danh sach
void display(struct node* head) {
    struct node* p;

    // duyet danh sach
    for (p = head; p != NULL; p = p->next) {
        printf("%d -> ", p->data);
    }
    printf("NULL\n");
}

// (b) them vao cuoi danh sach
struct node* addback(struct node* head, int data) {
    struct node* p = nalloc(data);

    if (p == NULL) return head;

    // neu danh sach rong
    if (head == NULL) {
        return p;
    }

    struct node* temp = head;

    // di toi node cuoi cung
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // noi node moi vao cuoi
    temp->next = p;

    return head;
}

// (c) tim node co gia tri data
struct node* find(struct node* head, int data) {
    struct node* p;

    for (p = head; p != NULL; p = p->next) {
        if (p->data == data) {
            return p; // tim thay
        }
    }

    return NULL; // khong tim thay
}

// (d) xoa node pelement
struct node* delnode(struct node* head, struct node* pelement) {
    if (head == NULL || pelement == NULL) return head;

    // truong hop xoa node dau
    if (head == pelement) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct node* prev = head;

    // tim node truoc node can xoa
    while (prev->next != NULL && prev->next != pelement) {
        prev = prev->next;
    }

    // neu tim thay
    if (prev->next == pelement) {
        prev->next = pelement->next;
        free(pelement);
    }

    return head;
}

// (e) giai phong toan bo danh sach
void freelist(struct node* head) {
    struct node* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// (f) ham main de test
int main() {
    struct node* head = NULL;

    // them phan tu
    head = addback(head, 10);
    head = addback(head, 20);
    head = addback(head, 30);
    head = addback(head, 40);

    printf("Danh sach ban dau:\n");
    display(head);

    // tim phan tu
    struct node* p = find(head, 20);
    if (p != NULL) {
        printf("Tim thay: %d\n", p->data);
    } else {
        printf("Khong tim thay\n");
    }

    // xoa phan tu
    head = delnode(head, p);

    printf("Danh sach sau khi xoa 20:\n");
    display(head);

    // giai phong bo nho
    freelist(head);

    return 0;
}

