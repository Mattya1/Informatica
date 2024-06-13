#include <iostream>
using namespace std;

int main ()
{
int temp;
cin >> temp;

if (temp >40 || temp < -20){
cout << "Non ci credo, il termometro deve essere rotto";}
else if (temp >= -20 && temp <= 0){
  cout << "Freddo incredibile";}

else if ( temp >=1 && temp <= 15){
  cout << "Freddo";}

else if (temp >=16 && temp <= 23){
  cout << "Normale";}
else if (temp >=24 && temp <=30){
  cout << "Caldo";}
else if (temp >=31 && temp <=40){
  cout << "Caldo da morire";}

}