/*Approach-1 //Hash Table. unordered_map<String, int>
Logic:
1. Open file, read each word, fill in unordered_map<Word, count>
2. Once file reading completes,
search map with highest value, Print Delete. Repeat 3 times.
Complexity: m:words in file
Time O(m). Reading file,storage in hash-table, Finding top 3 words. O(1).
Space O(m). Creating hash map.
*/
using String = std::string;
using Pair = std::pair<String, int>;

static bool comparator(Pair p1, Pair p2){
    return p1.second < p2.second;
}

int main(){
  std::ifstream iFile("Paragraph.txt");

  if (!iFile) {
    std::cout << "File not present\n";
    return 0;
  }

  String strLine, strWord;
  std::unordered_map<String, int> um;   //<Word, count>

  //Open the file
  while (iFile.eof() != 1){

    //Read the line
    std::getline (iFile, strLine);

    //Tokenize the line based on space
    std::stringstream oSS(strLine);
    while(std::getline(oSS, strWord, ' ')){
      um[strWord]++;          //Create <key=String, value=count>
    }
  }
  
//  for (auto [i,j]:um){
//    std::cout <<i<<","<<j << "\n";
//  }

  std::unordered_map<String, int>::iterator it;
  for (int i=0;i<3;++i){
    it = std::max_element(um.begin(), um.end(), comparator);
    std::cout << it->first <<"," << it->second <<"\n";
    um.erase(it);
  }
}  


//IN PTYHON

from collections import defaultdict
import operator

# Equivalent of Pair in C++
class Pair:
    def __init__(self, first, second):
        self.first = first
        self.second = second

# Equivalent of comparator in C++
def comparator(p1, p2):
    return p1.second < p2.second

if __name__ == "__main__":
    try:
        with open("Paragraph.txt", "r") as iFile:
            strLine = ""
            strWord = ""
            um = defaultdict(int)  # <Word, count>

            # Open the file
            for line in iFile:
                strLine = line

                # Tokenize the line based on space
                words = strLine.split()
                for strWord in words:
                    um[strWord] += 1  # Create <key=String, value=count>

        # Find the top 3 most frequent words
        sorted_um = sorted(um.items(), key=operator.itemgetter(1), reverse=True)
        for i in range(3):
            print(sorted_um[i][0] + "," + str(sorted_um[i][1]))

    except FileNotFoundError:
        print("File not present")
