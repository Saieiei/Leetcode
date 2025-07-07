class Solution {
public:
    int myAtoi(const string& s) {
        int i = 0, n = s.size();
        // 1) skip leading spaces
        while (i < n && isspace(s[i])) 
            ++i;
        // 2) handle optional sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            ++i;
        }
        // 3) if next char isn't a digit, we return 0
        if (i >= n || !isdigit(s[i])) 
            return 0;
        // 4) parse digits
        long long result = 0;  // use long long to detect overflow
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            // 5) clamp if overflow
            if (sign == 1 && result > INT_MAX) 
                return INT_MAX;
            if (sign == -1 && -result < INT_MIN) 
                return INT_MIN;
            ++i;
        }
        return int(sign * result);
    }
};