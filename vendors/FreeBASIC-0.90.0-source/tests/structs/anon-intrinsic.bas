# include "fbcu.bi"

namespace fbc_tests.structs.anon_intrinsic

function testproc( ) as integer
	function = 123
end function

sub test cdecl( )
	scope
		dim as integer i = type( 1.5 )
		CU_ASSERT( i = cint( 1.5 ) )
	end scope

	scope
		dim as integer i = type<typeof( type<typeof( i )>( 1.5 ) )>( 3 )
		CU_ASSERT( i = 3 )
	end scope

	scope
		dim i as integer
		dim d as double
		dim f as single

		i = type<integer>( 123 )
		CU_ASSERT( i = 123 )

		i = type( 456 )
		CU_ASSERT( i = 456 )

		f = type<single>( 1.5 )
		CU_ASSERT( f = 1.5 )

		f = type( 1.5 )
		CU_ASSERT( f = 1.5 )

		d = type<double>( 1.5 )
		CU_ASSERT( d = 1.5 )

		d = type( 1.5 )
		CU_ASSERT( d = 1.5 )

		'' integer = type<integer>( double )
		i = type( 1.1 )
		CU_ASSERT( i = 1 )

		'' integer = type<double>( double )
		i = type<double>( 1.1 )
		CU_ASSERT( i = 1 )

		'' double = type<integer>( integer )
		d = type<integer>( 123 )
		CU_ASSERT( d = 123 )

		d = type<integer>( 1.1 )
		CU_ASSERT( d = 1 )
	end scope

	scope
		enum E
			A = 1
			B
		end enum

		dim i as E = A

		i = type<E>( B )
		CU_ASSERT( i = B )

		i = A
		i = type( B )
		CU_ASSERT( i = B )
	end scope

	scope
		dim p1 as sub( )
		p1 = type<sub( )>( 0 )
		p1 = type( 0 )

		dim p2 as function( ) as integer
		p2 = type<function( ) as integer>( @testproc )
		CU_ASSERT( p2( ) = 123 )
		p2 = type( @testproc )
		CU_ASSERT( p2( ) = 123 )
	end scope
end sub

private sub ctor( ) constructor
	fbcu.add_suite( "tests/structs/anon-intrinsic" )
	fbcu.add_test( "test", @test )
end sub

end namespace