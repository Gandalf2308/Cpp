#include <iostream>
  #include <string>
  using namespace std;
  class Cricketer {
  public:
      string name;
      int age;
      int numTests;
      double avgRuns;
      // Method to input cricketer details
      void inputCricketer() {
cout << "Enter Cricketer's Name: ";
getline(cin,name);
cout << "Enter Age: ";
cin >> age;
cout << "Enter Number of Test Matches Played: ";
cin >> numTests;
cout << "Enter Average Runs Scored per Test: ";
cin >> avgRuns;
      }
    // Method to display cricketer details
    void displayCricketer() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Test Matches Played: " << numTests << endl;
        cout << "Average Runs per Test: " << avgRuns << endl;

}
};
int main() {
    const int numCricketers = 2;
    Cricketer cricketers[numCricketers];
for (int i = 0; i < numCricketers; ++i) {
cout << "Enter details for Cricketer " << i + 1 << ":" <<endl;
cricketers[i].inputCricketer();
}
for (int i = 0; i < numCricketers; ++i) {
    cout << "Cricketer " << i + 1 << " Details:" << endl;
    cricketers[i].displayCricketer();
    cout << endl;
}
return 0;
}
