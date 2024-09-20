#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
  int auth_flag = 0;
  char password[8];
  gets(password);
  if (strcmp(password, "123456")==0)
    auth_flag = 1;

  if (auth_flag) {
    printf("Access Granted\n");
  } else {
    printf("Access Denied\n");
  }
}
