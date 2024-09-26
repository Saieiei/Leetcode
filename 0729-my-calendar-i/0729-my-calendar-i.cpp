class MyCalendar {
private:
    // Vector to store the bookings as pairs of start and end times
    vector<pair<int, int>> bookings;

public:
    // Constructor to initialize the MyCalendar object
    MyCalendar() {
        // Empty constructor, no specific initialization needed
    }

    // Function to book an event if no overlap occurs
    bool book(int start, int end) {
        // Check all previously stored bookings to ensure no overlap
        for (const auto& booking : bookings) {
            int bookedStart = booking.first;
            int bookedEnd = booking.second;

            // Check if the current booking overlaps with any existing booking
            if (max(bookedStart, start) < min(bookedEnd, end)) {
                // If there's an overlap, return false
                return false;
            }
        }

        // If no overlap found, add the booking
        bookings.push_back({start, end});

        // Return true indicating the booking was successful
        return true;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */