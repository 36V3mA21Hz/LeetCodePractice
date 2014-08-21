class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		if (intervals.empty())
			return{};
		for (int i = intervals.size() - 1; i >= 0; i--) {
			bool allSplitted = false;
			while (!(allSplitted || i == intervals.size() - 1)) {
				int j = i + 1;
				allSplitted = true;
				while (j < intervals.size()) {
					if (intervals[i].end < intervals[j].start || intervals[i].start > intervals[j].end) {
						allSplitted &= true;
						j++;
					}
					else {
						allSplitted = false;
						swap(intervals[j].start, intervals.back().start);
						swap(intervals[j].end, intervals.back().end);
						intervals[i].start = min(intervals[i].start, intervals.back().start);
						intervals[i].end = max(intervals[i].end, intervals.back().end);
						intervals.pop_back();
					}
				}
			}
		}
		return intervals;
	}
};