namespace Int_io {
	using Int = __int128 ;
	std::istream& operator>> ( std::istream& in , Int& me ) {
		int64_t he ; in >> he ;
		me = he ;
		return in ;
	}
	std::ostream& operator<< ( std::ostream& out , Int me ) {
		while ( me ) {
			out << ( me % 10 ) ;
			me /= 10 ;
		}
		return out ;
	}
}
using namespace Int_io ;
