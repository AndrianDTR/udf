#include <wx/datetime.h>

#include "udftimectrl.h"

// MyTimeChangeEvent
IMPLEMENT_DYNAMIC_CLASS(udfTimeChangeEvent, wxNotifyEvent)
DEFINE_EVENT_TYPE(udfEVT_TIMECHANGE)

udfTimeChangeEvent::udfTimeChangeEvent()
	: wxNotifyEvent()
{
}

udfTimeChangeEvent::udfTimeChangeEvent(wxEventType type, wxWindowID id, const wxString& value)
	: wxNotifyEvent(type, id)
{
	SetValue(value);
}


udfTimeChangeEvent::udfTimeChangeEvent(const udfTimeChangeEvent& event) 
	: wxNotifyEvent(event)
{
	val = event.val;
}

wxEvent *udfTimeChangeEvent::Clone()
{
	return new udfTimeChangeEvent(*this);
}

void udfTimeChangeEvent::SetValue(const wxString& value) 
{
	val = value;
}

wxString udfTimeChangeEvent::GetValue() const
{
	return val;
}

// MyTextCtrl
IMPLEMENT_DYNAMIC_CLASS(udfTimeTextCtrl, wxTextCtrl)

udfTimeTextCtrl::udfTimeTextCtrl()
	: wxTextCtrl()
{
}

udfTimeTextCtrl::udfTimeTextCtrl(udfTimeCtrl *timectrl, const wxString& value)
	: wxTextCtrl(timectrl->GetParent(), -1, value, wxDefaultPosition, wxDefaultSize)
{
	tc = timectrl;
	buffer = wxT("");
}

udfTimeTextCtrl::~udfTimeTextCtrl()
{

}

void udfTimeTextCtrl::Increment(IncrementType direction)
{
	/**
	 * Format 00:00:00 xM
	 *
	 *        01234567891
	 *                  0
	 */
	 
	if (pos > 8)
	{
		if (buffer.IsSameAs(wxT("AM"), FALSE) )
		{
			buffer = wxT("PM");
		}
		else
		{
			buffer = wxT("AM");
		}
	}
	else
	{
		long value;
		buffer.ToLong(&value);

		switch	(direction)
		{
			case POSITIVE:
				value++;
				break;

			case NEGATIVE:
				value--;
				break;
		}
		
		FixValue(&value);
	
		buffer = wxString::Format(wxT("%.2d"), (int) value);
	}
}

void udfTimeTextCtrl::ApplyIncrement(IncrementType type)
{
	UpdatePosition();
	SelectPart();
	UpdateBuffer();
	Increment(type);
	FlushBuffer();
	SelectPart();
}

void udfTimeTextCtrl::OnChar(wxKeyEvent& event)
{
	UpdatePosition();
	SelectPart();
	UpdateBuffer();
		
	int keycode = event.GetKeyCode();
	
	if (keycode >= 48 && keycode <= 57 && pos < 8)
	{
		char ch = keycode;
		wxString temp = buffer + (wchar_t) ch;

		long value;
		temp.Right(2).ToLong(&value);
		
		if (value < min || value > max)
		{
			buffer = wxString(wxT("0") ) + (wchar_t) ch;
		}
		else 
		{
			buffer = wxString::Format(wxT("%.2d"), (int) value);
		}
		FlushBuffer();
	}
	
	switch (keycode)
	{
		case WXK_TAB:
			FlushBuffer();
			
			if (!event.ShiftDown() )
			{
				pos += 3;
			}
			else
			{
				pos -= 3;
			}
			
			#ifndef __WXMAC__
			if (pos < 0 || pos > 11)
			{
				event.Skip();
			}
			#endif // __WXMAC__
			break;

		case WXK_LEFT:
			FlushBuffer();

			pos -= 3;
			if (pos < 0) 
			{
				pos = 0;
			}
			break;
			
		case WXK_RIGHT:
			FlushBuffer();

			pos += 3;
			if (pos > 11) 
			{
				pos = 11;
			}
			break;
						
		case WXK_UP:
			Increment(POSITIVE);
			FlushBuffer();
			break;
			
		case WXK_DOWN:
			Increment(NEGATIVE);
			FlushBuffer();
			break;
		
		case 65:
		case 97:
			if (pos > 8)
			{
				buffer = wxT("AM");
			}
			FlushBuffer();
			break;
			
		case 80:
		case 112:
			if (pos > 8)
			{
				buffer = wxT("PM");
			}
			FlushBuffer();
		 	break;
	}
	SelectPart();
}

void udfTimeTextCtrl::UpdatePosition()
{
	pos = GetInsertionPoint();
}

void udfTimeTextCtrl::SelectPart() 
{
	if (pos <= 2) 
	{
		min = 0;
		max = 12;
	}
	
	if (pos > 2 && pos <= 8)
	{
		min = 0;
		max = 59;
	}

	if (pos <= 2)
	{
		SetSelection(0, 2);
	}
	
	if (pos > 2 && pos <= 5)
	{
		SetSelection(3, 5);
	}
	
	if (pos > 5 && pos <= 8)
	{
		SetSelection(6, 8);
	}
	
	if (pos > 8) 
	{
		SetSelection(9, 11);
	}
}

void udfTimeTextCtrl::UpdateBuffer()
{
	buffer = GetStringSelection();
}


void udfTimeTextCtrl::FlushBuffer(bool clear)
{
	long start, end;
	GetSelection(&start, &end);
	Replace(start, end, buffer);
	
	// trigger a MyTimeChangeEvent
	udfTimeChangeEvent timechanged(udfEVT_TIMECHANGE, tc->GetId() );
	timechanged.SetEventObject(tc);
	timechanged.SetValue(GetValue() );
	GetEventHandler()->ProcessEvent(timechanged);
}

void udfTimeTextCtrl::FixValue(long *value)
{
	if (*value < min) 
	{
		*value = max;
	}
	
	if (*value > max)
	{
		*value = min;
	}
}

BEGIN_EVENT_TABLE(udfTimeTextCtrl, wxTextCtrl)
	EVT_CHAR(udfTimeTextCtrl::OnChar)
END_EVENT_TABLE()	

// MySpinButton 
IMPLEMENT_DYNAMIC_CLASS(udfTimeSpinButton, wxSpinButton)

udfTimeSpinButton::udfTimeSpinButton()
	: wxSpinButton()
{	
}

udfTimeSpinButton::udfTimeSpinButton(udfTimeCtrl *timectrl)
	: wxSpinButton(timectrl->GetParent(), -1, wxDefaultPosition, wxDefaultSize)
{
	tc = timectrl;
}

udfTimeSpinButton::~udfTimeSpinButton()
{

}

void udfTimeSpinButton::OnSpinUp(wxSpinEvent& event)
{
	tc->UpdateTextCtrl(POSITIVE);
}

void udfTimeSpinButton::OnSpinDown(wxSpinEvent& event)
{
	tc->UpdateTextCtrl(NEGATIVE);
}

BEGIN_EVENT_TABLE(udfTimeSpinButton, wxSpinButton)
	EVT_SPIN_UP(-1, udfTimeSpinButton::OnSpinUp)
	EVT_SPIN_DOWN(-1, udfTimeSpinButton::OnSpinDown)
END_EVENT_TABLE()

// MyTimeCtrl
IMPLEMENT_DYNAMIC_CLASS(udfTimeCtrl, wxControl)

udfTimeCtrl::udfTimeCtrl(wxWindow *parent, wxWindowID id, 
	const wxString& value, const wxPoint& pos, const wxSize& size)
	: wxControl(parent, id, pos, size)
{
	tc = new udfTimeTextCtrl(this, value);
	sb = new udfTimeSpinButton(this);
	
	tc->SetWindowStyle(wxTE_PROCESS_TAB);
	tc->SetMaxLength(11);
	
	wxSize bestsize = DoGetBestSize();
	DoMoveWindow(pos.x, pos.y, bestsize.x, bestsize.y);
	
	// prevent the time picker from intercepting events
	wxControl::Enable(FALSE);
	
	Show(TRUE);
}

udfTimeCtrl::~udfTimeCtrl()
{
	delete tc;
	delete sb;
}

bool udfTimeCtrl::Show(bool show)
{
	wxControl::Show(show);
	
	tc->Show(show);
	sb->Show(show);
	
	return TRUE;
}

bool udfTimeCtrl::Enable(bool enable)
{
	wxControl::Enable(enable);
	
	tc->Enable(enable);
	sb->Enable(enable);
	
	return TRUE;
}

wxSize udfTimeCtrl::DoGetBestSize() const
{
	wxSize textsize = tc->GetBestSize(), buttonsize = sb->GetBestSize();
	return wxSize(textsize.x - buttonsize.x + SPACING + 10, textsize.y);
}

void udfTimeCtrl::DoMoveWindow(int x, int y, int width, int height)
{
	wxControl::DoMoveWindow(x, y, width, height);
	
	wxSize buttonsize = sb->GetBestSize();
	int textwidth = width - (buttonsize.x + SPACING);
	
	tc->SetSize(x, y, textwidth, height);
	sb->SetSize(x + textwidth + SPACING, y, -1, height);
}

void udfTimeCtrl::UpdateTextCtrl(IncrementType direction)
{
	tc->SetFocus();
	tc->ApplyIncrement(direction);
}

wxString udfTimeCtrl::GetValue() const
{
	return tc->GetValue();
}

wxString udfTimeCtrl::GetCurrentTime()
{
	return wxDateTime::Now().FormatTime();
}
