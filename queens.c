#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Udadd {
  int ud, a, dd;
};

char *output, *temp;
int boards_tried = 0;

bool tryrows(int size, int column, struct Udadd *bad, int bad_size){
  for (int i = 0; i < size; i++) {
    boards_tried++;
    for (int j = 0; j < bad_size; j++) {
      if (i == bad[j].ud || i == bad[j].a || i == bad[j].dd) {
	goto deep_break;
      }
    }

    if (column == size - 1) {
      sprintf(output, "%d-%d", column, i);
      return true;
    }

    bad[bad_size].ud = bad[bad_size].dd = bad[bad_size].a = i;
    for (int j = 0; j < bad_size + 1; j++) {
      bad[j].ud--;
      bad[j].dd++;
    }

    bool res = tryrows(size, column+1, bad, bad_size+1);
	
    for (int j = 0; j < bad_size; j++) {
      bad[j].ud++;
      bad[j].dd--;
    }   

    if (res) {
      sprintf(temp, "%s", output);
      sprintf(output, "%d-%d %s", column, i, temp);
      return true; 
    }
    deep_break:;
  }
  return false;
}

int main() {
        int size = 8;
	struct Udadd *udadd = malloc(size * sizeof(struct Udadd));
	output = malloc(4 * size);
	temp = malloc(4 * size);
	tryrows(size, 0, udadd, 0);
	printf("%s\nboards tried %d\n", output, boards_tried);
	return 0;
}
