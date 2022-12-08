#include <stdio.h>
#include <stdlib.h>

unsigned int HashRot13(char* str);


int main()
{
	int results[] = { -1519094430, -827415954, -2075482121 };
	int count = 0;
	char* buffer = (char*)malloc(sizeof(char) * 6);
	for (char i = 'A'; i < 'z'; i++)
	{
		for (char j = 'A'; j < 'z'; j++)
		{
			for (char k = 'A'; k < 'z'; k++)
			{
				for (char p = 'A'; p < 'z'; p++)
				{
					for (char t = 'A'; t < 'z'; t++)
					{
						buffer[0] = i;
						buffer[1] = j;
						buffer[2] = k;
						buffer[3] = p;
						buffer[4] = t;
						buffer[5] = '\0';
						int res = HashRot13(buffer);
						for (int c = 0; c < 3; c++)
						{
							if (res == results[c])
							{
								printf_s("%s ", buffer);
								count++;
								if (count == 3) return 0;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

unsigned int HashRot13(char* str)
{
	unsigned int hash = 0;
	for (; *str; str++)
	{
		hash += (unsigned char)(*str);
		hash -= (hash << 13) | (hash >> 19);
	}
	return hash;
}