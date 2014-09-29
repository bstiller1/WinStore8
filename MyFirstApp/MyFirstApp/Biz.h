#pragma once
#include "pch.h"
#include <collection.h>
using namespace Windows::Foundation::Collections;
using namespace Platform::Collections;

namespace MyFirstApp
{
	[Windows::UI::Xaml::Data::Bindable]
	public ref class Person sealed
	{
	public:
		Person() {}
		Person( Platform::String^ name ) { FullName = name; }
		property Platform::String^ FullName;
	};
	[Windows::UI::Xaml::Data::Bindable]
	public ref class Biz sealed
	{
	
		private: 
		~Biz() {}
	public:
		Biz() {}

		IVector<Person^>^ GetPeople()
		{
			Vector<Person^>^ vec = ref new Vector<Person^>();
			vec->Append( ref new Person("Roberto Brunetti") );
			vec->Append( ref new Person("Paolo Pialorsi") );
			vec->Append( ref new Person("Marco Russo") );
			vec->Append( ref new Person("Luca Regnicoli") );
			vec->Append( ref new Person("Vanni Boncinelli") );
			vec->Append( ref new Person("Guido Zambarda") );
			vec->Append( ref new Person("Jessica Faustinelli") );
			vec->Append( ref new Person("Katia Egiziano") );
			return vec;
		};
	};
}