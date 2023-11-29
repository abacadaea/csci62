#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void granted() {
  printf(" Access Granted.\n");
}

int check_authentication() {
    char password[8];
    gets(password);
    if (strcmp(password, "123456")==0)
      granted();
}

int main(){
  check_authentication();
}
