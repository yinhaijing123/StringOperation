
/*********************************************************************************
例：有一个字符数组的内容为:"student a am i",请你将数组的内容改为"i am a student". 
要求:不能使用库函数。只能开辟有限个空间（空间个数和字符串的长度无关）。
*********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

void Swap(char *a, char *b)
{
	assert(a);
	assert(b);

	char tmp = *a;
	*a = *b;
	*b = tmp;
}

//单词逆置
void ReverseWord(char *word_start,char *word_end)
{

	assert(word_start);
	assert(word_end);

	while (word_start < word_end)
	{
		Swap(word_start,word_end);  
		word_start++;
		word_end--;
	}
}

//整体逆置
void ReverseString(char *str, char *str_end)
{
	assert(str);
	assert(str_end);

	char *word_start = str;
	char *word_end = str;
	while (*word_end != '\0')
	{
		while (((*word_end) != ' ') && ((*word_end) != '\0'))
		{
			word_end++;
		}
		if (*word_end == ' ')
		{
			ReverseWord(word_start, word_end-1);
			word_end++;
			word_start = word_end;
			continue;
		}
	}

	while (str < str_end)
	{
		Swap(str, str_end);
		str++;
		str_end--;
	}


}

int main()
{
	char str[] = "student a am i";

	int lenth = strlen(str);
	ReverseString(str, str+lenth-1); 

	printf("%s\n", str);
	
	system("pause");
	return 0;
}