class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> map;
        int seq  = 0;
        for(int i=0; i<order.length(); i++){
            map[order[i]-'a'] = seq++;
        }
        
        for(int i=0; i<words.size()-1; i++)
        {
            string word1 = words[i];
            string word2 = words[i+1];
            
            int l1 = word1.length();
            int l2 = word2.length();
            
            int l = min(l1, l2);
            
            if(l!=l1 && l == l2)
                if(word1.find(word2, 0)==0)
                    return false;
            
            for(int j=0;j<l;j++)
            { 
                
                auto a =  map.find(word1[j]-'a');
                auto b = map.find(word2[j]-'a');
                
                if(a->second > b->second)
                  return false;
                
                else if(a->second < b->second)
                    break;
            }
        }
            return true;
    }
};