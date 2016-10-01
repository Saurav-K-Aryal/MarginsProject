#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>


using namespace std;

const static char PAD_CHAR = ' ';

// string StringPadRight(string* string, int padded_len, char *pad) {
//     int len = string->length();
//     if (len >= padded_len) {
//         return *string;
//     }
//     int i;
//     for (i = 0; i < padded_len - len; i++) {
//         strcat(string.c_str(), pad);
//     }
//     return *string;
// }

void rpad(string* buffer, int right, int left, char PAD_CHAR, ostream& out) {
   int MAX_CHAR_LIMIT = 80; 
   out << setiosflags(ios::left) << setw(right + MAX_CHAR_LIMIT + left) << setfill(PAD_CHAR) << *buffer << "\n";
}
//    string tmp;
//    out.setf(ios_base::right);   // Tell the stream to
//                                 // right-justify
//    while (!in.eof()) {
//       out.width(right);                  // Reset width after
//       getline(in, tmp, '\n');        // each write
//       out << tmp << '\n';
//    }
//    out.close();
// }

// addMargins takes two streams and two numbers. The streams are for
// input and output. The first of the two numbers represents the
// left margin width (i.e., the number of spaces to insert at the 
// beginning of every line in the file). The second number represents
// the total line width to pad to.
void addMargins(istream& in, ostream& out, int left, int right) {

   string tmp;

   while (!in.eof()) {
      // tmp = &temp;
      getline(in, tmp, '\n');
      tmp.insert(tmp.begin(), left, PAD_CHAR);
      cout << tmp;
      rpad(&tmp, right, left, PAD_CHAR, out);                 // rpad from Recipe
      //out << tmp << '\n';
   }
}

int main(int argc, char** argv) {

   if (argc != 4)
      return(EXIT_FAILURE);

   ifstream in(argv[1]);
   ofstream out("temp.txt");

   if (!in || !out)
      return(EXIT_FAILURE);
    int left, right;
   if (argc == 4) {
      left = atoi(argv[2]);
      right = atoi(argv[3]);
      addMargins(in, out, left, right);
   } 



   out.close();

   if (out)
      return(EXIT_SUCCESS);
   else
      return(EXIT_FAILURE);
}