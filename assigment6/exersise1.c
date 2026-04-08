#include <stdio.h>
#include <string.h>

// Ham strend: kiem tra chuoi t co nam o CUOI chuoi s hay khong
int strend(char *s, char *t) {

    // Lay do dai 2 chuoi
    int len_s = strlen(s);
    int len_t = strlen(t);

    // Neu t dai hon s -> khong the la hau to
    if (len_t > len_s) {
        return 0;
    }

    // So sanh tung ky tu cua t voi phan cuoi cua s
    for (int i = 0; i < len_t; i++) {

        // s[len_s - len_t + i] la vi tri bat dau o cuoi chuoi s
        if (s[len_s - len_t + i] != t[i]) {
            return 0;   // Khac nhau -> khong phai hau to
        }
    }

    return 1;   // Giong het -> la hau to
}


// Ham main de test
int main() {

    char s[100], t[100];

    printf("Nhap chuoi s: ");
    scanf("%s", s);

    printf("Nhap chuoi t: ");
    scanf("%s", t);

    // Goi ham kiem tra
    if (strend(s, t)) {
        printf("t la hau to cua s\n");
    } else {
        printf("t KHONG la hau to cua s\n");
    }

    return 0;
}