class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";

        for (string &word : strs) {
            // Store: length#word
            // Example: "Hello" -> "5#Hello"
            encoded += to_string(word.size()) + "#" + word;
        }

        return encoded;
    }

    // Decodes a single string back to the original list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;

        while (i < s.size()) {

            // Find the '#' that separates the length and the word
            int j = s.find('#', i);

            // Convert the length substring into an integer
            int len = stoi(s.substr(i, j - i));

            // Extract the actual word of 'len' characters
            decoded.push_back(s.substr(j + 1, len));

            // Move i to the start of the next encoded word
            i = j + 1 + len;
        }

        return decoded;
    }
};