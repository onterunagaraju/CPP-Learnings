#include<iostream>

int myAtoI(char* str)
{
	int result = 0;
	int index = 0;
	int sign = 1;
	if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	for (;str[index] != '\0'; index++)
	{
		result = result * 10 + str[index] - '0';
	}
	return result * sign;
}

//int main()
//{
//	char str[] = "1234";
//	char str2[] = "-6574";
//	int ans = myAtoI(str);
//	std::cout << ans << std::endl;
//	std::cout << myAtoI(str2) << std::endl;
//	return 0;
//}