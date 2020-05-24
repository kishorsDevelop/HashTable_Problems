/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of 
substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
*/

 vector<int> findSubstring(string s, vector<string>& words) {
        if(s.length() == 0 || words.size() == 0) {
           return {};   
        }
        vector<int> res;
        int word_count = words.size();
        int word_length = words[0].length();
        int full_word_size = word_length * words.size();
        
        if(full_word_size > s.length()){
            return res;
        }
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        for(int i=0;i<=s.length()-full_word_size;i++)
        {                                                        // checking for each word in every substring
            unordered_map<string,int> temp(mp);
            int j = i;
            int count = word_count;
            while(j<i+full_word_size){
                   string word = s.substr(j,word_length);
                
                   if(mp.find(word) == mp.end() || temp[word] == 0){
                       break;
                   }else{
                           temp[word]--;
                           count--;
                           
                   }
                j+=word_length;
            }
            if(count == 0){
                res.push_back(i);
            }
        }
        return res;
 }
