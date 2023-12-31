

class Solution
{
  public:
    long long minTime(int arr[], int n, int k)
    {
        long long low = *max_element(arr, arr + n);
        long long high = accumulate(arr, arr + n, 0LL);
        
        auto isPossible = [&](long long time) {
            long long total_time = 0;
            int painters = 1;
            for(int i = 0; i < n; i++) {
                if(arr[i] > time) return false;
                total_time += arr[i];
                if(total_time > time) {
                    total_time = arr[i];
                    painters++;
                    if(painters > k) return false;
                }
            }
            return true;
        };
        
        while(low < high) {
            long long mid = low + (high - low) / 2;
            if(isPossible(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};