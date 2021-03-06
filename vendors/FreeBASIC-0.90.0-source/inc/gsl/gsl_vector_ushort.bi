''
''
'' gsl_vector_ushort -- header translated with help of SWIG FB wrapper
''
'' NOTICE: This file is part of the FreeBASIC Compiler package and can't
''         be included in other distributions without authorization.
''
''
#ifndef __gsl_vector_ushort_bi__
#define __gsl_vector_ushort_bi__

#include once "gsl_types.bi"
#include once "gsl_errno.bi"
#include once "gsl_check_range.bi"
#include once "gsl_block_ushort.bi"

type gsl_vector_ushort
	size as integer
	stride as integer
	data as ushort ptr
	block as gsl_block_ushort ptr
	owner as integer
end type

type _gsl_vector_ushort_view
	vector as gsl_vector_ushort
end type

type gsl_vector_ushort_view as _gsl_vector_ushort_view

type _gsl_vector_ushort_const_view
	vector as gsl_vector_ushort
end type

type gsl_vector_ushort_const_view as _gsl_vector_ushort_const_view

extern "c"
declare function gsl_vector_ushort_alloc (byval n as integer) as gsl_vector_ushort ptr
declare function gsl_vector_ushort_calloc (byval n as integer) as gsl_vector_ushort ptr
declare function gsl_vector_ushort_alloc_from_block (byval b as gsl_block_ushort ptr, byval offset as integer, byval n as integer, byval stride as integer) as gsl_vector_ushort ptr
declare function gsl_vector_ushort_alloc_from_vector (byval v as gsl_vector_ushort ptr, byval offset as integer, byval n as integer, byval stride as integer) as gsl_vector_ushort ptr
declare sub gsl_vector_ushort_free (byval v as gsl_vector_ushort ptr)
declare function gsl_vector_ushort_view_array (byval v as ushort ptr, byval n as integer) as _gsl_vector_ushort_view
declare function gsl_vector_ushort_view_array_with_stride (byval base as ushort ptr, byval stride as integer, byval n as integer) as _gsl_vector_ushort_view
declare function gsl_vector_ushort_const_view_array (byval v as ushort ptr, byval n as integer) as _gsl_vector_ushort_const_view
declare function gsl_vector_ushort_const_view_array_with_stride (byval base as ushort ptr, byval stride as integer, byval n as integer) as _gsl_vector_ushort_const_view
declare function gsl_vector_ushort_subvector (byval v as gsl_vector_ushort ptr, byval i as integer, byval n as integer) as _gsl_vector_ushort_view
declare function gsl_vector_ushort_subvector_with_stride (byval v as gsl_vector_ushort ptr, byval i as integer, byval stride as integer, byval n as integer) as _gsl_vector_ushort_view
declare function gsl_vector_ushort_const_subvector (byval v as gsl_vector_ushort ptr, byval i as integer, byval n as integer) as _gsl_vector_ushort_const_view
declare function gsl_vector_ushort_const_subvector_with_stride (byval v as gsl_vector_ushort ptr, byval i as integer, byval stride as integer, byval n as integer) as _gsl_vector_ushort_const_view
declare function gsl_vector_ushort_get (byval v as gsl_vector_ushort ptr, byval i as integer) as ushort
declare sub gsl_vector_ushort_set (byval v as gsl_vector_ushort ptr, byval i as integer, byval x as ushort)
declare function gsl_vector_ushort_ptr (byval v as gsl_vector_ushort ptr, byval i as integer) as ushort ptr
declare function gsl_vector_ushort_const_ptr (byval v as gsl_vector_ushort ptr, byval i as integer) as ushort ptr
declare sub gsl_vector_ushort_set_zero (byval v as gsl_vector_ushort ptr)
declare sub gsl_vector_ushort_set_all (byval v as gsl_vector_ushort ptr, byval x as ushort)
declare function gsl_vector_ushort_set_basis (byval v as gsl_vector_ushort ptr, byval i as integer) as integer
declare function gsl_vector_ushort_fread (byval stream as FILE ptr, byval v as gsl_vector_ushort ptr) as integer
declare function gsl_vector_ushort_fwrite (byval stream as FILE ptr, byval v as gsl_vector_ushort ptr) as integer
declare function gsl_vector_ushort_fscanf (byval stream as FILE ptr, byval v as gsl_vector_ushort ptr) as integer
declare function gsl_vector_ushort_fprintf (byval stream as FILE ptr, byval v as gsl_vector_ushort ptr, byval format as zstring ptr) as integer
declare function gsl_vector_ushort_memcpy (byval dest as gsl_vector_ushort ptr, byval src as gsl_vector_ushort ptr) as integer
declare function gsl_vector_ushort_reverse (byval v as gsl_vector_ushort ptr) as integer
declare function gsl_vector_ushort_swap (byval v as gsl_vector_ushort ptr, byval w as gsl_vector_ushort ptr) as integer
declare function gsl_vector_ushort_swap_elements (byval v as gsl_vector_ushort ptr, byval i as integer, byval j as integer) as integer
declare function gsl_vector_ushort_max (byval v as gsl_vector_ushort ptr) as ushort
declare function gsl_vector_ushort_min (byval v as gsl_vector_ushort ptr) as ushort
declare sub gsl_vector_ushort_minmax (byval v as gsl_vector_ushort ptr, byval min_out as ushort ptr, byval max_out as ushort ptr)
declare function gsl_vector_ushort_max_index (byval v as gsl_vector_ushort ptr) as integer
declare function gsl_vector_ushort_min_index (byval v as gsl_vector_ushort ptr) as integer
declare sub gsl_vector_ushort_minmax_index (byval v as gsl_vector_ushort ptr, byval imin as integer ptr, byval imax as integer ptr)
declare function gsl_vector_ushort_add (byval a as gsl_vector_ushort ptr, byval b as gsl_vector_ushort ptr) as integer
declare function gsl_vector_ushort_sub (byval a as gsl_vector_ushort ptr, byval b as gsl_vector_ushort ptr) as integer
declare function gsl_vector_ushort_mul (byval a as gsl_vector_ushort ptr, byval b as gsl_vector_ushort ptr) as integer
declare function gsl_vector_ushort_div (byval a as gsl_vector_ushort ptr, byval b as gsl_vector_ushort ptr) as integer
declare function gsl_vector_ushort_scale (byval a as gsl_vector_ushort ptr, byval x as double) as integer
declare function gsl_vector_ushort_add_constant (byval a as gsl_vector_ushort ptr, byval x as double) as integer
declare function gsl_vector_ushort_isnull (byval v as gsl_vector_ushort ptr) as integer
end extern

#endif
