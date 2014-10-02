﻿//
// SearchPeople.xaml.h
// Declaration of the SearchPeople class.
//

#pragma once

#include "Common\LayoutAwarePage.h" // Required by generated header
#include "Common\BooleanToVisibilityConverter.h" // Required by generated header
#include "Common\BindableBase.h" // Required by Filter declaration
#include "Common\SuspensionManager.h" //Required for Activation
#include "SearchPeople.g.h"

namespace MyFirstApp
{
	/// <summary>
	/// This page displays search results when a global search is directed to this application.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class SearchPeople sealed
	{
	public:
		SearchPeople();

	protected:
		virtual void LoadState(Platform::Object^ navigationParameter,
			Windows::Foundation::Collections::IMap<Platform::String^, Platform::Object^>^ pageState) override;

	private:
		void Filter_Checked(Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Filter_SelectionChanged(Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e);
	};

	/// <summary>
	/// View model describing one of the filters available for viewing search results.
	/// </summary>
	[Windows::UI::Xaml::Data::Bindable]
	public ref class SearchPeopleFilter sealed : MyFirstApp::Common::BindableBase
	{
	private:
		Platform::String^ _name;
		int _count;
		bool _active;

	public:
		SearchPeopleFilter(Platform::String^ name, int count, bool active);

		property Platform::String^ Name
		{
			Platform::String^ get();
			void set(Platform::String^ value);
		};

		property int Count
		{
			int get();
			void set(int value);
		};

		property bool Active
		{
			bool get();
			void set(bool value);
		};

		property Platform::String^ Description
		{
			Platform::String^ get();
		};
	};
}
