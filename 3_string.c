#include "main.h"

/**
 * *_memcpy - copies memory area
 * @dest: destination string
 * @src: source string
 * @n: number of bytes
 * Return: pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * *_memset - fills memory with a constant byte
 * @s: pointer to string s
 * @b: constant byte
 * @n: number of bytes of memory
 * Return: pointer to s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}

/**
 * _itoa - Convert Integer To Char
 * @n: Int To Convert
 * Return: Char Pointer
 */
char *_itoa(unsigned int n)
{
	int len = 0, i = 0, num;
	char *s;
	char temp;

	num = n;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';

	for (i = 0; i < (len / 2); i++)
	{
		temp = s[i];
		s[i] = s[(len - 1) - i];
		s[(len - 1) - i] = temp;
	}
	s[i + 1] = '\0';
	return (s);
}