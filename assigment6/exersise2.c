#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 100
#define MAXLEN   1000

// Mang luu cac dong input
char *lineptr[MAXLINES];

// Bien option
int numeric = 0;     // -n: so sanh theo so
int fold = 0;        // -f: khong phan biet hoa/thuong
int directory = 0;   // -d: bo ky tu dac biet
int field_num = 1;   // -k: chon cot (mac dinh cot 1)


// Ham doc du lieu tu stdin
int readlines(char *lineptr[], int maxlines) {
    int len, nlines = 0;
    char buffer[MAXLEN];

    // Doc tung dong
    while (fgets(buffer, MAXLEN, stdin) != NULL) {

        len = strlen(buffer);

        // Xoa dau newline
        if (buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';

        // Cap phat bo nho
        lineptr[nlines] = (char *)malloc(len);

        // Copy du lieu
        strcpy(lineptr[nlines], buffer);

        nlines++;
    }

    return nlines;
}


// Ham lay field thu k trong 1 dong
char *get_field(char *line, int field) {
    static char temp[MAXLEN];

    // Copy chuoi vi strtok se lam thay doi chuoi
    strcpy(temp, line);

    // Tach chuoi theo khoang trang
    char *token = strtok(temp, " \t");
    int count = 1;

    while (token != NULL) {

        if (count == field)
            return token;

        token = strtok(NULL, " \t");
        count++;
    }

    return "";
}


// Ham loc ky tu (chi giu chu va so) - option -d
void filter(char *dest, char *src) {
    int j = 0;

    for (int i = 0; src[i]; i++) {

        // Chi giu ky tu chu va so
        if (isalnum(src[i]) || isspace(src[i])) {
            dest[j++] = src[i];
        }
    }

    dest[j] = '\0';
}


// Ham so sanh (quan trong nhat)
int compare(const void *a, const void *b) {

    // Lay 2 dong can so sanh
    char *s1 = *(char **)a;
    char *s2 = *(char **)b;

    // Lay field can so sanh
    char *f1 = get_field(s1, field_num);
    char *f2 = get_field(s2, field_num);

    char temp1[MAXLEN], temp2[MAXLEN];

    // Neu co -d thi loc ky tu dac biet
    if (directory) {
        filter(temp1, f1);
        filter(temp2, f2);
        f1 = temp1;
        f2 = temp2;
    }

    // Neu co -f thi chuyen ve chu thuong
    if (fold) {
        for (int i = 0; f1[i]; i++) f1[i] = tolower(f1[i]);
        for (int i = 0; f2[i]; i++) f2[i] = tolower(f2[i]);
    }

    // Neu co -n thi so sanh so
    if (numeric) {
        double v1 = atof(f1);
        double v2 = atof(f2);

        if (v1 < v2) return -1;
        else if (v1 > v2) return 1;
        else return 0;
    }

    // Mac dinh so sanh chuoi
    return strcmp(f1, f2);
}


// Ham in ket qua
void writelines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}


// Ham main
int main(int argc, char *argv[]) {

    int nlines;

    // Doc option tu command line
    for (int i = 1; i < argc; i++) {

        if (strcmp(argv[i], "-n") == 0)
            numeric = 1;

        else if (strcmp(argv[i], "-f") == 0)
            fold = 1;

        else if (strcmp(argv[i], "-d") == 0)
            directory = 1;

        // -k2 -> chon cot 2
        else if (strncmp(argv[i], "-k", 2) == 0)
            field_num = atoi(argv[i] + 2);
    }

    // Doc du lieu
    nlines = readlines(lineptr, MAXLINES);

    // Sap xep
    qsort(lineptr, nlines, sizeof(char *), compare);

    // In ket qua
    writelines(lineptr, nlines);

    return 0;
}