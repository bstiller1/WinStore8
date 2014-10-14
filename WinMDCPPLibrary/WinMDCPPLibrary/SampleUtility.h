#pragma once

namespace WinMDCPPLibrary
{
    public ref class SampleUtility sealed
    {
    public:
        SampleUtility();
		Platform::Boolean IsMailAddress( Platform::String^ email );
    };
}