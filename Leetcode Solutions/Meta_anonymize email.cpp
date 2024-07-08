/*

https://github.com/amitkumar50/Code-examples/blob/master/DS_Questions/Questions/Strings/Reverse/Reverse_Part_of_vector_anonmize_Email.md

Logic
Reverse 1st 5 words of vector //O(n)
Traverse remaining vector, anomamize inplace using random number generator.

Complexity //O(2n+m)
O(n) Total characters in vector to be reversed=n.
m: Total characters in complete vector.
*/
#define REVERSE 5 //Reverse 1st 5 words

void GenerateRandom(String& strRandom, int len) {
  int i=0;
  char ch='a';
  while (i < len){
    strRandom += ch+std::rand()%26;
    ++i;
  }
}

int main(){
  std::srand(time(0));
  StringVector v = {"test", "your", "ken", "everyday", "amit@gmail.com", "Build your character", "Because", "vivek@yahoo.com", 
  "Character", "is", "only", "thing", "for", "anil@times.com", "success"};
  StringVectorItr itr = v.begin();
  std::reverse(itr, (itr+REVERSE+1));

  String strRandom;
  int j, len, index=0;

  for (auto& i:v){
    j = len = index = 0;
    strRandom.clear();
    while (j<i.size()) {
      if (i[j] == '@'){
        if(len==0)
          index = j;
      }
      if (i[j] == '.'){
        GenerateRandom(strRandom, len-2);
        i.replace(index+1, len-1, strRandom);
        break;
      }
      if(index)
        ++len;
      ++j;
    }
  }
  for (auto i:v)
    std::cout<<i<<" ";
}