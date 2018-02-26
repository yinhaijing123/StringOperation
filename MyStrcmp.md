/*******************************************************
Strcmp的实现
*******************************************************/

```char
int MyStrcmp(const char *dst, const char *src)
{
	while ((*dst !='\0')||(*src!='\0'))             
	{
		if (*dst == *src)
		{
			dst++;
			src++;
		}
		else if (*dst > *src)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	if (*dst == '\0'&&*src == '\0')        //仅当dst和src同时为'\0'时，才会到此处
	{
		return 0;
	}
}
```