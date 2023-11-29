#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int auth() {
    int auth_flag=0;
    char password[16];
    
    gets(password);
    
    if (strcmp(password, "brilling")==0)
        auth_flag = 1;
    
    return auth_flag;
}

int main(){
    if (auth()) {
        printf(" Access Granted.\n");
    } else {
        printf("\nAccess Denied.\n");
    }
}
