class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> atomCount; // Map to store the count of each element
        stack<map<string, int>> stk; // Stack to manage nested parentheses
        int i = 0;
        int n = formula.size();

        while (i < n) {
            if (formula[i] == '(') {
                // Push current map to stack and start a new map for nested group
                stk.push(atomCount);
                atomCount.clear();
                i++;
            } else if (formula[i] == ')') {
                // Handle closing parenthesis and multiply counts by the number following it
                map<string, int> temp = atomCount;
                atomCount = stk.top();
                stk.pop();
                i++;
                int count = 0;
                while (i < n && isdigit(formula[i])) {
                    count = count * 10 + (formula[i] - '0');
                    i++;
                }
                if (count == 0) count = 1;
                // Multiply counts in the temporary map and add them to the current map
                for (auto &p : temp) {
                    atomCount[p.first] += p.second * count;
                }
            } else {
                // Handle element parsing and counting
                string element;
                element += formula[i++]; // First character is always uppercase
                if (i < n && islower(formula[i])) {
                    element += formula[i++]; // Add lowercase characters if present
                }
                int count = 0;
                while (i < n && isdigit(formula[i])) {
                    count = count * 10 + (formula[i] - '0');
                    i++;
                }
                if (count == 0) count = 1;
                // Add element and its count to the map
                atomCount[element] += count;
            }
        }

        // Convert map to sorted vector and build result string
        vector<pair<string, int>> sortedAtoms(atomCount.begin(), atomCount.end());
        sort(sortedAtoms.begin(), sortedAtoms.end());

        string result;
        for (auto &p : sortedAtoms) {
            result += p.first; // Add element name
            if (p.second > 1) {
                result += to_string(p.second); // Add count if greater than 1
            }
        }

    return result;
}
};