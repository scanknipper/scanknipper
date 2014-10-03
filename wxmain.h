#ifndef _WX_MAIN_H_
#define _WX_MAIN_H_

#include "wx/wx.h"
#include "mainframe.h"
#include "grid.h"


// Define a new application type
class App: public wxApp
{
	public:
		App()
		{
			m_currentFile = -1;
		}
		bool OnInit();

		void OnIdle(wxIdleEvent &evt);


		void SetFilenames(wxArrayString const &files);
		void SaveSlices(Grid *grid);
		void NextImage();
		void PrevImage();
		void SetFileType(int fileType) { m_fileType = fileType; }

		void OnInitCmdLine(wxCmdLineParser &parser);

	private:
		wxArrayString m_fileNames;
		int m_currentFile;
		int m_fileType;
		wxImage m_image;
		DECLARE_EVENT_TABLE();
		MainFrame *m_mainFrame;
		static const char * s_fileTypes[];
};

DECLARE_APP(App);



#endif

