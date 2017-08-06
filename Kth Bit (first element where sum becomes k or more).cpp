// it is not verified yet
class FenwickTree {
private:
  vi ft;
int d;
public:
  FenwickTree() {}
  // initialization: n + 1 zeroes, ignore index 0
  FenwickTree(int n) {d=n; ft.assign(n + 1, 0); }

  int kth(int v){
      int m=d,a=d,ans=-1;
        while(a)
        {
            a>>=1;
            if(ft[m]>=v)
            {
                ans=m;
                m-=a;
            }
            else {
                v-=ft[m];
                m+=a;
            }
        }
        return ans;
  }
  // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
  void adjust(int k, int v) {                    // note: n = ft.size() - 1
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};
