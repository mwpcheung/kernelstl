#pragma once
#include "stlhelp.h"

extern "C"{
#include <wdm.h>
}

#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif
class kstring :public std::wstring
{
public:
	kstring()
	{

	}
	kstring(const wchar_t* ptr)
	{
		append(ptr);
	}
	kstring(const wchar_t*ptr, uint32_t size)
	{
		append(ptr, size);
	}
	kstring(const std::wstring&str)
	{
		append(str.data(), str.length());
	}
	PUNICODE_STRING getUnicodeStringPtr() {
		m_ustr.Buffer = (wchar_t*)this->data();
		m_ustr.Length = this->size() * sizeof(wchar_t);
		m_ustr.MaximumLength = this->size() * sizeof(wchar_t);
		return &m_ustr;
	}
	kstring(const UNICODE_STRING&ustr)
	{
		if (ustr.Buffer){
			unsigned short len = min(ustr.Length, ustr.MaximumLength) / 2;
			append(ustr.Buffer, len);
		}
	}
	kstring(const PUNICODE_STRING pustr)
	{
		if (pustr && pustr->Buffer){
			unsigned short len = min(pustr->Length, pustr->MaximumLength) / 2;
			append(pustr->Buffer, len);
		}
	}
	void operator=(const PUNICODE_STRING pustr)
	{
		if (pustr && pustr->Buffer) {
			clear();
			unsigned short len = min(pustr->Length, pustr->MaximumLength) / 2;
			append(pustr->Buffer, len);
		}
	}
	void operator=(const UNICODE_STRING& ustr)
	{
		if (ustr.Buffer){
			clear();
			unsigned short len = min(ustr.Length, ustr.MaximumLength) / 2;
			append(ustr.Buffer, len);
		}
	}
	void operator=(const wchar_t* kw)
	{
		clear();
		append(kw);
	}

	bool operator==(const kstring&kstr)
	{
		return this->compare(kstr);
	}
	bool operator==(const UNICODE_STRING&ustr)
	{
		kstring kstr(ustr);
		return this->compare(kstr);
	}
	~kstring()
	{

	}
protected:
	UNICODE_STRING m_ustr;
};


