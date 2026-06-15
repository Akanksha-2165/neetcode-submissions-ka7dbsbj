class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if(dict.find(endWord) == dict.end())
            return 0;

        
        queue <pair<string, int>> q;

        q.push({beginWord,1});

        while(!q.empty())   {
            string word=q.front().first;
            int len= q.front().second;
            q.pop();

            if(word== endWord)
                return len;
            
            for(int i=0;i< beginWord.size();i++)    {
                char original= word[i];

                for(char ch= 'a'; ch<= 'z' ; ch++)  {
                    if(ch ==original)
                        continue;
                    word[i]=ch;
                    if(dict.count(word))    {
                        q.push({word,len+1});
                        dict.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};
