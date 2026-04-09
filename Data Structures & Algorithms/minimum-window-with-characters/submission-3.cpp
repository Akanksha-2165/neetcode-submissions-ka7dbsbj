class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty())    return "";
        unordered_map<char,int> cnt,window; //cnt-> maps freq of each char in str t
                                            //window->maps the current window freq
        for(char ch: t)         // mapping t            
            cnt[ch]++;

        int have=0,need=cnt.size();
        int l=0, resLen=INT_MAX;
        pair<int,int> res {-1,-1};

        for(int r=0;r<s.size();r++) {
            char c=s[r];
            window[c]++;
            
            if(cnt.count(c)&& (cnt[c]==window[c]))
                have++;

            while(need==have)   {
                if(r-l+1<resLen)    {
                    resLen=r-l+1;
                    res={l,r};
                }

                window[s[l]]--;
                if(cnt.count(s[l]) && cnt[s[l]]>window[s[l]])
                    have--;

                l++;
            }
        }
        return resLen==INT_MAX ? "" : s.substr(res.first,resLen);
    }
};
