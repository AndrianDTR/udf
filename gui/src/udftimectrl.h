/**
 * This widget is a time-picker control that is built by combining
 * a customised text control with a customised spin button.
 * 
 * @version $Id: MyTimeCtrl.h, v 0.01 2003/03/24 14:40:05 Eddy Young $
 */

#ifndef __udfTimeCtrl_h__
#define __udfTimeCtrl_h__

#include <wx/wx.h>
#include <wx/spinbutt.h>

#define SPACING 2

enum IncrementType
{
	POSITIVE = 1,
	NEGATIVE = 2
};

class udfTimeCtrl;

/**
 * This custom time change event triggers whenever the value in the text
 * control changes.
 */
class udfTimeChangeEvent : public wxNotifyEvent
{
public:
	/**
	 * Default constructor
	 */
	udfTimeChangeEvent();
	
	/**
	 * Normal constructor
	 */
	udfTimeChangeEvent(wxEventType type, wxWindowID id = -1, const wxString& value = wxT("") );
	
	/**
	 * To cater for Clone() function
	 * 
	 * @see @ref #Clone()
	 */
	udfTimeChangeEvent(const udfTimeChangeEvent& event);
	
	/**
	 * Set value
	 */
	void SetValue(const wxString& value);
	
	/**
	 * Get value
	 */
	wxString GetValue() const;
	
	/**
	 * Clone 
	 */
	virtual wxEvent *Clone();
	
private:
	wxString val;

	DECLARE_DYNAMIC_CLASS(udfTimeChangeEvent)
};

typedef void (wxEvtHandler::*udfEventFunction) (udfTimeChangeEvent&);

BEGIN_DECLARE_EVENT_TYPES()
	DECLARE_EVENT_TYPE(udfEVT_TIMECHANGE, 1)
END_DECLARE_EVENT_TYPES()

#define EVT_TIMECHANGE(id, func)  \
	DECLARE_EVENT_TABLE_ENTRY(udfEVT_TIMECHANGE, id, -1, (wxObjectEventFunction) (wxEventFunction) (udfEventFunction) & func, (wxObject *) NULL ),
	
/**
 * This control is the text part of the time-picker.
 */
class udfTimeTextCtrl : public wxTextCtrl
{
public:
	/**
	 * Default constructor
	 */
	udfTimeTextCtrl();
	
	/**
	 * Normal constructor
	 */
	udfTimeTextCtrl(udfTimeCtrl *timectrl, const wxString& value = wxT("") );
	  
	/**
	 * Destructor
	 */
	~udfTimeTextCtrl();
	
	/**
	 * This function is called from the spin control to 
	 * increment the value
	 *
	 * @param IncrementType type
	 */
	void ApplyIncrement(IncrementType type);
	
private:
	udfTimeCtrl *tc;
	wxString buffer;
	int pos, min, max;

	/**
	 * This event handler is called when a key is pressed in the text ctrl
	 *
	 * @param event
	 */
	void OnChar(wxKeyEvent& event);

	/**
	 * This funciton updates the caret position
	 */
	void UpdatePosition();
	
	/**
	 * This function sets the selection to the appropriate time part
	 */
	void SelectPart();
	
	/**
	 * This function updates the buffer
	 */
	void UpdateBuffer();
	
	/**
	 * This function updates the current time part (hour, minute, second or
	 * am/pm) based on the type of the change
	 *
	 * @param type
	 */
	void Increment(IncrementType type);

	/**
	 * Flush the buffer
	 */
	void FlushBuffer(bool clear = TRUE);
	 
	/**
	 * This function checks whether the valuefalls within the limit
	 *
	 * @param value
	 */
	void FixValue(long *value);
	
	
	DECLARE_DYNAMIC_CLASS(udfTimeTextCtrl)
	DECLARE_EVENT_TABLE()
};

/**
 * This control is the spin button of the time picker.
 */
class udfTimeSpinButton : public wxSpinButton
{
public:
 	/** 
 	 * Default constructor
 	 */
 	udfTimeSpinButton();
 	 
 	/**
 	 * Normal constructor
 	 */
 	udfTimeSpinButton(udfTimeCtrl *timectrl);
 	
 	/**
 	 * Destructor
 	 */
 	~udfTimeSpinButton();
 	
 	/**
 	 * These functions are called when the spin button is pressed
 	 *
 	 * @param wxSpinEvent&
 	 */
 	void OnSpinUp(wxSpinEvent& event);
 	
 	/**
 	 * @see @ref #OnSpinUp(wxSpinEvent& event)
 	 */
 	void OnSpinDown(wxSpinEvent& event);
 	
 private:
 	udfTimeCtrl *tc;	

	DECLARE_DYNAMIC_CLASS(udfTimeSpinButton)
	DECLARE_EVENT_TABLE()
};

class udfTimeCtrl : public wxControl
{
public:
	/**
	 * Normal constructor
	 */
	udfTimeCtrl(wxWindow *parent = NULL, wxWindowID id = -1,
		const wxString& value = wxT(""), const wxPoint& pos = wxDefaultPosition, 
		const wxSize& size = wxDefaultSize);
		
	/**
	 * Destructor
	 */
	~udfTimeCtrl();
	
	/**
	 * This function triggers an update on the text control part, indicating
	 * an increment or a decrement with the parameter @p type.
	 *
	 * @param type
	 */
	void UpdateTextCtrl(IncrementType type);
	
	/**
	 * This function returns the value of the time control.
	 *
	 * @return Time, const wxString&
	 */
	wxString GetValue() const;
	
	/**
	 * Static function to get current time as expected by the control
	 */
	static wxString GetCurrentTime();
		
	/**
	 * This function shows or hides the control.
	 *
	 * @param show (TRUE to show; FALSE to hide)
	 * @return bool
	 */
	virtual bool Show(bool show = TRUE);

	/**
	 * This function enables or disables the control
	 *
	 * @param true or false
	 */
	virtual bool Enable(bool enable = TRUE);
	
protected:
	/**
	 * This function overrides the wxControl::DoMoveWindow() function so
	 * that the two parts of the control are synchronised.
	 *
	 * @see wxControl::DoMoveWindow(int x, int y, int width, int height)
	 */
	void DoMoveWindow(int x, int y, int width, int height);
	
	/**
	 * This function overrides the wxControl::DoGetBestSize() function so
	 * that the correct "best size" of the combined controls is returned.
	 *
	 * @see wxControl::DoGetBestSize()
	 */
	wxSize DoGetBestSize() const;
	
private:
	udfTimeTextCtrl *tc;
	udfTimeSpinButton *sb;

	DECLARE_DYNAMIC_CLASS(udfTimeCtrl)
};

#endif // __udfTimeCtrl_h__
