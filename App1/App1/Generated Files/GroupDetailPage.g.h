﻿

#pragma once
//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------

namespace Windows {
    namespace UI {
        namespace Xaml {
            namespace Data {
                ref class CollectionViewSource;
            }
        }
    }
}
namespace Windows {
    namespace UI {
        namespace Xaml {
            namespace Controls {
                ref class GridView;
                ref class ListView;
                ref class Button;
                ref class TextBlock;
            }
        }
    }
}
namespace Windows {
    namespace UI {
        namespace Xaml {
            ref class VisualStateGroup;
            ref class VisualState;
        }
    }
}

namespace App1
{
    partial ref class GroupDetailPage : public ::App1::Common::LayoutAwarePage, 
        public ::Windows::UI::Xaml::Markup::IComponentConnector
    {
    public:
        void InitializeComponent();
        virtual void Connect(int connectionId, ::Platform::Object^ target);
    
    private:
        bool _contentLoaded;
    
        private: ::Windows::UI::Xaml::Data::CollectionViewSource^ itemsViewSource;
        private: ::Windows::UI::Xaml::Controls::GridView^ itemGridView;
        private: ::Windows::UI::Xaml::Controls::ListView^ itemListView;
        private: ::Windows::UI::Xaml::Controls::Button^ backButton;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ pageTitle;
        private: ::Windows::UI::Xaml::VisualStateGroup^ ApplicationViewStates;
        private: ::Windows::UI::Xaml::VisualState^ FullScreenLandscape;
        private: ::Windows::UI::Xaml::VisualState^ Filled;
        private: ::Windows::UI::Xaml::VisualState^ FullScreenPortrait;
        private: ::Windows::UI::Xaml::VisualState^ Snapped;
    };
}

