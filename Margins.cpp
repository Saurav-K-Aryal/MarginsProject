#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>


using namespace std;


//This is the paddingElement. This is used for padding. We are using '.' for padding. User have the option of adding the paramter that they want.
const static char paddingElement = ' ';
//The maximum for the character
const static int maxCharacterLimit = 80;
/**
   This function is used for the right padding of the file.
*/

void rightPadding(string* buffer, int right, int left, char paddingElement, ostream& out) {
   out << setiosflags(ios::left) << setw(right + maxCharacterLimit + left) << setfill(paddingElement) << *buffer << "\n";
}

/**
   This function takes the file, left and right margins. 
   This adds the left margin and calls the function above for  the right padding.
   This function also writes to the file with the proper margins.
*/
void addMargins(istream& in, ostream& out, int left, int right) {

   string tmp;

   while (!in.eof()) {
      getline(in, tmp, '\n');
      tmp.insert(tmp.begin(), left, paddingElement);
      rightPadding(&tmp, right, left, paddingElement, out);    
   }
}


/**
   This is the main function. It takes the file, left and right margin as the parameter.
   It checks to see if there is a proper number of arguments in the parameter and converts the left and right margin to integer.
   It calls the add margin function above.
*/
int main(int argc, char** argv) {
   /*
      The temp file is used as a buffer till we read from the
      DAT1.txt file, do the padding and than write it again to
      DAT.txt file.
   */
   int left, right;
   string readingFromTempFile;
   if (argc != 4)
      return(EXIT_FAILURE);
   ifstream in(argv[1]);
   ofstream out("temp.txt");
   if (!in || !out)
      return(EXIT_FAILURE);   
   if (argc == 4) {
      left = atoi(argv[2]);
      right = atoi(argv[3]);
      addMargins(in, out, left, right);
   } 
   in.close();
   out.close();
   ifstream input("temp.txt");
   ofstream output(argv[1]);
   //The following takes the temp file as input and writes to the DAT1.txt ile
   for(int i=0;input.eof()!=true;i++)
      readingFromTempFile+=input.get();
   readingFromTempFile.erase(readingFromTempFile.end()-1);
   output<<readingFromTempFile;
   remove("temp.txt");//deleting the temp file
   //Used to see if the program successfully did the work
   if (out)
      cout<<"\nProgram successfully completed\n";
   else
      cout<<"\nERROR with the program\n";
   return 0;
}