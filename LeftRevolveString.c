/*********************************************************
实现一个函数，可以左旋字符串中的k个字符。
如：ABCD左旋一个字符得到BCDA；ABCD左旋两个字符得到CDAB
*********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//法一：每次左旋一个字符，旋转times次(以下为法一实现代码)
void RevolveOnce(char *str, int lenth)
{
	assert(str);
	assert(lenth > 0);

	int i = 0;
	char tmp = str[0];
	for (i = 0; i < lenth - 1; i++)
	{
		str[i] = str[i + 1];
	}
	str[i] = tmp;
}

void LeftRevolveString1(char *str, int lenth, int times)
{
	assert(str);
	assert(lenth > 0);
	assert(times > 0);

	int revolve_times = times % lenth;

	while (revolve_times--)
	{
		RevolveOnce(str, lenth);
	}
}

//法二：利用局部逆置，局部逆置，再整体逆置(以下为法二代码)

void Swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void reverse(char *start_reverse, char *end_reverse)
{
	assert(start_reverse);
	assert(end_reverse);

	while (start_reverse < end_reverse)
	{
		Swap(start_reverse, end_reverse);
		start_reverse++;
		end_reverse--;
	}
}

void LeftRevolveString2(char *str, int lenth, int times)
{
	assert(str);
	assert(lenth > 0);
	assert(times > 0);

	int revolve_times = times % lenth;
	
	reverse(str, str + revolve_times - 1);
	reverse(str + revolve_times, str + lenth - 1);
	reverse(str, str + lenth - 1);

}

//法三:利用某字符串旋转后的字符串，必定为拼接其自己的字符串的子字符串

void LeftRevolveString(char *str, int lenth, int times)
{
	assert(str);
	assert(lenth > 0);
	assert(times > 0);

	int revolve_times = times % lenth;
	char *str1 = (char *)malloc(lenth * 2);
	strcpy(str1, str);
	strcat(str1, str);
	strncpy(str, str1 + revolve_times, lenth);
}

int main()
{
	char str[] = "ABCD1234";
	int lenth = strlen(str);  //注意其结果不包含'\0';若用sizeof()求解结果包含'\0'.
	int times = 0;

	printf("请输入旋转次数：");
	scanf("%d", &times);

	printf("Before:%s\n", str);
	LeftRevolveString(str, lenth, times);
	printf("After:%s\n", str);      //ret为0表示yes;ret为-1则表示no;

	system("pause");
	return 0;
}