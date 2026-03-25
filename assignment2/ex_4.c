/* Chuyen so nguyen n sang chuoi ki tu co so b, luu ket qua vao chuoi s
 *
 * -> chia lay phan du
 * -> lay phan du tu duoi len tren
 **/

#include <stdio.h>

/* đảo chuỗi */
void reverse(char s[])
{
    int i, j;
    char temp;

    for(j = 0; s[j] != '\0'; j++)
        ;

    j--;

    for(i = 0; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}


/* chuyển số n sang chuỗi ở cơ số b */
void itob(int n, char s[], int b)
{
    int i = 0;
    int sign;
    int digit;

    sign = n;

    do
    {
        digit = n % b;

        if(digit < 0)
            digit = -digit;

        if(digit <= 9)
            s[i++] = digit + '0';
        else
            s[i++] = digit - 10 + 'A';

    } while((n /= b) != 0);

    if(sign < 0)
        s[i++] = '-';

    s[i] = '\0';

    reverse(s);
}

int main()
{
    int n, base;
    char s[100];

    printf("Nhap so: ");
    scanf("%d", &n);

    printf("Nhap co so: ");
    scanf("%d", &base);

    itob(n, s, base);

    printf("Ket qua: %s\n", s);

    return 0;
}
