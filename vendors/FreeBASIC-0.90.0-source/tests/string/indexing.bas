#include "fbcu.bi"

namespace fbc_tests.string_.indexing

type UDT1
	fs	as  string * 31
	z	as zstring * 32
	w	as wstring * 32
end type

type UDT2
	x1a	as UDT1
	x1b	as UDT1
end type

dim shared as UDT2 globalx2
dim shared as  string * 31 globalfs
dim shared as zstring * 32 globalz
dim shared as wstring * 32 globalw

sub test cdecl( )
	static as UDT2 staticx2
	static as  string * 32 staticfs
	static as zstring * 32 staticz
	static as wstring * 32 staticw

	dim as UDT2 x2
	dim as  string * 32 fs
	dim as zstring * 32 z
	dim as wstring * 32 w

	dim as zstring ptr pz
	dim as wstring ptr pw
	dim as integer i0, i1, i2, i3
	dim as integer i = 2

	dim as uinteger hugewchar
	select case( sizeof( wstring ) )
	case 4
		hugewchar = &hA0000000u
	case 2
		hugewchar = &hA000u
	case else
		hugewchar = &hA0
	end select

	#macro testZstr( z, x2, zfield )
		z = !"abc\&hA0"
		pz = @z

		CU_ASSERT( z[0] = asc( "a" ) )
		CU_ASSERT( z[1] = asc( "b" ) )
		CU_ASSERT( z[i] = asc( "c" ) )
		CU_ASSERT( z[3] = &hA0 )
		CU_ASSERT( (*pz)[0] = asc( "a" ) )
		CU_ASSERT( (*pz)[1] = asc( "b" ) )
		CU_ASSERT( (*pz)[i] = asc( "c" ) )
		CU_ASSERT( (*pz)[3] = &hA0 )
		CU_ASSERT( pz[0] = asc( "a" ) )
		CU_ASSERT( pz[1] = asc( "b" ) )
		CU_ASSERT( pz[i] = asc( "c" ) )
		CU_ASSERT( pz[3] = &hA0 )

		i0 = z[0] : CU_ASSERT( i0 = asc( "a" ) )
		i1 = z[1] : CU_ASSERT( i1 = asc( "b" ) )
		i2 = z[i] : CU_ASSERT( i2 = asc( "c" ) )
		i3 = z[3] : CU_ASSERT( i3 = &hA0 )
		i0 = (*pz)[0] : CU_ASSERT( i0 = asc( "a" ) )
		i1 = (*pz)[1] : CU_ASSERT( i1 = asc( "b" ) )
		i2 = (*pz)[i] : CU_ASSERT( i2 = asc( "c" ) )
		i3 = (*pz)[3] : CU_ASSERT( i3 = &hA0 )
		i0 = pz[0] : CU_ASSERT( i0 = asc( "a" ) )
		i1 = pz[1] : CU_ASSERT( i1 = asc( "b" ) )
		i2 = pz[i] : CU_ASSERT( i2 = asc( "c" ) )
		i3 = pz[3] : CU_ASSERT( i3 = &hA0 )

		x2.x1a.zfield = !"abc\&hA0"
		CU_ASSERT( x2.x1a.zfield[0] = asc( "a" ) )
		CU_ASSERT( x2.x1a.zfield[1] = asc( "b" ) )
		CU_ASSERT( x2.x1a.zfield[i] = asc( "c" ) )
		CU_ASSERT( x2.x1a.zfield[3] = &hA0 )

		x2.x1b.zfield = !"abc\&hA0"
		CU_ASSERT( x2.x1b.zfield[0] = asc( "a" ) )
		CU_ASSERT( x2.x1b.zfield[1] = asc( "b" ) )
		CU_ASSERT( x2.x1b.zfield[i] = asc( "c" ) )
		CU_ASSERT( x2.x1b.zfield[3] = &hA0 )
	#endmacro

	#macro testWstr( w, x2, wfield )
		w = wstr( "abc" )
		w[3] = hugewchar
		w[4] = 0

		pw = @w

		CU_ASSERT( w[0] = asc( "a" ) )
		CU_ASSERT( w[1] = asc( "b" ) )
		CU_ASSERT( w[i] = asc( "c" ) )
		CU_ASSERT( w[3] = hugewchar )
		CU_ASSERT( (*pw)[0] = asc( "a" ) )
		CU_ASSERT( (*pw)[1] = asc( "b" ) )
		CU_ASSERT( (*pw)[i] = asc( "c" ) )
		CU_ASSERT( (*pw)[3] = hugewchar )
		CU_ASSERT( pw[0] = asc( "a" ) )
		CU_ASSERT( pw[1] = asc( "b" ) )
		CU_ASSERT( pw[i] = asc( "c" ) )
		CU_ASSERT( pw[3] = hugewchar )

		i0 = w[0] : CU_ASSERT( i0 = asc( "a" ) )
		i1 = w[1] : CU_ASSERT( i1 = asc( "b" ) )
		i2 = w[i] : CU_ASSERT( i2 = asc( "c" ) )
		i3 = w[3] : CU_ASSERT( i3 = hugewchar )
		i0 = (*pw)[0] : CU_ASSERT( i0 = asc( "a" ) )
		i1 = (*pw)[1] : CU_ASSERT( i1 = asc( "b" ) )
		i2 = (*pw)[i] : CU_ASSERT( i2 = asc( "c" ) )
		i3 = (*pw)[3] : CU_ASSERT( i3 = hugewchar )
		i0 = pw[0] : CU_ASSERT( i0 = asc( "a" ) )
		i1 = pw[1] : CU_ASSERT( i1 = asc( "b" ) )
		i2 = pw[i] : CU_ASSERT( i2 = asc( "c" ) )
		i3 = pw[3] : CU_ASSERT( i3 = hugewchar )

		x2.x1a.wfield = wstr( "abc" )
		x2.x1a.wfield[3] = hugewchar
		x2.x1a.wfield[4] = 0
		CU_ASSERT( x2.x1a.wfield[0] = asc( "a" ) )
		CU_ASSERT( x2.x1a.wfield[1] = asc( "b" ) )
		CU_ASSERT( x2.x1a.wfield[i] = asc( "c" ) )
		CU_ASSERT( x2.x1a.wfield[3] = hugewchar )

		x2.x1b.wfield = wstr( "abc" )
		x2.x1b.wfield[3] = hugewchar
		x2.x1b.wfield[4] = 0
		CU_ASSERT( x2.x1b.wfield[0] = asc( "a" ) )
		CU_ASSERT( x2.x1b.wfield[1] = asc( "b" ) )
		CU_ASSERT( x2.x1b.wfield[i] = asc( "c" ) )
		CU_ASSERT( x2.x1b.wfield[3] = hugewchar )
	#endmacro

	testZstr( z , x2, z  )
	testZstr( fs, x2, fs )
	testWstr( w , x2, w  )

	testZstr( staticz , staticx2, z  )
	testZstr( staticfs, staticx2, fs )
	testWstr( staticw , staticx2, w  )

	testZstr( globalz , globalx2, z  )
	testZstr( globalfs, globalx2, fs )
	testWstr( globalw , globalx2, w  )
end sub

private sub ctor( ) constructor
	fbcu.add_suite( "tests/string/indexing" )
	fbcu.add_test( "test", @test )
end sub

end namespace
