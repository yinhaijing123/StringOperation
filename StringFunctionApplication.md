>判断一个字符串是否为另外一个字符串旋转之后的字符串。 
>例如：给定s1 ＝ AABCD和s2 = BCDAA，返回1，给定s1=abcd和s2=ACBD，返回0. 

____

####法二：


```c
int Judge(char str1[],char str2[],int size)
{
	
	if (strcmp(str1, str2) == 0)
	{
		return -1;
	}
	strncat(str1, str1,size);
	if (strstr(str1, str2) != NULL)
	{
		return 1;
	}
	return 0;
}

int main()
{
	char str1[] = "AABCD";
	char str2[] = "AABCD";
	int ret = 0;
	int sz1 = strlen(str1);
	int sz2 = strlen(str2);
	if (sz1 == sz2)
	{
		ret = Judge(str1, str2,sz1);
	}
	
	if (ret == 1)
	{
		printf("str2是str1旋转之后得到的字符串\n");
	}
	else if (ret==0)
	{
		printf("str2不是str1旋转之后得到的字符串\n");
	}
	else if (ret == -1)
	{
		printf("str1与str2相等\n");
	}
	
	system("pause");
	return 0;
}

```