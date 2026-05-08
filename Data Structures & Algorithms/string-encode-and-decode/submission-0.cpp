class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string coded = "";
        for(auto &m: strs) {
            coded += to_string(m.size());
            coded += '#';
            coded += m;
        }
        return coded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        size_t found; 
        string size_;
        int index = 0;
        int message_len;
        while(index < s.size()) {
            found = s.find('#',index);
            if(found != string::npos) {
                size_ = s.substr(index, found-index);
                message_len = stoi(size_);
                string message = s.substr(found+1, message_len);
                ans.push_back(message);
            }
            index = found+message_len+1;
        }
        return ans;
    }
};
