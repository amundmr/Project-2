#include <iostream> //In out CLI
#include <fstream>  //Read write files
#include <cstdlib>  //String to float conversion
#include <string>   //Simple stringing

using namespace std

int main(int argc, char **argv) {
  if((argc < 2) || (argc > 2)) {
    cout << "This program takes filename to compile and run as input variable." << endl;
    throw "Write an input variable!";
  }

  cout << argv[0] << endl;
  return 0;
}
