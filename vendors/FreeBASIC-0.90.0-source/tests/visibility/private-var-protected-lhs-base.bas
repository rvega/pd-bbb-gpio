' TEST_MODE : COMPILE_ONLY_FAIL

type Parent
	as integer i
	private:
	static x as integer
end type

dim Parent.x as integer

type Child extends Parent
	declare sub test( )
end type

sub Child.test( )
	base.x = 123
end sub
