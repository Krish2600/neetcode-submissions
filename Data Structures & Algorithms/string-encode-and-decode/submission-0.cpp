class Solution {                          // approach 1: add # or special character between strings
public:                                   // Eg- [hello#world]


                                          // approach 2: add the length of each string in binary before 
                                          // every string
                                          // Eg- [0101hello0101world] 5-> 0101 in binary

                                          // approach 3: mix of above 2
                                          // Eg- [5#hello5#world]



    string encode(vector<string>& strs) {  
        string encoded = "";

        for(string& str : strs){     // converting the str len which is int into a char
            encoded += to_string(str.size()) + '#' + str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i=0;

        while(i<s.size()){
            int j=i;

            while(s[j] != '#'){              //finding the delimiter
                j++;
            }

            int len = stoi(s.substr(i,j-i));    //converting the length char back to int

            string word = s.substr(j+1,len);    // extracting the word of len length
            result.push_back(word);             // adding the word to the result vector

            i = j+1+len;                        // moving i to the beginning of next encoded string
        }
        return result;

    }
};
