class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if (intervals.empty()) {
        	intervals.push_back(newInterval);
        	return intervals;
        }
        vector<Interval> output;
        bool overlappingfound = false;
        auto it = intervals.begin();
        while (it < intervals.end() || !overlappingfound) {
        	if (it == intervals.end() && !overlappingfound) {
        		output.push_back(newInterval);
                break;
        	}
        	if (newInterval.end < it->start && !overlappingfound) {
        		output.push_back(newInterval);
        		overlappingfound = true;
        	} else if (newInterval.start > it->start && newInterval.start <= it->end && !overlappingfound) {
        		newInterval.start = it->start;
        	}
        	if (newInterval.end < it->end && !overlappingfound) {
        		newInterval.end = it->end;
        		output.push_back(newInterval);
        		overlappingfound = true;
        	}
        	if (newInterval.end < it->start || newInterval.start > it->end) {
        		output.push_back(*it);
        	}
        	it++;
        }
        return output;
    }
};
