class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int suma = 0, sumb = 0;
        for(int i : A)
            suma += i;
        for(int j : B)
            sumb += j;
        int avg = (suma + sumb) / 2;
        
        // printf("avg = %d\n", avg);
        
        sort(B.begin(), B.end());
        
        for(int i : A) {
            // printf("check %d   ", i);
            int temp = avg - (suma - i);
            // printf("temp = %d\n", temp);
            auto it = lower_bound(B.begin(), B.end(), temp);
            if(*it == temp) {
                return {i, temp};
            }
        }
    }
};