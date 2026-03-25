/* Ham expand(s1, s2) mo rong cac ki tu viet tat
handle cases like a-b-c and a-z0-9 and -a-z
s1 la chuoi dau vao
s2 chuoi output

-> duyet tung ki tu cua s1, gap pattern "x-y" voi y>x thi in cac ki tu tu x+1 den y
-> copy sang s2
*/

#include <stdio.h>

void expand(char s1[], char s2[])
{
	int i, j=0;
	char c;

	// duyet tung phan tu s1 voi dk dung \0
	for (i = 0; s1[i] != '\0'; i++)
	{
	  // Kiem tra pattern
	  if (s1[i] == '-' && i>0 && s1[i+1] != '\0' && s1[i-1] < s1[i+1])
	  {
		// mo rong cac ki tu co trong s1 tu i-1 den i+1
		for (c = s1[i-1] + 1; c <= s1[i+1]; c++) 
		{
			s2[j++] = c;
		}
	  }
	  // neu khong phai '-' thi copy nhu binh thuong
	  else if (s1[i] != '-') 
	  {
		s2[j++] = s1[i];
	  }
	}
	
	s2 [j] = '\0';
}


int main()
{
	char s1[200]; // cho phep nguoi dung nhap tu ban phim
	char s2[200]; // chuoi output

	printf ("Nhap chuoi: ");

	// su dung han doc chuoi tu ban phim de luu vao s1
	fgets (s1, sizeof(s1), stdin);

	expand(s1, s2);

	printf ("Chuoi duoc mo rong thanh: %s", s2);
	
	return 0;
}
