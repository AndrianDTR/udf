#include "udfreportbase.h"

#include "udfcommon.h"
#include "wx/xml/xml.h"

udfReportBase::udfReportBase()
{
}

udfReportBase::~udfReportBase()
{
}

void udfReportBase::Test()
{
	do
	{
		wxXmlDocument doc;

		if (!doc.Load(wxT("myfile.xml")))
			break;

		wxXmlNode *child = doc.GetRoot()->GetChildren();
		while (child)
		{
			if (child->GetName() == wxT("tag1"))
			{
				// process text enclosed by <tag1></tag1>
				wxString content = child->GetNodeContent();

				// process properties of <tag1>
				wxString propvalue1 = child->GetPropVal(wxT("prop1"), wxT("default-value"));
				wxString propvalue2 = child->GetPropVal(wxT("prop2"), wxT("default-value"));

			}
			else if (child->GetName() == wxT("tag2"))
			{
				// process tag2 ...
			}

			child = child->GetNext();
		}
	}while(0);
}
