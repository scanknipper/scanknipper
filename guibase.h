///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIBASE_H__
#define __GUIBASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/choice.h>
#include <wx/sizer.h>
#include "canvas.h"
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrameBase
///////////////////////////////////////////////////////////////////////////////
class MainFrameBase : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* m_menubar1;
		wxMenu* m_fileMenu;
		wxButton* m_saveAndNextButton;
		wxButton* m_skipAndNextButton;
		wxStaticLine* m_staticline1;
		wxButton* m_prevImage;
		wxStaticText* m_staticText31;
		wxSpinCtrl* m_rowsSpinCtrl;
		wxStaticText* m_staticText2;
		wxSpinCtrl* m_columnsSpinCtrl;
		wxStaticText* m_staticText3;
		wxChoice* m_saveFormatChoice;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOpenFile( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClose( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveAndNext( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSkipAndNext( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPrevious( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRows( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnColumns( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnFileType( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLeftDown( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnLeftUp( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnMotion( wxMouseEvent& event ) { event.Skip(); }
		
	
	public:
		ImageCanvas *m_canvas;
		
		MainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("ScanKnipper"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 606,461 ), long style = wxDEFAULT_FRAME_STYLE|wxMAXIMIZE|wxTAB_TRAVERSAL );
		
		~MainFrameBase();
	
};

#endif //__GUIBASE_H__
