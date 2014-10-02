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
		Person( Platform::String^ name, Platform::String^ photo )
		{
			FullName = name;
			Photo = photo;
		}
		property Platform::String^ FullName;
		property Platform::String^ Photo;
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
			vec->Append( ref new Person("Roberto Brunetti", "Photos/01.jpg") );
			vec->Append( ref new Person("Paolo Pialorsi", "Photos/02.jpg") );
			vec->Append( ref new Person("Marco Russo", "Photos/03.jpg") );
			vec->Append( ref new Person("Luca Regnicoli", "Photos/04.jpg") );
			vec->Append( ref new Person("Vanni Boncinelli", "Photos/05.jpg") );
			vec->Append( ref new Person("Guido Zambarda", "Photos/06.jpg") );
			vec->Append( ref new Person("Jessica Faustinelli", "Photos/07.jpg") );
			vec->Append( ref new Person("Katia Egiziano", "Photos/08.jpg") );
			return vec;
		}; 
		IVector<Person ^>^ GetPeople(Platform::String^ search)
		{
			Vector<Person^>^ vec = ref new Vector<Person^>();
			std::wstring _search = std::wstring( search->Data() );
			for each(Person^ p in GetPeople()){
				std::wstring name = std::wstring( p->FullName->Data());
				int pos = name.find(_search);
				if (pos> 0){
					vec->Append( p );
				} 
			}
			return vec;
		}; 
	};
}

	