>判断一个字符串是否为另外一个字符串旋转之后的字符串。 
>例如：给定s1 ＝ AABCD和s2 = BCDAA，返回1，给定s1=abcd和s2=ACBD，返回0. 

____

代码如下：

```c

int Judge(char str1[], char str2[],int size)
{
	int sz = size; 
	char* str = str1;
	if (strcmp(str1, str2) == 0)
	{
		return -1;
	}
	while (sz--)
	{
		int i = 0;
		char tmp = 0;
		tmp = str[0];
		for (i = 0; i <size - 1;i++)
		{
			str[i] = str[i + 1];     //如若size是用sizeof求出的，\
			                           则边界条件需修改为i<size-2.\
					           因为它不应该先拷贝'\0',再拷贝tmp。
		}
		str[size - 1] = tmp;
		if (strcmp(str, str2) == 0)
		{
			return 1;
		}
	}
	
	return 0;
}


int main()
{
	char str1[] = "AABCD";
	char str2[] = "BCDAA";
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
