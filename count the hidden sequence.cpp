  int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        vector<int > v(n+1 , 0);
        int i;
        long long int  sum = lower;
        v.push_back(lower);
        long long int minval = INT_MAX;
        long long int maxval = INT_MIN;
         minval = min(minval , sum);
        maxval = max(maxval , sum);
        for(i=0;i<n;i++ )
        {
            sum = sum + differences[i];
            // v.push_back(sum);
            minval = min(minval , sum);
            maxval = max(maxval , sum);
        }
        int d = 0;
        if(minval < lower)
        {
            d = lower - minval;
            maxval = maxval + d;
        }
        if(maxval >upper)
        {
            return 0;
        }
        return upper-maxval + 1;
    }
