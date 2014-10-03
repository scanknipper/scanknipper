#include "wx/wx.h"
#include "wx/filename.h"
#include "wxmain.h"

BEGIN_EVENT_TABLE(App, wxApp)
	EVT_IDLE(App::OnIdle)
END_EVENT_TABLE()



/*------------------------------------------------------------------
  Application object ( equivalent to main() )
------------------------------------------------------------------ */

IMPLEMENT_APP(App)

bool App::OnInit()
{
	m_fileType = 0;

	wxInitAllImageHandlers();

	m_mainFrame = new MainFrame(NULL);

	m_mainFrame->Show();


	return true;
}

void App::OnIdle(wxIdleEvent &idle)
{
    //
}



void App::SetFilenames(wxArrayString  const &names)
{
	m_currentFile = -1;
	m_fileNames = names;
	NextImage();
}

void App::NextImage()
{
	if (m_currentFile >= (int)(m_fileNames.GetCount()) - 1)
	{
		return;
	}

	m_currentFile++;

	m_image.LoadFile(m_fileNames[m_currentFile]);

	m_mainFrame->m_canvas->SetImage(&m_image);

	m_mainFrame->SetIsLastImage(m_currentFile  >= (int)(m_fileNames.GetCount()) - 1);
	m_mainFrame->SetIsFirstImage(!(m_currentFile > 0));

}


void App::PrevImage()
{
	m_currentFile -=2;

	if (m_currentFile < -1)
	{
		m_currentFile = -1;
	}
	NextImage();
}


void App::SaveSlices(Grid *grid)
{
	wxFileName fn(m_fileNames[m_currentFile]);

	int w = m_image.GetWidth();
	int h = m_image.GetHeight();

	wxString baseName = fn.GetName();

	fn.SetExt(s_fileTypes[m_fileType]);

	for (int i = 0; i < grid->m_divX; i++)
	{
		wxString columnName = baseName;
		if (grid->m_divX > 1)
		{
			columnName += wxString((char)('A' + i));
		}
		for (int j = 0; j < grid->m_divY; j++)
		{
			wxString rowName = columnName;
			if (grid->m_divY > 1)
			{
				rowName += wxString((char)('a' + j));
			}

			int xx = (int)(grid->m_x*w + grid->m_w*w*i/grid->m_divX);
			int yy = (int)(grid->m_y*h + grid->m_h*h*j/grid->m_divY);
			int ww = (int)(grid->m_w*w/grid->m_divX);
			int hh = (int)(grid->m_h*h/grid->m_divY);

			// 'fix' rounding errors
			if (xx + ww > w)
			{
				ww = w - xx;
			}
			if (yy + hh > h)
			{
				hh = h - yy;
			}

			wxImage img = m_image.GetSubImage(wxRect(xx,yy,ww,hh));


			fn.SetName(rowName);

			img.SaveFile(fn.GetFullPath());
		}
	}
}

char const *App::s_fileTypes[] = { "jpg", "png" };
