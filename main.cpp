#include <iostream>
#include <fstream>
#include <string>

#define MAX_CHAR 5
using namespace std;

typedef struct {
  int count = 0;
} char_node;

char_node *arr = (char_node *)malloc(MAX_CHAR * sizeof(char_node));

int count_char(char *s, char a, int len);
void automate_char_counting(char *s, char a[], int len);

int main(int argc, char **argv) { 

  // array of char to search
  char search[MAX_CHAR] = {'a', 'b', 'c', 'd', 'e'};
  
  // if the argument legnth is not 2
  if (argc != 2) {
    cout << "Missing command-line argument\n";
    free(arr);
    return 1;
  }

  // call fstream
  fstream file;

  // open the file
  file.open(argv[1], ios::in);

  // only if the file is open
  if (file.is_open()) {

    // define string and set count to 1
    string s;
    int count = 0;

    // for each line in the .txt file
    while(getline(file, s)) {

      // if it is not an empty line
      if (s != "") {
        
        // increment count every line and ignore spaces
        count++;

        // print every line as it is
        cout << s << endl;

        // 
        char *str = (char *)malloc(s.length() * sizeof(char));
        for (int i = 0; i < s.length(); i++) {
          str[i] = s[i];
        }

        automate_char_counting(str, search, s.length());
        
        free(str);
      }
    }

    // print total line
    cout << "-----------------------------\n";
    cout << "Total line: " << count << endl;

    // print total char to search that was found
    for (int i = 0; i < MAX_CHAR; i++) {
      cout << "Total of '" << search[i] << "' found: " << arr[i].count << endl; 
    }

    // close the file
    file.close();

  } 
  
  // if the file is not found
  else {
    cout << "No such file.\n";
    free(arr);
    return 1;
  }

  // exit with status 0
  free(arr);
  return 0;
}


int count_char(char *s, char a, int len) {
  /* 
    count number of specific char seen in a set of string
  */
  int count = 0;

  for (int i = 0; i < len; i++) {
    if (s[i] == a)  count++;
  }

  return count;
}


void automate_char_counting(char *s, char a[], int len) {
  /* 
    -loop over the array of char to search 
    -do the search
    -append result to the struct accordignly
  */
  for (int i = 0; i < MAX_CHAR; i++) {

    // call for count char fct for each items
    arr[i].count += count_char(s, a[i], len);
  }
}
