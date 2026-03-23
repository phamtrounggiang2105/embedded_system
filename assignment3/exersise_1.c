/* Bai yeu cau viet mot chuong trinh chuyen doi chu hoa va chu thuong, nhung cach chuyen doi phu thuoc vao ten chuong trinh khi chay.
Chuong trinh se lay ten cua chinh no tu argv[0] de quyet dinh:
neu ten chuong trinh la lower → chuyen chu hoa thanh chu thuong
neu ten chuong trinh la upper → chuyen chu thuong thanh chu hoa */


#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])   // argc: so tham so ; argv: mang chua tham so
{
    int c;   // tung ky tu doc tu ban phim

    // kiem tra ten chuong trinh duoc goi
    if (strstr(argv[0], "lower") != NULL)
    {
        // neu ten chuong trinh la lower
        // chuyen chu hoa thanh chu thuong

        while ((c = getchar()) != EOF)
        {
            putchar(tolower(c));
        }
    }
    else if (strstr(argv[0], "upper") != NULL)
    {
        // neu ten chuong trinh la upper
        // chuyen chu thuong thanh chu hoa

        while ((c = getchar()) != EOF)
        {
            putchar(toupper(c));
        }
    }
    else
    {
        // neu ten chuong trinh khong phai lower hoac upper
        printf("Ten chuong trinh phai la lower hoac upper\n");
    }

    return 0;
}
