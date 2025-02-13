class Solution {
public:
/*
    We are given an array of integers "nums" and an integer "k". In a single operation, we:

        1. Take the two smallest integers x and y in nums.
        2. Remove x and y from nums.
        3. Add (min(x, y) * 2 + max(x, y)) to nums.

    We want to find the minimum number of such operations required so that
    all elements in nums are >= k.

    Key Idea:
    ----------
    - We use a min-heap (priority_queue in C++ with greater<int>) to always pick the two smallest elements.
    - Combine them according to the formula:
         newValue = 2 * min(x, y) + max(x, y)
      and push it back into the min-heap.
    - We repeat this process until the smallest element in the heap is >= k (or until we are down to one element).
    - The number of times we do this "combine" step is the answer.

    Why does this greedy approach work?
    ------------------------------------
    - Combining the two smallest elements first ensures we do not waste large values 
      on smaller values, and this is a known strategy (similar to "Scoville" or "Spicy" type problems).
    - The minimum number of operations is achieved by repeatedly combining the smallest pair 
      to boost their value and push it back into the array.

    Complexity:
    ------------
    - Building the min-heap from nums: O(n).
    - Each operation involves:
        * Extracting two smallest elements from the heap: O(log n) each pop.
        * Inserting one element back: O(log n).
      In the worst case, you could be doing as many as n-1 operations (if you end up combining until one element remains).
      So overall complexity: O(n log n) in the worst case.

    Edge Cases to Consider:
    ------------------------
    - If nums already has all elements >= k, the answer is 0.
    - If at any point the heap has fewer than 2 elements but the smallest is still < k, 
      it might be impossible (depending on problem statement). 
      However, from the given statement and examples, it seems we can always combine 
      until we either have a single large element or all are >= k. 
      The problem examples do not mention an impossibility scenario.

    Let's implement the solution now.
*/
    int minOperations(vector<int>& nums, int k) {
         // Min-heap with long long
    priority_queue<long long, vector<long long>, greater<long long>> minHeap(nums.begin(), nums.end());

    int operations = 0;

    // While the smallest element in the heap is less than k
    while (!minHeap.empty() && minHeap.top() < k) {
        // If we don't have at least 2 elements to combine, we can't proceed
        if (minHeap.size() < 2) {
            // If there's only one element left and it's still < k, not possible
            return -1;
        }

        // Pop the two smallest elements
        long long x = minHeap.top();
        minHeap.pop();
        long long y = minHeap.top();
        minHeap.pop();

        // Combine using 64-bit arithmetic
        long long newValue = 2LL * min(x, y) + max(x, y);

        // Push the new value back
        minHeap.push(newValue);
        operations++;
    }

    // If the smallest element is >= k, we succeeded
    if (!minHeap.empty() && minHeap.top() >= k) {
        return operations;
    }

    // If we reach here, it is not possible to make all >= k
    return operations; // or -1 if that's the intended meaning
    }
};