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
}
