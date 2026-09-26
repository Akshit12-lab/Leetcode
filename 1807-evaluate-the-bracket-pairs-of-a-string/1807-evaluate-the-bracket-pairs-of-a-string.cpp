class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string, string> mp;
        
        for (auto& item : knowledge) {
            mp[item[0]] = item[1];
        }
        
        string answer;
        
        for (int i = 0; i < s.length(); i++) {
            
            if (s[i] == '(') {
                
                i++;
                
                string key;
                
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }
                
                if (mp.find(key) != mp.end()) {
                    answer += mp[key];
                }
                else {
                    answer += "?";
                }
            }
            else {
                answer += s[i];
            }
        }
        
        return answer;
    }
};