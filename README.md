
# Table of Contents

1.  [Introduction](#orgcdbbb0f)
2.  [Declarations](#org9e93811)
    1.  [Preprocesors](#orgfe83a1b)
    2.  [Variables](#orgbac0e20)
    3.  [Functions](#org633cb6d)
3.  [Check Input](#orgceecf9c)
4.  [Utils](#org87d73ec)
    1.  [Print Packages](#orgebcb21f)
5.  [Commands](#orgcc50534)
    1.  [Stow](#orgdcb0924)
        1.  [Stow-Package](#org67f8b8d)
        2.  [Stow-Commands](#org67d8628)
        3.  [Unstow](#orgb68d7f8)
6.  [Main loop](#org1b60338)



<a id="orgcdbbb0f"></a>

# Introduction

This is a project to learn c nothing else, this is not certainly a tool to be more efficient due to the fact that issuing the commands is faster. Thanks and any feedback to help me learn is apreciated.

**Mangin** is a cli tool to control and alter your dotfiles from anywhere in your computer.

The first time you launch Mangin it should promt you for the path to your Stow directory.
Example : `~/Dot/` or `~/.dotfiles/` 


<a id="org9e93811"></a>

# Declarations


<a id="orgfe83a1b"></a>

## Preprocesors

These are the preprocesors of the program

    
    #include <stdio.h>
    #include <stdlib.h>


<a id="orgbac0e20"></a>

## Variables

    
    const char dotdir[] = "~/Dot/";


<a id="org633cb6d"></a>

## Functions

    
    void checkInput(char input);
    int stowPkg(char folder[], char pkg[]);
    int getPkg();
    void stowCmds();
    void unStow(char folder[], char pkg[]);


<a id="orgceecf9c"></a>

# Check Input

This is the function that handles the input form the user.

    
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


<a id="org87d73ec"></a>

# Utils


<a id="orgebcb21f"></a>

## Print Packages

This function is used as a util to list the packages available to the user

    
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


<a id="orgcc50534"></a>

# Commands


<a id="orgdcb0924"></a>

## Stow

This is the section that holds all the functions for the stow commands.


<a id="org67f8b8d"></a>

### Stow-Package

    
    
    int stowPkg(char folder[], char pkg[]) {
      char chr;
      char cmd[50];
      sprintf(cmd, "cd %s;stow %s", folder, pkg);
      printf("The command is : %s\n", cmd);
      return 0;
    }


<a id="org67d8628"></a>

### Stow-Commands

    
    void stowCmds() {
      printf("q - Quit\nd - Unstow\n");
    }


<a id="orgb68d7f8"></a>

### Unstow

    
    void unStow(char folder[], char pkg[]) {
      char cmd[50];
      sprintf(cmd, "cd %s ; stow -D %s", folder, pkg);
      printf("The command is : %s", cmd);
    }


<a id="org1b60338"></a>

# Main loop

This is the main function and starts a infinite loop that asks the user for input and invoes the `checkInput` function

    
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

