﻿//
// SearchPeople.xaml.cpp
// Implementation of the SearchPeople class.
//

#include "pch.h"
#include <collection.h>
#include "SearchPeople.xaml.h"

using namespace MyFirstApp;

using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Search Contract item template is documented at http://go.microsoft.com/fwlink/?LinkId=234240

SearchPeople::SearchPeople()
{
	InitializeComponent();
}

/// <summary>
/// Populates the page with content passed during navigation.  Any saved state is also
/// provided when recreating a page from a prior session.
/// </summary>
/// <param name="navigationParameter">The parameter value passed to
/// <see cref="Frame::Navigate(Type, Object)"/> when this page was initially requested.
/// </param>
/// <param name="pageState">A map of state preserved by this page during an earlier
/// session.  This will be null the first time a page is visited.</param>
void SearchPeople::LoadState(Object^ navigationParameter, IMap<String^, Object^>^ pageState)
{
	(void) pageState;	// Unused parameter

	// Unpack the two values passed in the parameter object: query text and previous Window content
	auto queryText = safe_cast<String^>(navigationParameter);

	// TODO: Application-specific searching logic.  The search process is responsible for
	//       creating a list of user-selectable result categories:
	//
	//       filterList->Append(ref new SearchPeopleFilter("<filter name>", <result count>), false);
	//
	//       Only the first filter, typically "All", should pass true as a third argument in
	//       order to start in an active state.  Results for the active filter are provided
	//       in Filter_SelectionChanged below.
	auto biz = ref new Biz();
	auto people = biz->GetPeople(queryText);
	DefaultViewModel->Insert("Results", people );

	auto filterList = ref new Vector<Object^>();
	filterList->Append(ref new SearchPeopleFilter("All", people->Size, true));

	// Communicate results through the view model
	DefaultViewModel->Insert("QueryText", "\u201c" + queryText + "\u201d");
	DefaultViewModel->Insert("Filters", filterList);
	DefaultViewModel->Insert("ShowFilters", filterList->Size > 1);
}

/// <summary>
/// Invoked when a filter is selected using the ComboBox in snapped view state.
/// </summary>
/// <param name="sender">The ComboBox instance.</param>
/// <param name="e">Event data describing how the selected filter was changed.</param>
//void SearchPeople::Filter_SelectionChanged(Object^ sender, SelectionChangedEventArgs^ e)
void SearchPeople::Filter_SelectionChanged(Object^ sender, SelectionChangedEventArgs^ e)
{
	(void) sender;	// Unused parameter

	// Determine what filter was selected
	auto selectedFilter = (e->AddedItems->Size == 0) ? nullptr :
		dynamic_cast<SearchPeopleFilter^>(e->AddedItems->GetAt(0));
	if (selectedFilter != nullptr)
	{
		// Mirror the results into the corresponding filter object to allow the
		// RadioButton representation used when not snapped to reflect the change
		selectedFilter->Active = true;

		// TODO: Respond to the change in active filter by calling DefaultViewModel->Insert("Results", <value>)
		//       where <value> is a collection of items with bindable Image, Title, Subtitle, and Description properties
		
		// Ensure results are found
		IVector<Object^>^ resultsCollection;
		if (this->DefaultViewModel->HasKey("Results") == true)
		{
			resultsCollection = dynamic_cast<IVector<Object^>^>(this->DefaultViewModel->Lookup("Results"));
			if (resultsCollection != nullptr && resultsCollection->Size != 0)
			{
				VisualStateManager::GoToState(this, "ResultsFound", true);
				return;
			}
		}
	}

	// Display informational text when there are no search results.
	VisualStateManager::GoToState(this, "NoResultsFound", true);
}

/// <summary>
/// Invoked when a filter is selected using a RadioButton when not snapped.
/// </summary>
/// <param name="sender">The selected RadioButton instance.</param>
/// <param name="e">Event data describing how the RadioButton was selected.</param>
void SearchPeople::Filter_Checked(Object^ sender, RoutedEventArgs^ e)
{
	(void) e;	// Unused parameter

	// Mirror the change into the CollectionViewSource used by the corresponding ComboBox
	// to ensure that the change is reflected when snapped
	if (filtersViewSource->View != nullptr)
	{
		auto filter = safe_cast<FrameworkElement^>(sender)->DataContext;
		filtersViewSource->View->MoveCurrentTo(filter);
	}
}

SearchPeopleFilter::SearchPeopleFilter(String^ name, int count, bool active): _count(0), _active(false)
{
	Name = name;
	Count = count;
	Active = active;
}

String^ SearchPeopleFilter::Name::get()
{
	return _name;
}

void SearchPeopleFilter::Name::set(String^ value)
{
	if (value == _name || (value != nullptr && value->Equals(_name)))
	{
		return;
	}

	_name = value;
	OnPropertyChanged("Name");
	OnPropertyChanged("Description");
}

int SearchPeopleFilter::Count::get()
{
	return _count;
}

void SearchPeopleFilter::Count::set(int value)
{
	if (value == _count)
	{
		return;
	}

	_count = value;
	OnPropertyChanged("Count");
	OnPropertyChanged("Description");
}

bool SearchPeopleFilter::Active::get()
{
	return _active;
}

void SearchPeopleFilter::Active::set(bool value)
{
	if (value == _active)
	{
		return;
	}
	_active = value; OnPropertyChanged("Active");
}

String^ SearchPeopleFilter::Description::get()
{
	return _name + " (" + _count.ToString() + ")";
}
