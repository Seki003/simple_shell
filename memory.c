#include "shell.h"

/**
* bfree - Frees a pointer and sets it to NULL.
* @ptr: Address of the pointer to free.
*
* Return: 1 if freed, otherwise 0.
*/
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr); /* Free the memory pointed to by ptr */
*ptr = NULL; /* Set the pointer to NULL to avoid using a dangling pointer */
return (1); /* Return 1 to indicate that memory was successfully freed */
}
return (0); /* Return 0 if the pointer was already NULL or invalid */
}
