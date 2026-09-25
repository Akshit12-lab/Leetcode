class Solution {
public:

    set<string> parse(string& s, int& i) {

        set<string> result;
        set<string> current = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {

                i++;

                set<string> inside = parse(s, i);

                i++;

                set<string> temp;

                for (string a : current) {
                    for (string b : inside) {
                        temp.insert(a + b);
                    }
                }

                current = temp;
            }

            else if (s[i] == ',') {

                for (string word : current) {
                    result.insert(word);
                }

                current = {""};
                i++;
            }

            else {

                set<string> temp;

                for (string word : current) {
                    temp.insert(word + s[i]);
                }

                current = temp;

                i++;
            }
        }

        for (string word : current) {
            result.insert(word);
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> answerSet = parse(expression, i);

        vector<string> answer;

        for (string word : answerSet) {
            answer.push_back(word);
        }

        return answer;
    }
};