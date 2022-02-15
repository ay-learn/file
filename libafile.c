#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "file.h"

#define MAXLINE 80

void readFirstLine(char *file,char *line){
  FILE *fp = NULL;
  fp = fopen(file, "r");
  if (!fp) {
    perror ("File open error!\n");
  }
  fscanf(fp, "%[^\n]", line);
  fclose(fp);
}



void readOneLine(char *file, char *s, int N) {
  FILE *fp = fopen(file, "r");
  char line[MAXLINE];
  int i = 0;
  int x = 0;

  while (fgets(line, sizeof(line), fp)) {
    i++;
    if (i == N) {
      sscanf(line, "%*s %d", &x);
      strcpy(s, line);
    }
  }
  fclose(fp);
}

int fgetint(char *file) {
  FILE *fp = fopen(file, "r");
  char line[MAXLINE];
  int i = 0;
  int x = 0;

  fgets(line, sizeof(line),fp);
  sscanf(line, "%d", &x);
  fclose(fp);
  return x;
}

void fgetString(char *file,char *s) {
  FILE *fp = fopen(file, "r");
  fgets(s, sizeof(s),fp);
}

// run shell command and get first output from stdout 
void stdoutOneline(char *s_in,char *s_out) {
  FILE *popen(const char *command, const char *mode);
  int pclose(FILE * stream);
  FILE *file;

  file = popen(s_in, "r");
  if (file == NULL) {
    perror("popen");
    exit(EXIT_FAILURE);
  }
  fgets(s_out, sizeof(s_out), file);
  pclose(file);
}
