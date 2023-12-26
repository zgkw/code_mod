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
