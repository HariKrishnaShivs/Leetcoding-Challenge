class Solution {
public:
    string removeDuplicateLetters(string s) {
        string fi;
unordered_map<char, int> m;

 for(int i=0;i<s.length();i++)
     m[s[i]]++;
 
 if(fi.length()==m.size())
     return fi;
 
 for(int i=0;i<s.length();i++){
     
     while(fi.length()>0 && fi.back()>s[i] && m[fi.back()]>0 && fi.find(s[i])==-1)
         fi.pop_back();
         
     
     if(fi.find(s[i])==-1)
         fi.push_back(s[i]);
     
     m[s[i]]--;
 }    
 return fi;
    }
};