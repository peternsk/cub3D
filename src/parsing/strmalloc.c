#include "cube.h"

char	*strmalloc(int size)
{
	char	*ptr;

	ptr = malloc (sizeof(char) * size + 1);
	if (!ptr)
		return (NULL);
	return (ptr);
}