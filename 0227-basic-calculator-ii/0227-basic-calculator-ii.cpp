
class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int i = 0;
        int n = s.size();

        // Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Read the first number
        int num = 0;

        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            i++;
        }

        stk.push(num);

        // Process the remaining operators and numbers
        while (i < n) {
            // Skip spaces
            while (i < n && s[i] == ' ') {
                i++;
            }

            if (i == n) {
                break;
            }

            // Read the operator
            char op = s[i];
            i++;

            // Skip spaces after the operator
            while (i < n && s[i] == ' ') {
                i++;
            }

            // Read the next complete number
            num = 0;

            while (i < n && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }

            // Apply the operator
            if (op == '+') {
                stk.push(num);
            }
            else if (op == '-') {
                stk.push(-num);
            }
            else if (op == '*') {
                int a = stk.top();
                stk.pop();

                stk.push(a * num);
            }
            else if (op == '/') {
                int a = stk.top();
                stk.pop();

                stk.push(a / num);
            }
        }

        // Add all signed terms
        int ans = 0;

        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }

        return ans;
    }
};
