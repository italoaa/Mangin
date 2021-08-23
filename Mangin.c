#include <stdio.h>
int main() {
  char chr;
  printf("Enter a character: ");
  scanf("%c", &chr);
  printf("You entered %c.", chr);
  return 0;
}

void displayString(char str[])
{
    printf("String Output: ");
    puts(str);
}
