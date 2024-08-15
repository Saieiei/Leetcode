class Solution {
public:
bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;

    // Iterate over each customer in the queue
    for (int bill : bills) {
        if (bill == 5) {
            // If the customer pays with a $5 bill, just collect it
            five++;
        } else if (bill == 10) {
            // If the customer pays with a $10 bill, we need to give back a $5 bill as change
            if (five > 0) {
                five--; // Give out one $5 bill
                ten++;  // Collect the $10 bill
            } else {
                return false; // Not enough $5 bills to give change
            }
        } else if (bill == 20) {
            // If the customer pays with a $20 bill, we need to give back $15 as change
            if (ten > 0 && five > 0) {
                // Prefer to give one $10 bill and one $5 bill as change
                ten--;
                five--;
            } else if (five >= 3) {
                // If no $10 bill is available, give three $5 bills as change
                five -= 3;
            } else {
                return false; // Not enough bills to give change
            }
        }
    }
    return true; // All customers received the correct change
}
};