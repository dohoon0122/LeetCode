class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int remain = n - m;
        auto customCompareLambda = [](pair<int, int>& a, pair<int, int>& b){
            return (long long)a.first*b.second < (long long)a.second*b.first;
        };
        priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(customCompareLambda)> store; 

        for(int q: quantities){
            store.push(make_pair(q, 1));
        }

        while(remain){
            auto curr = store.top();
            store.pop();
            curr.second++;

            store.push(curr);
            remain--;
        }


        return ceil((double)store.top().first / store.top().second);
    }
};

/*
n 개 상점, m type product
일단 m개 상점에 다 넣기

15 10 10 0 0 0 0
그 다음 distribute.
max_heap 뽑아낸뒤, top 절반, 다시 넣고, remain 0 될때까지
7 10 10 8 0 0 0
7 5 10 8 5 0 0
7 5 5 8 5 5 0
7 5 5 4 5 5 4 -> 반례

-------
=> top 절반이 아니라, 같은type의 max 갯수로 하면 되는듯?
15 10 10  remain 4
8 10 10 remain 3
8 5 5 remain 1
15, 1, 


*/