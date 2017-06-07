#define MAX_N 200010                         // second approach: O(n log n)

#define LOG_TWO_N 18 // 2^18 > 200010, adjust this value as needed
int _A[MAX_N], SpT[LOG_TWO_N][MAX_N];
int Log[MAX_N];
class RMQ { // Range Minimum Query
private:
public:
RMQ(int n, vi A) { // constructor as well as pre-processing routine
for (int i = 0; i < n; i++) {
_A[i] = A[i];
SpT[0][i] = i; // RMQ of sub array starting at index i + length 2^0=1
}
// the two nested loops below have overall time complexity = O(n log n)
for (int j = 1; (1<<j) <= n; j++) // for each j s.t. 2^j <= n, O(log n)
for (int i = 0; i + (1<<j) - 1 < n; i++) // for each valid i, O(n)
if (_A[SpT[j-1][i]] < _A[SpT[j-1][i+(1<<(j-1))]]) // RMQ
SpT[j][i] = SpT[j-1][i]; // start at index i of length 2^(j-1)
else // start at index i+2^(j-1) of length 2^(j-1)
SpT[j][i] = SpT[j-1][i+(1<<(j-1))];
}
int rmq(int i, int j) { // this query is O(1)
int k = Log[j-i+1]; // 2^k <= (j-i+1) . Never use log() function.
if (_A[SpT[k][i]] <= _A[SpT[k][j-(1<<k)+1]]) return _A[SpT[k][i]];
else return _A[SpT[k][j-(1<<k)+1]];
} };
int main()
{
    int prev=0;
    for(int i=0;i<19;i++)
    {
        int temp=1<<i;
        for(int j=prev+1;j<=(prev+temp)&&j<MAX_N;j++) Log[j]=i;
        prev+=temp;
    }
   // ...
    vi A;
   // ...
    RMQ st=(A.size(),A);
   // ...
}
