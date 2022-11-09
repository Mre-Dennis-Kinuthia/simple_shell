#ifndef _MAIN_
#define _MAIN_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**#define BUF_SIZE
 **/

void type_prompt()
{
        static int first_time = 1;
        if ( first_time )
        {
                const char* CLEAR_SCREEN_ANSI = "\033[H\033[J";
                write(STDOUT_FILENO,CLEAR_SCREEN_ANSI,12);
                first_time = 0;
        }
        printf("#");
}
void read_command ( char cmd[], char *par[] )
{
	/*char line[1024];
	int count = 0;*/
	int i = 0, j = 0;
	char *array[1024], *pch;
	char *buffer;
	size_t buffersize = 1024;
	/**for(;;)
	{
		int c = fgetc ( stdin );
		line[count++] = (char) c;
		if ( buffer == '\0' )
			break;
	}
	if ( count == 1 )
	  return;*/

	/*added code*/
	buffer = malloc(sizeof(char) * buffersize);
	getline(&buffer, &buffersize, stdin);
	pch = strtok ( buffer, " \n");

	while ( pch != NULL )
	{
		array[i++] = strdup ( pch );
		pch = strtok (NULL, " \n");
	}
	strcpy ( cmd, array[0] );
	for ( j = 0; j < i; j++)
		par[j] = array[j];
	par[i] = NULL;
}

#endif
