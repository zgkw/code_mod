//#pragma clang diagnostic push
//#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
//#pragma ide diagnostic ignored "hicpp-signed-bitwise"
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
# include  <bits/stdc++.h>
using  namespace  std ;

using ll = long long ;
namespace predefine {
const long long inf = 0x3f3f3f3f3f3f3f3f ;
using ll = long long ;
using pll = pair < ll , ll > ;
using pls = pair < ll , string > ;
using psl = pair < string , ll > ;
using pss = pair < string , string > ;
using Int = __int128 ;
# define  IOS  iostream::sync_with_stdio ( 0 ) ; cin.tie ( 0 ) ;

# define af1( i , b ) for ( ll i = 1 ; i <= b ; ++ i )
# define df1( i , b ) for ( ll i = b ; i >= 1 ; -- i )
# define af( i , a , b ) for ( ll i = a ; i <= b ; ++ i )
# define df( i , a , b ) for ( ll i = a ; i >= b ; -- i )
# define afc( i , a , b , c ) for ( ll i = a ; i <= b ; i += c )
# define dfc( i , a , b , c ) for ( ll i = a ; i >= b ; i -= c )
# define Dg( x ) cout << " ------- " <<  x << " ------- " << '\n'
# define Dgop Dg ( "Debug op" )
# define Dged Dg ( "Debug ed" )
# define pr( x ) cout << #x << " = " << x << '\n'
# define pn putchar ('\n') 
# define ps cout << "yes" 
# define lowbit( x ) ( x & ( - x ) ) 
# define Rd(...) \
	ll __VA_ARGS__ ; \
	rd ( __VA_ARGS__ )


template < typename X , typename Y >
auto maX ( X x , Y y ) { return ( x > y ) ? x : y ; } 
template < typename X , typename Y >
auto miN ( X x , Y y ) { return ( x < y ) ? x : y ; }

template <typename Type , typename ... Types > 
auto maX ( Type arg , Types... args ) { return maX ( arg , maX ( args... ) ) ; }  
template <typename Type , typename ... Types > 
auto miN ( Type arg , Types... args ) { return miN ( arg , miN ( args... ) ) ; }  

// # define endl '\n'
}
//-----  快读、快输  ---------------------------------------------------------------------------------------------------------
namespace Fastio {
using ll = long long ;
# define MAXSIZE (1 << 20)
# define isdigit(x) (x >= '0' && x <= '9')

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
//-----  快读、快输  ---------------------------------------------------------------------------------------------------------

using namespace predefine ;
using namespace Fastio ;

//-----  常量定义  ---------------------------------------------------------------------------------------------------------

const ll maxn = 1e5 + 10 ;

const ll mod = 998244353 ;

//-----  常量定义  ---------------------------------------------------------------------------------------------------------


//-----  结构体  ---------------------------------------------------------------------------------------------------------

// struct node
// {	
// 	ll x , y , t ;
	
// 	// bool operator <( const node &a )const
// 	// {
// 	// 	return x < a.x ;
// 	// }
// };

//-----  结构体  ---------------------------------------------------------------------------------------------------------


//-----  排序  ---------------------------------------------------------------------------------------------------------

//bool cmp1 ( const ll &a , const ll &b )
//{
//	return hr [ a ] < hr [ b ] ;
//}

//-----  排序  ---------------------------------------------------------------------------------------------------------


//-----  链式前向星  ---------------------------------------------------------------------------------------------------------

// ll st [ 2 * maxn ] , to  [ 2 * maxn ] , nt  [ 2 * maxn ]   ;/*, w [ 2 * maxn ]*/

// ll add_cnt ;

// void add ( ll a , ll b /*, ll ow*/ ) 
// {
// 	to [ ++ add_cnt ] = b ;

// 	/* w [ add_cnt ] = ow ;*/

// 	nt [ add_cnt ] = st [ a ] ;

// 	st [ a ] = add_cnt ;
// }

// ll sum [ maxn ] ;

// unordered_map < string , ll > st ;

// string to  [ 2 * maxn ] ;

// ll nt  [ 2 * maxn ]  ;/*, ow [ 2 * maxn ] */

// ll cnt ;

// void add ( string a , string b /*, ll w*/ ) 
// {
// 	to [ ++ cnt ] = b ;

// 	/* ow [ cnt ] = w ;*/

// 	nt [ cnt ] = st [ a ] ;

// 	st [ a ] = cnt ;

// }

//-----  链式前向星  ---------------------------------------------------------------------------------------------------------


//-----  并查集  ---------------------------------------------------------------------------------------------------------

// ll fa [ maxn ] , em [ maxn ] , son [ maxn ] ; /**/

// ll find ( ll _a )
// {
// 	if ( fa [ _a ] == _a ) return _a ;

// 	/* ll tfa = find ( fa [ _a ] ) ;

// 	v [ _a ] += v [ fa [ _a ] ] ;

// 	fa [ _a ] = tfa ; */

// 	return fa [ _a ] = find ( fa [ _a ] ) ;
// }

//-----  并查集  ---------------------------------------------------------------------------------------------------------


//-----  质数筛  ---------------------------------------------------------------------------------------------------------

// ll ans [ maxn ] ;

// pll pos [ maxn ] ;

// ll p [ maxn ] ;

// bool p_c [ maxn ] ;

// ll p_cnt ;

// unordered_map < ll , ll > Hashmap ;

// ll hash_cnt ;

// void p_f ()
// {
// 	af ( i , 2 , maxn )
// 	{
// 		if ( ! p_c [ i ] )
// 		{
// 			p [ ++ p_cnt ] = i ;

// 			// Hashmap[ i ] = true ;
// 		}
// 		for ( int b = 1 ; b <= p_cnt && i * p [ b ] <= maxn ; ++ b )
// 		{
// 			p_c [ i * p [ b ] ] = 1 ;
			
// 			pos [ i * p [ b ] ] = { i , p [ b ] } ;

// 			if ( i % p [ b ] == 0 ) break ;
// 		}
// 	}
// }

//-----  质数筛  ---------------------------------------------------------------------------------------------------------


//-----  快速幂  ---------------------------------------------------------------------------------------------------------

ll Q_power ( ll a , ll b , ll mod )
{
	a = a % mod ;

	ll ans = 1 ;

	for ( ; b ; b >>= 1 )
	{
		if ( b & 1 ) ans = ( a * ans ) % mod ; 	// a * ans 可能会爆

		a = ( a * a ) % mod ; 					// 同理
	}

	return ans ;
}

//-----  快速幂  ---------------------------------------------------------------------------------------------------------

//-----  矩阵快速幂  ---------------------------------------------------------------------------------------------------------

//ll mq_n , mq_k ;
//
//class MAT_POWER
//{
//public :
//	static const ll maxmp = 200 ;
//	static const ll mod = 1e9 + 7 ;
//
//	ll mp [ maxmp ] [ maxmp ] ;
//
//	MAT_POWER (){
//		memset ( mp , 0 , sizeof mp ) ;
//	}
//	inline void clear_1(){
//		memset ( mp , 0 , sizeof mp ) ;
//		af ( i , 1 , mq_n )
//			mp [ i ] [ i ] = 1 ;
//	}
//
//	MAT_POWER operator *( const MAT_POWER &x )
//	{
//		MAT_POWER z ;
//
//		af ( k , 1 , mq_n )
//		af ( i , 1 , mq_n )
//		af ( j , 1 , mq_n )
//		z.mp[ i ] [ j ] = ( z.mp [ i ] [ j ] + x.mp [ k ] [ j ] * mp [ i ] [ k ] % mod ) % mod ;
//
//		return z ;
//	}
//}mp, ans;
//
// void mQ_power ( ll n )
// {
// 	mq_n = 3 , mq_k = n - 3 ;

// 	mp.mp [ 1 ] [ 1 ] = 1 , mp.mp [ 1 ] [ 2 ] = 1 , mp.mp [ 1 ] [ 3 ] = 0 ;
// 	mp.mp [ 2 ] [ 1 ] = 0 , mp.mp [ 2 ] [ 2 ] = 0 , mp.mp [ 2 ] [ 3 ] = 1 ;
// 	mp.mp [ 3 ] [ 1 ] = 1 , mp.mp [ 3 ] [ 2 ] = 0 , mp.mp [ 3 ] [ 3 ] = 0 ;

// 	ans.clear_1 () ;

// 	do{
// 		if ( mq_k & 1 ) ans = ans * mp ;

// 		mp = mp * mp ; mq_k >>= 1 ;
// 	}while ( mq_k ) ;
// }

//-----  矩阵快速幂  ---------------------------------------------------------------------------------------------------------


//-----  前n项和 && 乘法逆元  ---------------------------------------------------------------------------------------------------------

//-----  前n项和  ---------------------------------------------------------------------------------------------------------

// const ll inv2 = 500000004 , inv6 = 166666668 ; // 除法逆元 mod = 19940417
//
// inline ll sum1 ( ll _a )
// {
// 	_a = _a % mod ;
// 	return  _a * ( _a + 1 ) % mod * inv2 % mod ;
// }

inline ll sum1 ( ll _a )
{
	return ( _a * ( _a + 1 ) ) >> 1 ;
}

//-----  前n项和  ---------------------------------------------------------------------------------------------------------

//-----  前n项平方和  ---------------------------------------------------------------------------------------------------------

//
// inline ll sum2 ( ll _b )
// {
// 	_b = _b % mod ;
// 	return _b * ( _b + 1 ) % mod * ( 2 * _b + 1 ) % mod * inv6 % mod ;
// }

inline ll sum2 ( ll _b )
{
	return _b * ( _b + 1 ) * ( 2 * _b + 1 ) / 6  ;
}

//-----  前n项平方和  ---------------------------------------------------------------------------------------------------------

//-----  逆元  ---------------------------------------------------------------------------------------------------------

//-----  拓展欧几里得算法 要求 a 与 b 互质  ---------------------------------------------------------------------------------------------------------

//void exgcd ( ll a , ll b , ll& x , ll& y )  // 注意实际上的x与y的变量类型
//{
//	if ( b == 0 )
//	{
//		x = 1, y = 0;
//		return;
//	}
//	exgcd ( b , a % b , y , x ) ;
//	y -= a / b * x ;
//}

//-----  拓展欧几里得算法 要求 a 与 b 互质  ---------------------------------------------------------------------------------------------------------

//-----  快速幂 逆元  ---------------------------------------------------------------------------------------------------------
	//
ll Q_pow ( ll a , ll b = mod , ll p = mod ) // a 对 b (一个素数） 的 逆元（p为答案限制的mod）
{
	ll ans = 1 ;

	b = b - 2 ;

	a = ( a % p + p ) % p ;

	for ( ; b ; b >>= 1 )
	{
		if ( b & 1 ) ans = ( a * ans ) % p ; 	// a * ans 可能会爆

		a = ( a * a ) % p ; 					// 同理
	}
	return ans ;
}

//-----  o(n)逆元  ---------------------------------------------------------------------------------------------------------

//ll inv [ maxn ] ;
//
//void inv_f ( ll n , ll p )								// 用于求大量逆元
//{
//	inv[ 1 ] = 1;
//
//	for ( int i = 2 ; i <= n ; ++ i )
//		inv [ i ] = ( ll )( p - p / i ) * inv [ p % i ] % p ;
//}

//-----  o(n)逆元  ---------------------------------------------------------------------------------------------------------

//-----  乘法逆元  ---------------------------------------------------------------------------------------------------------

//-----  前n项和 && 乘法逆元  ---------------------------------------------------------------------------------------------------------

//-----  __in128 输出  ---------------------------------------------------------------------------------------------------------

//inline void print(__int128 x)
//{
//	if(x<0){
//		putchar('-');
//		x=-x;
//	}
//	if(x>9) print(x/10);
//	putchar(x%10+'0');
//}

//-----  __int128 输出  ---------------------------------------------------------------------------------------------------------

//-----  求解欧拉函数  ---------------------------------------------------------------------------------------------------------

//int euler_phi(int n) {
//  int ans = n;
//  for (int i = 2; i * i <= n; i++)
//    if (n % i == 0) {
//      ans = ans / i * (i - 1);
//      while (n % i == 0) n /= i;
//    }
//  if (n > 1) ans = ans / n * (n - 1);
//  return ans;
//}

//-----  求解欧拉函数  ---------------------------------------------------------------------------------------------------------

//-----  gcd  ---------------------------------------------------------------------------------------------------------

// ll gcd( ll a , ll b )
// {
// 	if ( a < b ) swap ( a , b ) ;
// 	while ( a % b != 0 )
// 	{
// 		ll t_a = a ;

// 		a = b ;

// 		b = t_a % b ;
// 	}
// 	return b ;
// }

//-----  gcd  ---------------------------------------------------------------------------------------------------------


//-----  类  ---------------------------------------------------------------------------------------------------------

//----- 分数   ---------------------------------------------------------------------------------------------------------

// class frac
// {
// public:
// 	ll head , tail ;

// 	frac( ll _head , ll _tail ) : head( _head ) , tail ( _tail ){};

	// frac operator + ( const frac& ot )
	// {
	// 	frac res( 0 , 0 ) ;

	// 	res.tail = tail * ot.tail ;

	// 	res.head = head * ot.tail + ot.head * tail ;

	// 	ll g = gcd ( res.tail , res.head ) ;

	// 	res.head = res.head / g ;

// 		res.tail = res.tail / g ;

//		cout << "ip:" << ip << '\n' ;

		// ip += res.head / res.tail ;

//		cout << "ip:" << ip << '\n' ;

// 		res.head = res.head % res.tail ;

// 		return res ;
// 	}
// }

//----- 分数   ---------------------------------------------------------------------------------------------------------

//-----  线段树  ---------------------------------------------------------------------------------------------------------

// template <typename T>
// class SegtreeLazyRangeAdd {
// 	vector<T> tree , lazy ;
// 	vector<T> *arr ;
// 	ll n , root , n4 , end ;

// 	void maintain ( ll cl , ll cr , ll p ){
// 		ll cm = cl + ( ( cr - cl ) >> 1 ) ;
// 		if ( cl != cr && lazy [ p ] ) {
// 			lazy [ p << 1 ] += lazy [ p ] ;
// 			lazy [ p << 1 | 1 ] += lazy [ p ] ;
// 			tree [ p << 1 ] += lazy [ p ] * ( cm - cl + 1 ) ;
// 			tree [ p << 1 | 1 ] += lazy [ p ] * ( cr - cm ) ;
// 			lazy [ p ] = 0 ;
// 		}
// 	}
// 	T range_sum ( ll l , ll r , ll cl , ll cr , ll p )
// 	{
// 		if ( l <= cl && r >= cr ) return tree [ p ] ;
// 		ll m = cl + ( ( cr - cl ) >> 1 ) ;
// 		T sum = 0 ;
// 		maintain ( cl , cr , p ) ;
// 		if ( l <= m ) sum += range_sum ( l , r , cl , m , p << 1 ) ;
// 		if ( r > m ) sum += range_sum ( l , r , m + 1 , cr , p << 1 | 1 ) ;
// 		return sum ;
// 	}
// 	void range_add ( ll l , ll r , T val , ll cl , ll cr , ll p ) {
// 		if ( l <= cl && r >= cr ) {
// 			lazy [ p ] += val ;
// 			tree [ p ] += ( cr - cl + 1 ) * val ;
// 			return ;
// 		}
// 		ll m = cl + ( ( cr - cl ) >> 1 ) ;
// 		maintain ( cl , cr , p ) ;
// 		if ( l <= m ) range_add ( l , r , val , cl , m , p << 1 ) ;
// 		if ( r > m ) range_add ( l , r , val , m + 1 , cr , p << 1 | 1 ) ;
// 		tree [ p ] = tree [ p << 1 ] + tree [ p << 1 | 1 ] ;
// 	}
// 	void build ( ll s , ll t , ll p ) { 
// 		if ( s == t ) {
// 			tree [ p ] = ( *arr )[ s ] ;
// 			return ;
// 		}
// 		ll m = s + ( ( t - s ) >> 1 ) ;
// 		build ( s , m , p << 1 ) ;
// 		build ( m + 1 , t , p << 1 | 1 ) ;
// 		tree [ p ] = tree [ p << 1 ] + tree [ p << 1 | 1 ] ;
// 	}
// public : 
// 	explicit SegtreeLazyRangeAdd < T > ( vector < T > v ) {
// 		n = v.size () ;
// 		n4 = n * 4 ;
// 		tree = vector < T > ( n4 , 0 ) ;
// 		lazy = vector < T > ( n4 , 0 ) ;
// 		arr = &v ;
// 		end = n - 1 ;
// 		root = 1 ;
// 		build ( 0 , end , 1 ) ;
// 		arr = nullptr ;
// 	}	
// 	void show ( ll p , ll depth = 0 ) {
// 		if ( p > n4 || tree [ p ] == 0 ) return ;
// 		show ( p << 1 , depth + 1 ) ;
// 		for ( ll i = 0 ; i < depth ; ++ i ) putchar ( '\t' ) ;
// 		printf ( "%d:%d\n", tree [ p ] , lazy [ p ] ) ;
// 		show ( p << 1 | 1 , depth + 1 ) ;
// 	}

// 	T range_sum ( int l , int r ) { return range_sum ( l - 1 , r - 1 , 0 , end , root ) ; } 

// 	void range_add ( ll l , ll r , ll val ) { range_add ( l - 1 , r - 1 , val , 0 , end , root ) ; } 
// };

// template <typename T>
// class SegtreeLazyRangeAdd_and_Mul {
// 	vector<T> tree , lazy_add , lazy_mul ;
// 	vector<T> *arr ;
// 	ll n , root , n4 , end ;

// 	void maintain ( ll cl , ll cr , ll p ){
// 		ll cm = cl + ( ( cr - cl ) >> 1 ) ;
// 		if ( cl != cr && lazy_mul [ p ] != 1 ) {
// 			lazy_add [ p << 1 ] *= lazy_mul [ p ] ;
// 			lazy_add [ p << 1 | 1 ] *= lazy_mul [ p ] ;
// 			lazy_mul [ p << 1 ] *= lazy_mul [ p ] ;
// 			lazy_mul [ p << 1 | 1 ] *= lazy_mul [ p ] ;			
// 			tree [ p << 1 ] *= lazy_mul [ p ] ;
// 			tree [ p << 1 | 1 ] *= lazy_mul [ p ] ;
// 			lazy_mul [ p ] = 1 ;
// 		}
// 		if ( cl != cr && lazy_add [ p ] ) {
// 			lazy_add [ p << 1 ] += lazy_add [ p ] ;
// 			lazy_add [ p << 1 | 1 ] += lazy_add [ p ] ;
// 			tree [ p << 1 ] += lazy_add [ p ] * ( cm - cl + 1 ) ;
// 			tree [ p << 1 | 1 ] += lazy_add [ p ] * ( cr - cm ) ;
// 			lazy_add [ p ] = 0 ;
// 		}
// 	}
// 	T range_sum ( ll l , ll r , ll cl , ll cr , ll p )
// 	{
// 		if ( l <= cl && r >= cr ) return tree [ p ] ;
// 		ll m = cl + ( ( cr - cl ) >> 1 ) ;
// 		T sum = 0 ;
// 		maintain ( cl , cr , p ) ;
// 		if ( l <= m ) sum += range_sum ( l , r , cl , m , p << 1 ) ;
// 		if ( r > m ) sum += range_sum ( l , r , m + 1 , cr , p << 1 | 1 ) ;
// 		return sum ;
// 	}
// 	void range_add ( ll l , ll r , T val , ll cl , ll cr , ll p ) {
// 		if ( l <= cl && r >= cr ) {
// 			lazy_add [ p ] += val ;
// 			tree [ p ] += ( cr - cl + 1 ) * val ;
// 			return ;
// 		}
// 		ll m = cl + ( ( cr - cl ) >> 1 ) ;
// 		maintain ( cl , cr , p ) ;
// 		if ( l <= m ) range_add ( l , r , val , cl , m , p << 1 ) ;
// 		if ( r > m ) range_add ( l , r , val , m + 1 , cr , p << 1 | 1 ) ;
// 		tree [ p ] = tree [ p << 1 ] + tree [ p << 1 | 1 ] ;
// 	}
// 	void range_mul ( ll l , ll r , T val , ll cl , ll cr , ll p ) {
// 		if ( l <= cl && r >= cr ) {
// 			lazy_add [ p ] *= val ;
// 			lazy_mul [ p ] *= val ;
// 			tree [ p ] = tree [ p ] * val ;
// 			return ;
// 		}
// 		ll m = cl + ( ( cr - cl ) >> 1 ) ;
// 		maintain ( cl , cr , p ) ;
// 		if ( l <= m ) range_mul ( l , r , val , cl , m , p << 1 ) ;
// 		if ( r > m ) range_mul ( l , r , val , m + 1 , cr , p << 1 | 1 ) ;
// 		tree [ p ] = tree [ p << 1 ] + tree [ p << 1 | 1 ] ;
// 	}
// 	void build ( ll s , ll t , ll p ) { 
// 		if ( s == t ) {
// 			tree [ p ] = ( *arr )[ s ] ;
// 			return ;
// 		}
// 		ll m = s + ( ( t - s ) >> 1 ) ;
// 		build ( s , m , p << 1 ) ;
// 		build ( m + 1 , t , p << 1 | 1 ) ;
// 		tree [ p ] = tree [ p << 1 ] + tree [ p << 1 | 1 ] ;
// 	}
// public : 
// 	explicit SegtreeLazyRangeAdd_and_Mul < T > ( vector < T > v ) {
// 		n = v.size () ;
// 		n4 = n * 4 ;
// 		tree = vector < T > ( n4 , 0 ) ;
// 		lazy_add = vector < T > ( n4 , 0 ) ;
// 		lazy_mul = vector < T > ( n4 , 1 ) ;
// 		arr = &v ;
// 		end = n - 1 ;
// 		root = 1 ;
// 		build ( 0 , end , 1 ) ;
// 		arr = nullptr ;
// 	}	
// 	void show ( ll p , ll depth = 0 ) {
// 		if ( p > n4 || tree [ p ] == 0 ) return ;
// 		show ( p << 1 , depth + 1 ) ;
// 		for ( ll i = 0 ; i < depth ; ++ i ) putchar ( '\t' ) ;
// 		printf ( "%d:%d\n", tree [ p ] , lazy_add [ p ] ) ;
// 		show ( p << 1 | 1 , depth + 1 ) ;
// 	}

// 	T range_sum ( int l , int r ) { return range_sum ( l - 1 , r - 1 , 0 , end , root ) ; } 

// 	void range_add ( ll l , ll r , ll val ) { range_add ( l - 1 , r - 1 , val , 0 , end , root ) ; } 

// 	void range_mul ( ll l , ll r , ll val ) { range_mul ( l - 1 , r - 1 , vla ,  0 , end , root ) ; }
// };

// template <typename T>
// class SegtreeLazyRangeSet {
// 	vector<T> tree , lazy ;
// 	vector<T> *arr ;
// 	ll n , root , n4 , end ;

// 	void maintain ( ll cl , ll cr , ll p ){
// 		ll cm = cl + ( ( cr - cl ) >> 1 ) ;
// 		if ( cl != cr && lazy [ p ] ) {
// 			lazy [ p << 1 ] = lazy [ p ] ;
// 			lazy [ p << 1 | 1 ] = lazy [ p ] ;
// 			tree [ p << 1 ] = lazy [ p ] * ( cm - cl + 1 ) ;
// 			tree [ p << 1 | 1 ] = lazy [ p ] * ( cr - cm ) ;
// 			lazy [ p ] = 0 ;
// 		}
// 	}
// 	T range_sum ( ll l , ll r , ll cl , ll cr , ll p )
// 	{
// 		if ( l <= cl && r >= cr ) return tree [ p ] ;
// 		ll m = cl + ( ( cr - cl ) >> 1 ) ;
// 		T sum = 0 ;
// 		maintain ( cl , cr , p ) ;
// 		if ( l <= m ) sum += range_sum ( l , r , cl , m , p << 1 ) ;
// 		if ( r > m ) sum += range_sum ( l , r , m + 1 , cr , p << 1 | 1 ) ;
// 		return sum ;
// 	}
// 	void range_set ( ll l , ll r , T val , ll cl , ll cr , ll p ) {
// 		if ( l <= cl && r >= cr ) {
// 			lazy [ p ] = val ;
// 			tree [ p ] = ( cr - cl + 1 ) * val ;
// 			return ;
// 		}
// 		ll m = cl + ( ( cr - cl ) >> 1 ) ;
// 		maintain ( cl , cr , p ) ;
// 		if ( l <= m ) range_set ( l , r , val , cl , m , p << 1 ) ;
// 		if ( r > m ) range_set ( l , r , val , m + 1 , cr , p << 1 | 1 ) ;
// 		tree [ p ] = tree [ p << 1 ] + tree [ p << 1 | 1 ] ;
// 	}
// 	void build ( ll s , ll t , ll p ) {
// 		if ( s == t ) {
// 			tree [ p ] = ( *arr )[ s ] ;
// 			return ;
// 		}
// 		ll m = s + ( ( t - s ) >> 1 ) ;
// 		build ( s , m , p << 1 ) ;
// 		build ( m + 1 , t , p << 1 | 1 ) ;
// 		tree [ p ] = tree [ p << 1 ] + tree [ p << 1 | 1 ] ;
// 	}
// public : 
// 	explicit SegtreeLazyRangeAdd < T > ( vector < T > v ) {
// 		n = v.size () ;
// 		n4 = n * 4 ;
// 		tree = vector < T > ( n4 , 0 ) ;
// 		lazy = vector < T > ( n4 , 0 ) ;
// 		arr = &v ;
// 		end = n - 1 ;
// 		root = 1 ;
// 		build ( 0 , end , 1 ) ;
// 		arr = nullptr ;
// 	}	
// 	void show ( ll p , ll depth = 0 ) {
// 		if ( p > n4 || tree [ p ] == 0 ) return ;
// 		show ( p << 1 , depth + 1 ) ;
// 		for ( ll i = 0 ; i < depth ; ++ i ) putchar ( '\t' ) ;
// 		printf ( "%d:%d\n", tree [ p ] , lazy [ p ] ) ;
// 		show ( p << 1 | 1 , depth + 1 ) ;
// 	}

// 	T range_sum ( ll l , ll r ) { return range_sum ( l , r , 0 , end , root ) ; } 

// 	void range_set ( ll l , ll r , ll val ) { range_set ( l , r , val , 0 , end , root ) ; } 
// };

//-----  线段树  ---------------------------------------------------------------------------------------------------------

//-----  类  ---------------------------------------------------------------------------------------------------------

//-----  常用定义  ---------------------------------------------------------------------------------------------------------


ll hr [ maxn ] , hr1 [ maxn ] , g1 [ maxn ] , g2 [ maxn ] ;

// ll   , hr3 [ maxn ] , hr4 [ maxn ] ;

// ll sum [ maxn ] ;

// priority_queue < ll > q ;

// priority_queue < pll , vector < pll > , greater < pll > > q1 ;

// bitset < 300 > q [ 300 ] ;

// unordered_map < char , ll > hp;

// ll dx [ 4 ] = { -1 , 0 , 1 , 0 } ;

// ll dy [ 4 ] = { 0 , 1 , 0 , -1 } ;

// queue < ll > q ;

// node hr [ maxn ] ;

// char mp [ 20 ] [ 20 ] ;

// ll dp [ maxn ] ;

// ll ans ;

// char mp [ 200 ] [ 200 ] ;

ll dp [ maxn ] ;

ll ti [ maxn ] , f [ maxn ] ;

bool cmp ( const ll & a , const ll & b ) {
	// if ( ti [ a ] == ti [ b ] ) return a < b ;
	/* else */ return hr1 [ a ] < hr1 [ b ] ;
}

ll tree [ maxn * 4 ] ;
ll vis1 [ maxn ] , vis2 [ maxn ] ;

void add ( ll u , ll n , ll k ) { while ( u <= n ) tree [ u ] += k  , u += lowbit ( u ) ;  }
ll query ( ll r ) {
	ll sum2 = 0 ;
	while ( r ) sum2 += tree [ r ] , r -= lowbit ( r ) ;
	return sum2 ;
}

struct node {
	ll x , y ;
	static ll len ( node a , node b ) {
		return ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) ;
	}
};

void solve ()
{
	node p , a , b , o ; 
	o = { 0 , 0 } ;
	rd ( p.x , p.y , a.x , a.y , b.x , b.y ) ;
	ll pa = node::len ( a , p ) ;
	ll pb = node::len ( b , p ) ;
	ll ao = node::len ( a , o ) ;
	ll bo = node::len ( b , o ) ;
	double w ;
	if ( maX ( pa , ao ) <= miN ( pb , bo ) ) 
	{
		w = sqrt ( maX ( pa , ao ) ) ;
	} 
	else if ( maX ( pb , bo ) <= miN ( pa , ao ) ) {
		w = sqrt ( maX ( pb , bo ) ) ;
	}
	else {
		ll ab = node::len ( a , b ) ;
		ab = maX ( miN ( pa , pb ) * 4 , ab , miN ( ao , bo ) * 4 ) ;
		w = sqrt ( ab ) / 2 ;
	}
	cout << fixed << setprecision ( 10 ) << w << endl ;
}

// void solve2 () ;

int  main ()
{
	// p_f () ;

	// IOS

	ll _ ;

	//    _ = 1 ;

	rd ( _ ) ;

	while ( _ -- )
	{
		solve () ;
	}


//	system ( "pause" ) ;


	// fwrite(Fastio::pbuf, 1, Fastio::pp - Fastio::pbuf, stdout) ;

	return 0 ;
}
/*

//-----  数据  ---------------------------------------------------------------------------------------------------------
3260745630
266012571


// ----------

//-----  数据  ---------------------------------------------------------------------------------------------------------

//-----  板子  ---------------------------------------------------------------------------------------------------------

//-----    ---------------------------------------------------------------------------------------------------------

//-----  板子  ---------------------------------------------------------------------------------------------------------


----------
*/
