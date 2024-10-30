#include<iostream>
using namespace std;
class Fruit{
public:
  string name;
  string color;

};
int main(){
    Fruit mango;//Object
    mango.name="Mango";
    mango.color="Yellow";
    cout<<mango.name<<"-"<<mango.color<<endl;
    Fruit *apple=new Fruit();
    apple->name="Apple";
    apple->color="Red";
    cout<<apple->name<<"-"<<apple->color;
    return 0;
}