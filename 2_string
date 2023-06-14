#include "main.h"

/**
 * _strncmp - Compare Amount (n) Of Characters Of Two Strings.
 * @s1: A String.
 * @s2: A String.
 * @n: Amount Of Characters To Compare.
 *
 * Return: 1 If The Strings Don't Match Otherwise 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);
	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}

/**
*_strdup - duplicates a string
*
*@str: string parameter
*
*Return: pointer to a duplicate of str
*/

char *_strdup(char *str)
{
	char *s;
	size_t i = 0, len = 0;

	len = _strlen(str);

	s = malloc(sizeof(char) * (len + 1));

	if (s == NULL)
	{
		free(s);
		return (NULL);
	}

	while (i <= len)
	{
		s[i] = str[i];
		i++;
	}
	return (s);
}
/**
*_isdigit - checks if it is a digit
*
*@c: parameter integer to test
*
*Return: 1 if its )-9 else 0
*/

int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
*_atoi - converts string to integer
*
*@s: pointer to string
*
*Return: integer from string
*/
int _atoi(char *s)
{
	unsigned int num = 0, n, i;
	int sign = 1;

	for (n = 0; *(s + n) != '\0'; n++)
	{
	}

	for (i = 0; i < n; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		else if (s[i] >= '0' && s[i] <= '9')
		num = num * 10 + (s[i] - 48);

		else if (num > 0)
			break;
	}

	return (num * sign);
}