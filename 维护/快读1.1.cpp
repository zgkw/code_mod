struct Fastin {
    using Long = long long ;
    # define cin in 
    Fastin () {}
    # define MAXSIZE (1 << 20)
    # define isdigit(x) (x >= '0' && x <= '9')

    char buf[MAXSIZE], *p1 = buf, *p2 = buf;

    char gc() {
        if (p1 == p2) 
            p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        return p1 == p2 ? ' ' : *p1++;
    }

    bool blank(char ch) {
        return ch == ' ' || ch == '\n' 
            || ch == '\r' || ch == '\t' || ch == EOF;
    }
    template <typename T>
    Fastin& operator>> (T&x) {
        x = 0 ;
        bool sign = 0;
        char ch = gc();
        for (; !isdigit(ch); ch = gc())
            if (ch == '-') sign = 1;
        for (; isdigit(ch); ch = gc()) 
            x = (x << 3) + (x << 1) + ch - '0';
        if (sign)x = -x;
        return *this ;
    }
    Fastin& operator>> (char&x) {
        x = ' ';
        for (; blank(x); x = gc ()) ;
        return *this ;
    }
    Fastin& operator>> (double&x) {
        x = 0 ;
        double tmp = 1;
        bool sign = 0;
        char ch = gc();
        for (; !isdigit(ch); ch = gc())
            if (ch == '-') sign = 1;
        for (; isdigit(ch); ch = gc()) 
            x = x * 10 + ch - '0';
        if (ch == '.')
        for (ch = gc(); isdigit(ch); ch = gc())
            tmp /= 10.0, x += tmp * (ch - '0');
        if (sign) x = -x;
        return *this ;
    }
    Fastin& operator>>(string&s) {
        s.clear() ;
        char ch = gc();
        for (; blank(ch); ch = gc());
        for (; !blank(ch); ch = gc()) {
            s += ch ;
        }
        return *this ;
    }
}cin;
