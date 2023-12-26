namespace Fastio {
using ll = long long ;
# define MAXSIZE (1 << 20)
# define isdigit(x) (x >= '0' && x <= '9')
# define Rd(...) \
	ll __VA_ARGS__ ; \
	rd ( __VA_ARGS__ )

char buf[MAXSIZE], *p1 = buf, *p2 = buf;
char pbuf[MAXSIZE], *pp = pbuf ;
char _0 = ' ' , _1 = '\n' , _2 = ',' ;
void push(const char &c) {
	if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
	*pp++ = c;
}

inline char gc() {
	return getchar();
	if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
	return p1 == p2 ? ' ' : *p1++;
}

inline bool blank(char ch) {
	return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}

template <class T>
T read( T & x ) {
	x = 0 ;
	bool sign = 0;
	char ch = gc();
	for (; !isdigit(ch); ch = gc())
		if (ch == '-') sign = 1;
	for (; isdigit(ch); ch = gc()) x = ( x << 3 ) + ( x << 1 ) + ch - '0';
	if (sign) x = -x;
	return x ;
}

template <>
double read<double>( double & x) {
	x = 0 ;
	double tmp = 1;
	bool sign = 0;
	char ch = gc();
	for (; !isdigit(ch); ch = gc())
		if (ch == '-') sign = 1;
	for (; isdigit(ch); ch = gc()) x = x * 10 + ch - '0';
	if (ch == '.')
	for (ch = gc(); isdigit(ch); ch = gc())
		tmp /= 10.0, x += tmp * (ch - '0');
	if (sign) x = -x;
	return x ;
}

template<>
string read<string>( string & s ) {
	s.clear() ;
	char ch = gc();
	for (; blank(ch); ch = gc());
	for (; !blank(ch); ch = gc()) s += ch;
	return s ;
}

template<>
char read<char>(char & c) { c = ' ' ; for (c = gc(); blank(c); c = gc()); return c ; }


void rd () {}
template<typename Type, typename... Types>
void rd(Type& arg, Types&... args) {
    read<Type>( arg );
    rd(args...);
}

template < typename T > 
void write ( T & x ) {
	std::ostringstream stream ;
	stream << x  ;
	string s = stream.str () ;
	for ( auto u : s ) push ( u ) ;
}

template <>
void write < double > ( double & x ) {
	int x_l = 3 ;
	std::ostringstream stream ;
	stream << fixed << setprecision ( x_l ) << x  ;
	string s = stream.str () ;
	for ( auto u : s ) push ( u ) ;
}

template <>
void write < string > ( string & x ) {
	for ( auto u : x ) push ( u ) ;
}

template <>
void write < char > ( char & x ) {
	push ( x ) ;
}

void wt () {} 
template< typename Type , typename... Types >
void wt ( Type& arg , Types&...args ) {
	write < Type > ( arg ) ;
	wt ( args... ) ;
}
template <typename T>
void sp( T x ) {
    T _ = x < 0;
    if (_) putchar('-'), x *= -1;
    if (x > 9) sp(x / 10);
    putchar(x % 10 | '0');
}

void pf() {}
template <typename Type, typename... Types>
void pf(Type arg, int x, Types... args) {
    sp < Type > ( arg );
    x == 0 ? putchar(' ') : putchar('\n');
    pf(args...);
}
}
using namespace Fastio ;
