bool isPossible(vector<int>& boards, int k, int mid) {
    int painters = 1, time = 0;
    for(int length : boards) {
        if(time + length > mid) {
            painters++;
            time = length;
            if(painters > k) return false;
        } else {
            time += length;
        }
    }
    return true;
}

int minTime(vector<int>& boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    int ans = high;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(isPossible(boards, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
