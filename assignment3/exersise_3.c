/* viet chuong trinh in ra noi dung cua nhieu tep
 * Moi tep phai bat dau in o mot trang moi
 * Moi trang phi co tieu de, deer biet ten cua tep dang duoc in
 * moi tep co so trang ddanh lien tuc
 *
 * Y tuong:
 * 	truyen cac file vaof VD: ./print file1.txt file2.txt file3.txt
 * 	dung vong lap de su ly tung file
 * 	mo file ra 
 * 	in tieeu de trang, doc tung dong cua file, in noi dung
 * 	dem so dong trong trang 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define PAGELEN 20   // so dong moi trang

int main(int argc, char *argv[])
{
    FILE *fp;                // con tro file
    char line[MAXLINE];      // luu mot dong doc tu file
    int page;                // bien dem so trang
    int line_count;          // dem so dong trong trang
    int i;                   // bien lap qua cac file

    // kiem tra nguoi dung co nhap file hay khong
    if (argc < 2)
    {
        printf("Cach dung: %s file1 file2 ...\n", argv[0]);
        return 1;
    }

    // lap qua tung file duoc truyen tu dong lenh
    for (i = 1; i < argc; i++)
    {
        // mo file o che do doc
        fp = fopen(argv[i], "r");

        // kiem tra neu khong mo duoc file
        if (fp == NULL)
        {
            printf("Khong mo duoc file %s\n", argv[i]);
            continue;
        }

        // khoi tao trang dau tien
        page = 1;
        line_count = 0;

        // in tieu de trang dau tien
        printf("\n===== File: %s   Page: %d =====\n", argv[i], page);

        // doc tung dong trong file
        while (fgets(line, MAXLINE, fp) != NULL)
        {
            // in dong ra man hinh
            printf("%s", line);

            // tang so dong trong trang
            line_count++;

            // neu da du so dong trong mot trang
            if (line_count == PAGELEN)
            {
                // sang trang moi
                page++;
                line_count = 0;

                // in tieu de trang moi
                printf("\n===== File: %s   Page: %d =====\n", argv[i], page);
            }
        }

        // dong file sau khi doc xong
        fclose(fp);
    }

    return 0;
}
