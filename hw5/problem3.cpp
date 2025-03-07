#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void granted() {
  printf(" Access Granted.\n");
}

void auth() {
    char password[16];
    gets(password);
    if (strcmp(password, "123456")==0)
      granted();
}

int main(){
  auth();
}
