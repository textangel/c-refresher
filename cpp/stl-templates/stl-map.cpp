
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <algorithm> 
#include <fstream>
#include <vector>
#include "stream-tokenizer.cpp"

using namespace std;
/*
    Our one large example ingests all words from a plain-text version of a 
    large novel, compile all information of interest into a map<string, size_t>,
    generate some statistics, and then allow us to query the index for
    information about words we're curious about.

    Note: Compile with
    g++ -std=gnu++11 stl-map.cpp -o stl-map.o -I/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/libxml2 -lxml2
*/
static void printLeadingWords(const string& header,
                              const vector<pair<string, size_t>>& words, size_t count) {
  cout << header << ":" << endl;
  cout << endl;
  auto curr = words.cbegin();
  for (size_t i = 1; i <= count && curr != words.cend(); i++, ++curr) {
    cout << "  " << setw(2) << i << ".) " << curr->first
         << " [count: " << curr->second << "]" << endl;
}
  cout << endl;
}

static const int kWrongArgumentCount = 1;
static const int kFileNotAccessible = 2;
// static const string &kDelimiters = " ";

string & toLowerCase(string & data){
    transform(data.begin(), data.end(), data.begin(),
        [](unsigned char c){ return tolower(c); });
    return data;
}

string & ltrim(string & str)
{
  auto it2 =  find_if( str.begin() , str.end() , [](char ch){ return !isspace<char>(ch , locale::classic() ) ; } );
  str.erase( str.begin() , it2);
  return str;   
}

string & rtrim(string & str)
{
  auto it1 =  find_if( str.rbegin() , str.rend() , [](char ch){ return !isspace<char>(ch , locale::classic() ) ; } );
  str.erase( it1.base() , str.end() );
  return str;   
}

string & trim(string & str)
{
   return ltrim(rtrim(str));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <text-file>" << endl;
        return kWrongArgumentCount;
    }
    ifstream infile(argv[1]);
    if (infile.fail()) {
        cerr << "File named \"" << argv[1] << "\" couldn't be opened." << endl;
        return kFileNotAccessible;
    }
    map<string, size_t> m;
    StreamTokenizer st(infile, " ", 0);
    while (st.hasMoreTokens()) {
        string cur_str = st.nextToken();
        string str = toLowerCase(cur_str);
        m[str]++; 
    }
    cout << "Ingested all of \"" << argv[1] << "\"." << endl;
    cout << "Discovered " << m.size() << " unique words." << endl;

    vector<pair<string, size_t>> alphabeticallySortedWords(m.cbegin(), m.cend());
    printLeadingWords("Leading words, sorted alphabetically", alphabeticallySortedWords, 15);
    
    vector<pair<string, size_t>> frequentlyOccurringWords(alphabeticallySortedWords);
    auto compfn = [](const pair<string, size_t>& one, const pair<string, size_t>& two) -> bool {
    return
        (one.second > two.second) ||
        (one.second == two.second && one.first < two.first);
    };
    sort(frequentlyOccurringWords.begin(), frequentlyOccurringWords.end(), compfn);
    printLeadingWords("Leading words, sorted by frequency", frequentlyOccurringWords, 15);

    while (true) {
        cout << "Enter a word [or just hit enter to quit]: ";
        string word;
        getline(cin, word);
        word = toLowerCase(trim(word));
        if (word.empty()) break;
        auto found = m.find(word);
        if (found == m.end()) {
          cout << "The word \"" << word << "\" isn't present. #facepalm" << endl;
        } else {
          cout << "The word \"" << word << "\" is present and appears this many times: "
               << found->second << " [with frequency rank: ";
          const pair<string, size_t>& match = *found;
          auto found = lower_bound(frequentlyOccurringWords.cbegin(),
                                   frequentlyOccurringWords.cend(), match, compfn);
          size_t rank = found - frequentlyOccurringWords.cbegin() + 1;
          cout << rank << "]" << endl;
        }
    }
    return 0;
}