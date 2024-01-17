#include <vector>
#include <algorithm>
using namespace std;

class Job {
public:
    int startTime;
    int endTime;
    int profit;

    Job(int start, int end, int p) : startTime(start), endTime(end), profit(p) {}

    // Overloaded less than operator for sorting by startTime
    bool operator<(const Job& other) const {
        return startTime < other.startTime;
    }
};

class Solution {
public:
    int recur(int s, vector<int>& dp, vector<Job>& jobs) {
        if (s >= dp.size()) return 0;
        if (dp[s] != -1) return dp[s];

        int nextNonOverlap = s + 1;
        while (nextNonOverlap < dp.size() && jobs[nextNonOverlap].startTime < jobs[s].endTime)
            nextNonOverlap++;

        int take = jobs[s].profit + recur(nextNonOverlap, dp, jobs);
        int skip = recur(s + 1, dp, jobs);

        return dp[s] = max(take, skip);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<Job> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back(Job(startTime[i], endTime[i], profit[i]));
        }

        sort(jobs.begin(), jobs.end());
        vector<int> dp(n, -1);

        return recur(0, dp, jobs);
    }
};
