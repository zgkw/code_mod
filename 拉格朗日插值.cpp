template<int P = ::P, class T1 , class T2>
constexpr Poly<P> Lagrange (T1 x, T2 y) {
    int n = x.size () ;
    vector <Poly<>> M ( 4 * n );
    std::function<void(int, int, int)> build = [&](int p, int l, int r) {
        if (r - l == 1) {
            M[p] = Poly{(int)-x[l], 1};
        } else {
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            M[p] = M[2 * p] * M[2 * p + 1];
        }
    };
    build ( 1 , 0 , n ) ;
    auto M_ = M[1].deriv().eval( x );
    for ( int i = 0 ; i < n ; ++ i ) {
        M_ [ i ] = y [ i ] * M_ [ i ].inv () ;
    }
    vector<Poly<>> f (4 * n) ;
    std::function<void(int, int, int)> work = [&](int p, int l, int r) -> void {
        if (r - l == 1) {
            if (l < n) {
                f[p] = Poly{(int)M_[l]};
            }
        } else {
            int m = (l + r) / 2;
            work(2 * p, l, m);
            work(2 * p + 1, m, r);
            f [ p ] = f [ 2 * p ] * M [ 2 * p + 1 ] + f [ 2 * p + 1 ] * M [ 2 * p ] ;
        }
    };
    work ( 1 , 0 , n ) ;
    return f[1];
}
