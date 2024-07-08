# Logic: Read words from input file(skip email), Write words to output file. rename output file.

# 0. Import re, os modules
# 1. Open output file fout in write mode.
# 2. Open input file in f in read mode and read every line
# 3. Create list of email addresses from line using re module
# Example lst = ['a@test.com', 'b@test.com']
# 4. if word is not in list. Write into file
# 5. close both inupt, out files
# 6. Rename newly created file to old


# Complexity
# Time: n:words in input file. m:Emails in input file. O(mn)
# Space: O(n+m): Creating a new file

import re
import os
fout = open("html-file-new.html", "w")

with open("html-file.html", "r") as f: 
  for line in f:
    lst = re.findall('\S+@\S+',line)
    for word in line.split():
      if word not in lst:
        fout.write(word)
    fout.write("\r\n")
f.close()
fout.close()        
os.rename("html-file-new.html","html-file.html")


//IN C++
#include<iostream>
#include<fstream>
#include<sstream>

int main(){
  std::ifstream fin("input.html");      //1
  std::ofstream fout("temporary");

  std::string strLine, strWord;

  while (fin) {
    std::getline(fin, strLine);
    std::stringstream oSS(strLine);

    //Tokenize the line to read the word
    while (std::getline(oSS, strWord, ' ')){
      std::cout<<strWord<<" ";
      if (strWord.find('@') == std::string::npos)
        fout << strWord;
    }
    
    fout <<std::endl;
  }
  fin.close();
  fout.close();
}