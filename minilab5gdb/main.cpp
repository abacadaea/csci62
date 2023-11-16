#include <iostream>
#include "node.h"
using namespace std;
int main(){
node<int>* head = nullptr, * tail=nullptr, *nh, *nt, *nh2=nullptr, *nt2=nullptr;
list_head_insert(head, tail, 3);
list_head_insert(head, tail, 2);
list_tail_insert(head, tail, 1);
cout<<head;
cout<<endl;
list_tail_insert(nh, nt, 1);  
cout<<nh;
cout<<endl;
list_copy(head, tail, nh, nt);
cout<<nh;
list_clear(head, tail);
cout<<endl;
list_insert(head, 4);
cout<<head;
cout<<endl;
list_head_remove(head, tail);
list_head_remove(nh, nt);
list_head_remove(nh2, nh2);
cout<<head;
cout<<endl;
cout<<nh;
cout<<endl;
cout<<nh2;
cout<<endl;
list_insert(head, 4);
list_remove(head, tail);
cout<<head;
return 0;
}

