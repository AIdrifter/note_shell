/*
 * @lc app=leetcode id=346 lang=cpp
 *
 * [346] Moving Average from Data Stream
 *
 * https://leetcode.com/problems/moving-average-from-data-stream/description/
 *
 * algorithms
 * Easy (64.64%)
 * Total Accepted:    66.6K
 * Total Submissions: 103K
 * Testcase Example:  '["MovingAverage","next","next","next","next"]\n[[3],[1],[10],[3],[5]]'
 *
 * Given a stream of integers and a window size, calculate the moving average
 * of all integers in the sliding window.
 *
 * Example:
 *
 *
 * MovingAverage m = new MovingAverage(3);
 * m.next(1) = 1
 * m.next(10) = (1 + 10) / 2
 * m.next(3) = (1 + 10 + 3) / 3
 * m.next(5) = (10 + 3 + 5) / 3
 *
 *
 *
 *
 */
class MovingAverage {
public:

    vector<int> S;
    int window_size = 0;
    int base_cnt = 0;
    int idx = 0;

    /** Initialize your data structure here. */
    MovingAverage(int size) {
        window_size = size;
        S.resize(window_size);
        return;
    }

    double next(int val) {
        double sum = 0;
        S[idx] = val;

        if(++base_cnt == window_size + 1 )
            base_cnt = window_size;

        if(idx++==window_size-1)
            idx = 0;

        for(int i =0; i< window_size ;i++)
            sum += S[i];

        return sum/base_cnt;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
