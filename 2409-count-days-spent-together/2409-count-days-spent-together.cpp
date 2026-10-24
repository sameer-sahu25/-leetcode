class Solution {
public:
    int days(string date) {
        vector<int> monthDays = {31,28,31,30,31,30,31,31,30,31,30,31};

        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int total = day;

        for (int i = 0; i < month - 1; i++) {
            total += monthDays[i];
        }

        return total;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int start = max(days(arriveAlice), days(arriveBob));
        int end = min(days(leaveAlice), days(leaveBob));

        if (start > end) return 0;

        return end - start + 1;
    }
};