#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "stack.h"

void printCommands()
{
  printf("The commands for this program are:\n\n");
  printf("q - to quit the program\n");
  printf("? - to list the accepted commands\n");
  printf("or any postfix mathematical expression using operators of *, /, +, -\n");
}

int main(int argc, char const *argv[])
{

  t_node *root = NULL;
  char input[300];

  /* set up an infinite loop */
  while (1)
  {
    fgets(input, 300, stdin);
    /* remove the newline character from the input */
    int i = 0;

    while (input[i] != '\n' && input[i] != '\0')
    {
      /*
		if(isalpha(input[i]) > 0){
			if(input[i] == 'q' || input[i] == 'Q'){
				break;
			}
			
			exit(-1);
		}
		*/
      i++;
    }
    input[i] = '\0';

    /* check if user enter q or Q to quit program */
    if ((strcmp(input, "q") == 0) || (strcmp(input, "Q") == 0))
    {
      break;
    }
    /* check if user enter ? to see command list */
    else if (strcmp(input, "?") == 0)
    {
      printCommands();
    }
    /* user enters an expression */
    else
    {
      //printf ("%s\n", input);
      root = parseExpression(input);

      /*
		Infix notation: ( 42  +  64 )
		Prefix notation:  +  42  64 
		Postfix notation:  42  64  + 
		Expression result: 106
		*/

      printf("Infix notation: ");
      inFixPrint(root);
      printf("\nPrefix notation: ");
      preOrderprint(root);
      printf("\nPostfix notation: ");
      postOrderprint(root);
      //printf("\nExpression result: ");
      /* 1- Store the expression in a tree
           2- Display infix notation
           3- Display prefix notation
           4- Display postfix notation
           5- Display the result 
        */
    }
  }

  printf("\nGoodbye\n");
  destroyTree(root);
  return 0;
}
