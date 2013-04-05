#include "udfReportPreview.h"
#include "wx/image.h"
#include "wx/imagpng.h"

udfReportPreview::udfReportPreview( wxWindow* parent, const wxArrayString& data )
: ReportPreview( parent )
, m_data(data)
{
	wxString text;
	int col = 0;
	for(; col < data.GetCount(); ++col)
	{
		text += data[col]; 
	}
	m_htmlReport->ReadCustomization(wxConfig::Get());
	m_htmlReport->AppendToPage(text);
	
}

void udfReportPreview::OnPrint( wxCommandEvent& event )
{
	// TODO: Implement OnPrint
}

void udfReportPreview::OnDiscard( wxCommandEvent& event )
{
	EndModal(wxID_CANCEL);
}
