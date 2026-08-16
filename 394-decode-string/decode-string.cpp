class Solution {
public:
    string decodeString(string s) {
        if(s.length() == 0) return s;
        
        // Initialize trackers
        string ans = "";
        int currNum = 0;
        stack<int> intStack;
        stack<string> strStack;

        for(auto &x : s) {
            if(x >= '0' && x <= '9') { 
                // Build the multiplier (handles multi-digit numbers)
                currNum = (currNum * 10) + (x - '0');
            } 
            else { 
                // x is an alphabet character or bracket
                if(x == '[') {
                    // Save state and go a level deeper
                    intStack.push(currNum);
                    currNum = 0;
                    
                    string temp = "";
                    temp += x;
                    strStack.push(temp);
                }
                else if(x == ']') {
                    // Unpack the current level
                    string temp = "";
                    while(!strStack.empty() && strStack.top() != "[") {
                        temp = strStack.top() + temp;
                        strStack.pop();
                    }
                    strStack.pop(); // Remove the "["
                    
                    int num = intStack.top();
                    intStack.pop();
                    
                    // Multiply the string
                    string temp_ans = "";
                    for(int i = 0; i < num; ++i) {
                        temp_ans += temp;
                    }
                    
                    // Push the expanded string back onto the stack
                    strStack.push(temp_ans);
                } 
                else {
                    // Just a regular letter
                    string temp = "";
                    temp += x;
                    strStack.push(temp);
                }
            }
        }
        
        // Assemble final answer
        while(!strStack.empty()) {
            ans = strStack.top() + ans;
            strStack.pop(); 
        }
        
        return ans;
    }
};