#include "ascii.bi"

#define macro2 macro1

#define macro3(i) lcase(wstr(i))

	dim as wstring * 32 s1, s2 
	
	s1 = macro1("test")
	s2 = macro2("test")

	assert( s1 = s2 )
	
	s1 = macro3( "12345" )
	s2 = macro4( "12345" )

	assert( s1 = s2 )	

