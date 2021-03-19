// This project takes in user input and makes use of a stack to fill values in
// a binary tree and perform the operations based on a specific arithmetic order
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "stack.h"

// Print the initial commands
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
  int result = -999;
  char input[300];

  /* set up an infinite loop */
  while (1)
  {
    fgets(input, 300, stdin);
    /* remove the newline character from the input */
    int i = 0;

    while (input[i] != '\n' && input[i] != '\0')
    {
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
      // Parse the user input
      printf("%s", input);
      root = parseExpression(input);
      if (root == NULL)
      {
        continue;
      }

      // Print out the values in the desired order and return the final calc
      else
      {

        printf("\nInfix notation: ");
        inFixPrint(root);
        printf("\nPrefix notation: ");
        preOrderprint(root);
        printf("\nPostfix notation: ");
        postOrderprint(root);
        printf("\nExpression result: ");
        result = evalExpression(root);
        printf("%d\n\n", result);
      }
    }
  }

  // Delete the tree
  printf("\nGoodbye\n");
  destroyTree(root);
  return 0;
}
