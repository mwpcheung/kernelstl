#include "stlhelp.h"
#include <ntddk.h>
const unsigned int DefaultTAG = 'laux';
void  std::_String_base::_Xlen()
{	// report a length_error
}


void  std::_String_base::_Xran()
{	// report an out_of_range error
}


void std::_String_base::_Xinvarg()
{	// report an out_of_range error
}

void * __cdecl operator new(size_t sz)
{
	return ExAllocatePoolWithTag(NonPagedPool, sz, DefaultTAG);
}
void * __cdecl operator new[](size_t sz)
{
	return ExAllocatePoolWithTag(NonPagedPool, sz, DefaultTAG);
}

void __cdecl operator delete(void *ptr, size_t sz)
{
	UNREFERENCED_PARAMETER(sz);
	if (ptr){
		ExFreePoolWithTag(ptr, DefaultTAG);
	}
}
void __cdecl operator delete(void *ptr)
{
	if (ptr){
		ExFreePoolWithTag(ptr, DefaultTAG);
	}
}
void __cdecl operator delete[](void *ptr)
{
	if (ptr){
		ExFreePoolWithTag(ptr, DefaultTAG);
	}
}
void __cdecl operator delete[](void *ptr, size_t sz)
{
	UNREFERENCED_PARAMETER(sz);
	if (ptr){
		ExFreePoolWithTag(ptr, DefaultTAG);
	}
}
void* __cdecl operator new(size_t sz, void*p)
{
	UNREFERENCED_PARAMETER(sz);
	return p;
}
#if (_MSC_VER < 1600) 

errno_t __cdecl memcpy_s(
void * dst,
size_t sizeInBytes,
const void * src,
size_t count
)
{
	if (count == 0 || dst == 0 || src == 0)
	{
		/* nothing to do */
		return 0;
	}
	memcpy(dst, src, count);
	return 0;
}
errno_t __cdecl memmove_s(
	void * dst,
	size_t sizeInBytes,
	const void * src,
	size_t count
	)
{

	memmove(dst, src, count);	
	return 0;
}

#endif


