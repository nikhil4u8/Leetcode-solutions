#include<iostream>
#include<fstream>
#include<sstream>

int main(){
  std::string strLine;
  std::string strWord;
  uint32_t u32Count = 0;
  std::ifstream iFile("a.txt"); /ifstream (>>)	For reading from file
  if(not iFile) {
    std::cout << "File Open error" << std::endl;
    return 0;
  }

  while (iFile.eof() == 0) {  //bool eof(); Returns true if End-of-file reached.
    std::getline(iFile, strLine);    //getline(istream& is, string& str);  
    std::stringstream oSS(strLine);
    while (std::getline(oSS, strWord, ' ')){ //istream& getline(istream& is, string& str, char delim);
//      if (strWord.find('@') != std::string::npos) //Find character inside word
        if (strWord == "amit@gmail.com")
          u32Count++;
    }
  }
  std::cout << "Count = " << u32Count << std::endl;
}

//IN PYTHON
u32Count = 0

try:
    with open("a.txt", "r") as iFile:
        for line in iFile:
            strLine = line.strip()
            words = strLine.split(' ')
            for strWord in words:
                if strWord == "amit@gmail.com":
                    u32Count += 1

    print("Count =", u32Count)

except FileNotFoundError:
    print("File Open error")
