#include <stdio.h>
#include <string.h>

void granted() {
  printf("Access Granted.\n");
}

int auth() {
    char password[16];
    gets(password);
    return 0;
}

int main(){
  auth();
}
