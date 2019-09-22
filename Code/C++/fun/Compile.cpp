/*
This program compiles and runs the requested code.
*/

#include <iostream> // In out CLI
#include <fstream>  // Read write files
#include <string>   // Simple stringing

using namespace std;

void simpleCompile(string inFile) {
  // Removing .cpp from infile and concatenating input strings to commands
  string outFile = inFile.substr(0, inFile.size()-4);
  string compileCommand = "c++ -o " + outFile + " " + inFile;
  string runCommand = "./" + outFile;

  // Make system compile and run file
  system(compileCommand.c_str());
  system(runCommand.c_str());
}


void compile(string outFile, string inFile) {
  // Concatenating input strings to commands
  string compileCommand = "c++ -o " + outFile + " " + inFile + " -std=c++11 -DARMA_DONT_USE_WRAPPER -larmadillo -lopenblas -llapack"; // add -DARMA_DONT_USE_WRAPPER -lopenblas -llapack for armadillo
  string runCommand = "./" + outFile;

  // Make system compile and run file
  system(compileCommand.c_str());
  system(runCommand.c_str());
}

int main(int argc, char **argv) {

  for (int i = 1; i < argc; ++i) {            // Checkin every input argument for help command -h or --help
    string arg = argv[i];
    if ((arg == "-h") || (arg == "--help")){  // Displaying help information
      cout << "This program can take either one or two input variables."<< endl;
      cout << "Outfile is the compiled file you want to save, and infile.cpp is the code you want to compile." << endl;
      cout << " " << endl;
      cout << "Example: "<< argv[0] <<" outfile infile.cpp" << endl;
      cout << "This will compile the infile.cpp to outfile." << endl;
      cout << " " << endl;
      cout << "Example: "<< argv[0] <<" infile.cpp" << endl;
      cout << "This will compile the infile.cpp to infile." << endl;

      return 0;
    }
  }

  if ((argc < 2) || (argc > 3)) {             // Checks if user input wrong amount of variables
    cerr << "Wrong input variables. Run with parameter --help for more." << endl;
  }

  if (argc == 2) {
    simpleCompile(argv[1]);
  } else if (argc == 3) {
    compile(argv[1], argv[2]);
  }

  return 0;
}
