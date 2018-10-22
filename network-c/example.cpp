#include <iostream>
using namespace std;
int main(){
char name[5] = {'R','O','E','U','N'};
for (int i=0; i<5; i++){
for(int j=i; j<5; j++){
cout<<name[j];
}
cout<<"\n";
}
}
