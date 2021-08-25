#include <stdio.h>
#include <stdlib.h>

const char dotdir[] = "~/Dot/";

void checkInput(char input);
int stowPkg(char folder[], char pkg[]);
int getPkg();
void stowCmds();
void unStow(char folder[], char pkg[]);

void checkInput(char input) {
  if (input == 'S') {

    char pkg[50];
    getPkg(); /* list the packages */
    printf("What Package to stow? ");
    scanf("%s", pkg);
    stowPkg(dotdir, pkg);

  } else if (input == 's') {

    char cmd;
    printf("What stow action to perform ( ? for help ) : ");
    scanf("%s", &cmd);
    if (cmd == 'd') {
      char pkg[50];
      getPkg();
      printf("What Package to unStow? ");
      scanf("%s", &pkg);
      unStow(dotdir, pkg);
    }else if (cmd == 'q') {
      exit(1);
    } else if (cmd == '?') {
      stowCmds();
    } else {
      printf("Unrecongized Character : %c \n", cmd);
    }
  } else if (input == 'l') {
    getPkg();
  } else if (input == 'q') {
    exit(0);
  } else if (input == '?') {
    printf("S - Stow [pkg_name]\ns - stow commands\nl - list the packages in the stow directory\nq - quit\n");
  } else {
    printf("Unrecognized Character %c \n", input);
  }
}

int getPkg() {
  FILE *fp;
  char pkg[1035];
  /* Open the command for reading. */
  char cmd[50];
  sprintf(cmd, "cd %s ; ls -d */", dotdir);
  fp = popen(cmd, "r");
  if (fp == NULL) {
    printf("Failed to run command\n");
    exit(1);
  }

  /* Read the output a line at a time - output it. */
  int counter = 0;
  while (fgets(pkg, sizeof(pkg), fp) != NULL) {
    printf("%d : %s", counter, pkg);
    counter++;
  }

  /* close */
  pclose(fp);
  return 0;
}

int stowPkg(char folder[], char pkg[]) {
  char chr;
  char cmd[50];
  sprintf(cmd, "cd %s;stow %s", folder, pkg);
  printf("The command is : %s\n", cmd);
  return 0;
}

void stowCmds() {
  printf("q - Quit\nd - Unstow\n");
}

void unStow(char folder[], char pkg[]) {
  char cmd[50];
  sprintf(cmd, "cd %s ; stow -D %s", folder, pkg);
  printf("The command is : %s", cmd);
}

int main() {
  printf("Hello! Thanks for trying Mangin. Remember that the purpose of this project is to start to learn the C programming language so if there are any bugs or improvements I would like for you to let me know\n");
  while (1) {
    char chr = 'x';
    printf("Mangin prompt ( ? for help ) : ");
    scanf("%c", &chr);
    checkInput(chr);
    scanf("%c", &chr);
  }
  return 0;
}
