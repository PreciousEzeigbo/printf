#include "main.h"
#include <stdlib.h>

/**
 * printing_hex - prints a long decimal in hexadecimal
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int printing_hex(va_list arguments, char *buf, unsigned int ibuf)
{
	long int int_input = va_arg(arguments, long int);
	int isnegative = 0;
	unsigned int binary_len = sizeof(long int) * 8; /* size of long int in bits*/
	char *binary = malloc(binary_len + 1);
		if (binary == NULL)
	{
		return (0); /* allocation failed */
	}
	char *hexadecimal;
	hexadecimal = malloc(16 + 1);
		if (hexadecimal == NULL)
	{
		free(binary);
		return (0); /* allocation failed */
	}
	if (int_input == 0)
	{
		ibuf = hand1_buf(buf, '0', ibuf);
		free(binary);
		free(hexadecimal);
		return (1);
	}
	if (int_input < 0)
	{
		isnegative = 1;
		if (int_input == (1L << (binary_len - 1)))
		{
			/* most negative value, cannot negate */
			binary[binary_len - 1] = '1';
			for (unsigned int i = 0; i < binary_len - 1; i++)
			{
				binary[i] = '0';
			}
		}
		else
		{
			int_input = -int_input - 1;
		}
	}
	fill_binary_array(binary, int_input, isnegative, binary_len);
	fill_hex_array(binary, hexadecimal, 0, 16);
	unsigned int count = 0;
	int first_digit = 0;
		for (unsigned int i = 0; i < 16; i++)
	{
		if (hexadecimal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = hand1_buf(buf, hexadecimal[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (count);
}

