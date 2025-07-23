#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        return (x > y)
                   ? removePairs(s, "ab", x, "ba", y)
                   : removePairs(s, "ba", y, "ab", x);
    }

private:
    int removePairs(string &s, const string &first, int firstGain, const string &second, int secondGain)
    {
        int result = 0;
        stack<char> stk;

        // First pass: remove all occurrences of `first`
        for (char c : s)
        {
            if (!stk.empty() && stk.top() == first[0] && c == first[1])
            {
                stk.pop();
                result += firstGain;
            }
            else
            {
                stk.push(c);
            }
        }

        // Prepare string for second pass
        string remaining;
        while (!stk.empty())
        {
            remaining += stk.top();
            stk.pop();
        }
        reverse(remaining.begin(), remaining.end());

        // Second pass: remove all occurrences of `second`
        for (char c : remaining)
        {
            if (!stk.empty() && stk.top() == second[0] && c == second[1])
            {
                stk.pop();
                result += secondGain;
            }
            else
            {
                stk.push(c);
            }
        }

        return result;
    }
};

int main()
{
    string s = "cdbcbbaaabab";
    int x = 4, y = 5;
    int expected = 19;

    Solution sol;
    int res = sol.maximumGain(s, x, y);

    if (res == expected)
    {
        cout << "Test passed!" << endl;
    }
    else
    {
        cout << "Test failed!" << endl;
    }
    cout << res << '\n';

    return 0;
}
