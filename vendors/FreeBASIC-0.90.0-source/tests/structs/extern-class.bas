# include "fbcu.bi"
#include "extern-class.bi"

namespace fbc_tests.structs.extern_class

constructor T1( byval i as integer )
	this.i = i
end constructor

constructor T2( )
	this.i = 321
end constructor

dim shared as T1 global1 = T1( 123 )
dim shared as T1 fixarray1(0 to 1) = { T1( 456 ), T1( 789 ) }

dim shared as T2 global2
dim shared as T2 fixarray2(0 to 1)

end namespace
