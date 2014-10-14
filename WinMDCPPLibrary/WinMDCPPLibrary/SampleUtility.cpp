// SampleUtility.cpp
#include <regex>
#include "pch.h"
#include "SampleUtility.h"


using namespace WinMDCPPLibrary;
using namespace Platform;

SampleUtility::SampleUtility()
{
	Platform::Boolean SampleUtility::IsMailAddress( Platform::String^ email )
	{
		std::tr1::wregex rx(L"(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
		return std::tr1::regex_match<const wchar_t*>( email->Begin(), email->End(), rx );
	}
}
