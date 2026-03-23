/* Hãy viết một chương trình để so sánh hai tệp (file) với nhau, và in ra dòng đầu tiên mà hai tệp này khác nhau.
 *
 * B1: nhap 2 file de so sanh 
 * 	Su dung cau lenh: ./compare file1.txt file2.txt
 * B2: Mo 2 file, neu khong mo duoc -> bao loi
 * B3: So sanh tung dong
 * 	- 2 dong giong nhau -> tiep tuc doc
 * 	- 2 dong khac nhau -> dung chuong trinh va in so dong, in noi dung 2 dong do
 * B4: Ktra: neu doc den cuoi file ma khong cos dong nao khacs nhau -> 2 file giong nhau :)))
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *f1, *f2;          // con tro file cho file
    char line1[1000];       // luu mot dong tu file1
    char line2[1000];       // luu mot dong tu file2
    int line = 1;           // dem so dong

    // ktra tham so nhap vao tu dong lenh
    if (argc != 3)
    {
        printf("Cach dung: %s file1 file2\n", argv[0]);
        return 1;
    }

    // mo file thu nhat
    f1 = fopen(argv[1], "r");

    // mo file thu hai
    f2 = fopen(argv[2], "r");

    // ktra neu khong mo duoc file
    if (f1 == NULL || f2 == NULL)
    {
        printf("Khong mo duoc file\n");
        return 1;
    }

    // doc tung dong cua hai file dong thoi
    while (fgets(line1, sizeof(line1), f1) != NULL &&
           fgets(line2, sizeof(line2), f2) != NULL)
    {
        // so sanh hai dong
        if (strcmp(line1, line2) != 0)
        {
            // neu hai dong khac nhau thi in ra thong tin
            printf("Hai file khac nhau tai dong %d\n", line);
            printf("File1: %s", line1);
            printf("File2: %s", line2);

            // dung chuong trinh
            fclose(f1);
            fclose(f2);
            return 0;
        }

        // tang so dong len
        line++;
    }

    // neu khong co dong nao khac nhau
    printf("Hai file giong nhau\n");

    // dong hai file
    fclose(f1);
    fclose(f2);

    return 0;
}
