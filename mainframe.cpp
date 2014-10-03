#include "wx/config.h"
#include "wx/dnd.h"
#include "mainframe.h"
#include "wxmain.h"


class MyDropTarget
	: public wxFileDropTarget
{
	public:
		virtual bool OnDropFiles (wxCoord x, wxCoord y, const wxArrayString &filenames)
		{
			wxGetApp().SetFilenames(filenames);
			return true;
		}
};


MainFrame::MainFrame( wxWindow* parent )
:
MainFrameBase( parent )
{
	m_dragGrid = DRAG_NONE;
	wxConfigBase *conf = wxConfig::Get();
	int fileType = conf->ReadLong(wxT("SaveFileType"), 0);
	int rows = conf->ReadLong(wxT("Rows"), 1);
	int columns = conf->ReadLong(wxT("Columns"), 8);

	if (rows < 1)
	{
		rows = 1;
	}

	if (rows > 26)
	{
		rows = 26;
	}

	if (columns < 1)
	{
		columns = 1;
	}

	if (columns > 26)
	{
		columns = 26;
	}

	m_rowsSpinCtrl->SetValue(rows);
	m_columnsSpinCtrl->SetValue(columns);

	m_canvas->m_grid.m_divX = columns;
	m_canvas->m_grid.m_divY = rows;

	m_saveFormatChoice->SetSelection(fileType);
	wxGetApp().SetFileType(fileType);


	double gx = conf->ReadDouble(wxT("GridX"), 0.0);
	double gy = conf->ReadDouble(wxT("GridY"), 0.0);
	double gw = conf->ReadDouble(wxT("GridW"), 1.0);
	double gh = conf->ReadDouble(wxT("GridH"), 1.0);

	m_canvas->m_grid.m_x = gx;
	m_canvas->m_grid.m_y = gy;
	m_canvas->m_grid.m_w = gw;
	m_canvas->m_grid.m_h = gh;

	SetDropTarget(new MyDropTarget);

}

void MainFrame::OnOpenFile( wxCommandEvent& event )
{
	wxFileDialog openDialog(this, wxT("Open images(s)"), wxEmptyString, wxEmptyString, wxT("Image Files|*.jpg;*.jpeg;*.JPG;*.JPEG;*.png;*.PNG;*.BMP;*.bmp|All Files|*.*"), wxFD_OPEN | wxFD_MULTIPLE);

	if (openDialog.ShowModal() == wxID_CANCEL)
	{
		return;
	}

	wxArrayString files;

	openDialog.GetFilenames(files);

	wxGetApp().SetFilenames(files);


}

void MainFrame::OnSave( wxCommandEvent& event )
{
	wxGetApp().SaveSlices(&(m_canvas->m_grid));
}

void MainFrame::OnClose( wxCommandEvent& event )
{
	Close();
}


void MainFrame::OnLeftDown( wxMouseEvent& event )
{
	m_canvas->CaptureMouse();

	double x,y;

	m_canvas->WindowToGrid(event.GetX(), event.GetY(), &x, &y);
	m_dragGrid = SelectClosest(m_canvas->m_grid, x, y);;
	OnMotion(event);
}

void MainFrame::OnLeftUp( wxMouseEvent& event )
{
	m_dragGrid = DRAG_NONE;
	m_canvas->ReleaseMouse();

}

void MainFrame::OnMotion( wxMouseEvent& event )
{
	double x,y;

	m_canvas->WindowToGrid(event.GetX(), event.GetY(),&x,&y);

	Grid &g = m_canvas->m_grid;

	if (m_dragGrid == DRAG_TOPLEFT)
	{
		g.m_x = x;
		g.m_y = y;

	}

	if (m_dragGrid == DRAG_TOPRIGHT)
	{
		g.m_w = x - g.m_x;
		g.m_y = y;
	}

	if (m_dragGrid == DRAG_BOTTOMRIGHT)
	{
		g.m_w = x - g.m_x;
		g.m_h = y - g.m_y;
	}

	if (m_dragGrid == DRAG_BOTTOMLEFT)
	{
		g.m_x = x;
		g.m_h = y - g.m_y;
	}

	if (m_dragGrid != DRAG_NONE)
	{
		g.MakeInside();
		m_canvas->Render(true);
		m_canvas->Refresh();
	}
}


MainFrame::GRIDDRAG MainFrame::SelectClosest(Grid const &g, double x, double y)
{
	double distXLeft = fabs(g.m_x - x);
	double distYTop = fabs(g.m_y -y);
	double distXRight = fabs(g.m_x + g.m_w - x);
	double distYBottom = fabs(g.m_y + g.m_h - y);

	if (distXLeft < distXRight)
	{
		if (distYTop < distYBottom)
		{
			return DRAG_TOPLEFT;
		}
		else
		{
			return DRAG_BOTTOMLEFT;
		}
	}
	else
	{
		if (distYTop < distYBottom)
		{
			return DRAG_TOPRIGHT;
		}
		else
		{
			return DRAG_BOTTOMRIGHT;
		}
	}

	return DRAG_NONE;
}


void MainFrame::SetIsLastImage(bool li)
{
	m_saveAndNextButton->SetLabel(li ? wxT("Save") : wxT("Save, Next Image"));
	m_skipAndNextButton->Enable(!li);
}

void MainFrame::SetIsFirstImage(bool fi)
{
	m_prevImage->Enable(!fi);
}

void MainFrame::OnSaveAndNext( wxCommandEvent& event )
{
	wxConfigBase *conf = wxConfig::Get();

	conf->Write(wxT("GridX"), m_canvas->m_grid.m_x * m_canvas->m_bitmap.GetWidth());
	conf->Write(wxT("GridY"), m_canvas->m_grid.m_y * m_canvas->m_bitmap.GetHeight());
	conf->Write(wxT("GridW"), m_canvas->m_grid.m_w * m_canvas->m_bitmap.GetWidth());
	conf->Write(wxT("GridH"), m_canvas->m_grid.m_h * m_canvas->m_bitmap.GetHeight());


	wxGetApp().SaveSlices(&(m_canvas->m_grid));
	wxGetApp().NextImage();
}

void MainFrame::OnSkipAndNext( wxCommandEvent& event )
{
	wxConfigBase *conf = wxConfig::Get();

	conf->Write(wxT("GridX"), m_canvas->m_grid.m_x * m_canvas->m_bitmap.GetWidth());
	conf->Write(wxT("GridY"), m_canvas->m_grid.m_y * m_canvas->m_bitmap.GetHeight());
	conf->Write(wxT("GridW"), m_canvas->m_grid.m_w * m_canvas->m_bitmap.GetWidth());
	conf->Write(wxT("GridH"), m_canvas->m_grid.m_h * m_canvas->m_bitmap.GetHeight());

	wxGetApp().NextImage();
}

void MainFrame::OnPrevious( wxCommandEvent& event )
{
	wxGetApp().PrevImage();
}


void MainFrame::OnRows( wxSpinEvent& event )
{
	m_canvas->m_grid.m_divY = m_rowsSpinCtrl->GetValue();
	wxConfig::Get()->Write(wxT("Rows"), (long)m_rowsSpinCtrl->GetValue());
	m_canvas->Render(true);
	m_canvas->Refresh(true);
}

void MainFrame::OnColumns( wxSpinEvent& event )
{
	m_canvas->m_grid.m_divX = m_columnsSpinCtrl->GetValue();
	wxConfig::Get()->Write(wxT("Columns"), (long)m_columnsSpinCtrl->GetValue());
	m_canvas->Render(true);
	m_canvas->Refresh(true);
}

void MainFrame::OnFileType( wxCommandEvent& event )
{
	wxConfig::Get()->Write(wxT("SaveFileType"), (long)m_saveFormatChoice->GetSelection());
	wxGetApp().SetFileType(m_saveFormatChoice->GetSelection());

}

