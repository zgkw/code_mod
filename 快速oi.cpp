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
struct __setprecision {
    int precision ;
};
__setprecision setprecision (int x) { return __setprecision {x};}
struct Fastout {
# define MAXSIZE (1 << 20)
# define cout out 
char pbuf[MAXSIZE], *pp = pbuf ;
    void push(const char &c) {
        if (pp - pbuf == MAXSIZE) 
            fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
        *pp++ = c;
    }
    int precision ;
    Fastout () { precision = 6 ;}
    ~Fastout () { fwrite(pbuf, 1, pp - pbuf, stdout);}
    template<class T>
    Fastout& operator<< (const T& x) {
        T tmp = x ;
        bool _ = tmp < 0 ;
        if (_) push ('-'), tmp *= -1;
        while ( tmp ) push ('0' + (tmp % 10)), tmp /= 10;
        return *this ;
    }
    Fastout& operator<< (const string& x) {
        for (auto&u : x) push (u);
        return *this;
    }
    template<size_t N>
    Fastout& operator<< (const char(&x)[N]) {
        *this << string (x) ;
        return *this;
    }
    Fastout& operator<< (const char& x) {
        push (x);
        return *this;
    }
    Fastout& operator<< (const bool& x) {
        push (x ? '1' : '0');
        return *this;
    }
    Fastout& operator<<(const double& x) {
        int intPart = static_cast<int>(x);
        *this << intPart; // Output the integer part

        push('.'); // Decimal point
        
        double decimalPart = x - intPart;
        for (int i = 0; i < precision; ++i) {
            decimalPart *= 10;
            int digit = static_cast<int>(decimalPart);
            *this << char('0' + digit);
            decimalPart -= digit;
        }
        return *this;
    }
    Fastout& operator<< (const __setprecision& x) {
        precision = x.precision ;
        return *this ;
    }
}cout;
