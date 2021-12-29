class Solution {
public:
    string minWindow(string s, string t) {
        //edge cases
        if(t.length() > s.length()) {
            return "";
        }
//         if(t.length() == s.length())
//         {
//             if(t.compare(s) == 0) {
//                 return t;
//             } else {
//                 return "";
//             }
            
//         }
        int left = 0, right = 0;
        int minLength = INT_MAX;
        int bestLeft, bestRight = 0;
        unordered_map<char, int> char_count, char_encountered;
        int fulfilled = 0;
        
        //we  fill up char_count with each character and how many times it appears in the string
        for(int i = 0; i < t.length(); i++) {
            char_count[t[i]]++;
        }
        int required = char_count.size();
        
        while(right < s.length() || fulfilled == required) 
        {
            //increment right side (grow substring) if still not meeting all criteria
            if(fulfilled < required) {
                char current = s[right];
                //check relevance of encountered char
                if(char_count.count(current)) {
                    //this is a relevant letter
                    char_encountered[current]++;
                    if(char_encountered[current] == char_count[current]) {
                        fulfilled++;
                    }
                }
                right++;
            }
            
            //increment left side if we have a valid substring
            else {
                char current = s[left];
                if(char_count.count(current)) {
                    //this is a relevant letter
                    char_encountered[current]--;
                    if(char_encountered[current] < char_count[current]) {
                        fulfilled--;
                    }                    
                }
                left++;
            
                if(right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    bestLeft = left - 1;
                    bestRight = right;
                }
            }
            
        }
        if(minLength == INT_MAX) {
            return "";
        } else {
            return s.substr(bestLeft, minLength);
        }
    }
};