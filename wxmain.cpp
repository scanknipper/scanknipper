#include "wx/wx.h"
#include "wx/filename.h"
#include "wx/cmdline.h"
#include "wx/config.h"
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

	if (argc > 1)
	{
		wxArrayString files;
		for (int i = 1; i < argc; i++)
		{
			files.Add(argv[i]);
		}
		SetFilenames(files);
	}

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

	wxConfigBase *conf = wxConfig::Get();

	double gx = conf->ReadDouble(wxT("GridX"), 0.0);
	double gy = conf->ReadDouble(wxT("GridY"), 0.0);
	double gw = conf->ReadDouble(wxT("GridW"), m_image.GetWidth());
	double gh = conf->ReadDouble(wxT("GridH"), m_image.GetHeight());

	Grid &g = m_mainFrame->m_canvas->m_grid;
	g.m_x = gx / m_image.GetWidth();
	g.m_y = gy / m_image.GetHeight();
	g.m_w = gw / m_image.GetWidth();
	g.m_h = gh / m_image.GetHeight();


	g.MakeInside();
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

			img.SetOption("quality", 95);

			fn.SetName(rowName);

			img.SaveFile(fn.GetFullPath());
		}
	}
}

char const *App::s_fileTypes[] = { "jpg", "png" };


static const wxCmdLineEntryDesc cmdLineDesc[] =
{
{ wxCMD_LINE_PARAM, NULL, NULL, "input file", wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_MULTIPLE },
{ wxCMD_LINE_NONE }
};

void App::OnInitCmdLine(wxCmdLineParser &parser)
{
	// suppress wx's default cmdline options so it won't complain about unkown options if we pass files on the cmdline
	parser.SetDesc(cmdLineDesc);
}

