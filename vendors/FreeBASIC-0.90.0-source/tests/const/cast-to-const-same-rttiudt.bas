' TEST_MODE : COMPILE_ONLY_FAIL

type UDT extends object
	i as integer
end type

dim x as UDT
cast( const UDT, x ).i = 5
