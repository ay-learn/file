#include <stdio.h>
#include <string.h>

#define MAXLINE 80

void ram(char *file, char *s, int N) {
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

int main(int argc, char *argv[]) {
  char s[MAXLINE];

  ram("/proc/meminfo",s,3);
  printf("%s\n", s);
}
