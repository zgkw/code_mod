struct Miller_Rabin_Test {
    using i64 = long long ;using ll = long long ;
    using Long = MLong<0> ;
    vector<ll> ud;
    Miller_Rabin_Test () { ud ={2,325,9375,28178,450775,9780504,1795265022} ; } 
    bool operator()(ll n)//Miller Rabin Test
    {
        MLong<0>::setMod (n);
        if(n < 3 || n % 2 == 0) 
            return n == 2;//特判
        ll u = n - 1, t = 0;
        while(u % 2 == 0) u /= 2, ++ t;
        for(Long a : ud) {
            Long v = power(a, u);
            if(v == 1 || v == n - 1 || v == 0) continue;
            for(int j = 1; j <= t; j ++) {
                v= power(v, (i64)v);
                if(v == n - 1 && j != t) 
                    {v = 1; break;}//出现一个n-1，后面都是1，直接跳出
                if(v == 1) return 0;//这里代表前面没有出现n-1这个解，二次检验失败
            }
            if(v != 1) return 0;//Fermat检验
        }
        return 1;
    }
} Isprime;
