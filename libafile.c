#include <stdio.h>
#include <string.h>

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

