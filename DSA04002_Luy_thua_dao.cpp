#include <bits/stdc++.h>

using namespace std;
/*
n mũ k bất kì có thể viết được thành 2 dạng
    n^k= n^(k/2) * n^(k/2) nếu k chẵn
    n^k= n^(k/2) * n^(k/2) * n nếu k lẻ
*/
long long MOD = 1e9 + 7;
long long Pow(long long n,long long k){
    if(k == 0){
        return 1;// n mũ 0 bằng 1; x=1 -> y 
    }
    long long x = Pow(n,k/2);// chia thành các phần tử nhỏ hơn để tính
    long long y = (x*x)%MOD;
    if(k % 2 != 0){
        return (y*n) % MOD;
    }else{
        return y % MOD;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long n; cin >> n;
        long long k=0;
        long long m=n; // de het vong wile khong thay doi n
        while(m>0){ // k la so dao cua n
            k = k*10 + m%10;
            m /= 10;
        }
        cout << Pow(n,k) << endl;
    }
    system("pause");
    return 0;
}