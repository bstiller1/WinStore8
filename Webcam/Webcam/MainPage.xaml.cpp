//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace Webcam;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Media::Capture;
using namespace Windows::Storage;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Media::Imaging;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

MainPage::MainPage()
{
	InitializeComponent();
}

/// <summary>
/// Invoked when this page is about to be displayed in a Frame.
/// </summary>
/// <param name="e">Event data that describes how this page was reached.  The Parameter
/// property is typically used to configure the page.</param>
void MainPage::OnNavigatedTo(NavigationEventArgs^ e)
{
	(void) e;	// Unused parameter
}


void Webcam::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}


void Webcam::MainPage::TakePhoto_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	CameraCaptureUI^ dialog = ref new CameraCaptureUI();

	concurrency::create_task(
		dialog->CaptureFileAsync(CameraCaptureUIMode::Video)).then(
		[this] (StorageFile^ file)
	{
		if (nullptr != file)
		{
			concurrency::create_task(
				file->OpenAsync(FileAccessMode::Read)).then(
				[this] (Streams::IRandomAccessStream^ stream)
			{
				BitmapImage^ bitmapImage = ref new BitmapImage();
				bitmapImage->SetSource(stream);
				image->Source = bitmapImage;
			});
		}
	});
}
