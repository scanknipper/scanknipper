#ifndef __CANVAS_H__
#define __CANVAS_H__

#include "wxcanvas.h"
#include "grid.h"


class ImageCanvas
	: public  Canvas
{
	public:
		ImageCanvas(wxWindow * parent)
			: Canvas(parent)
		{
			m_zoom = 1.0;
		};

		void SetImage(wxImage *image);

		virtual void Render(bool force = false);
		Grid m_grid;
		wxBitmap m_bitmap;

		void WindowToGrid(int x, int y, double *xx, double *yy);

		void FitImageToWindow();

	private:


		double m_zoom;
		double m_offX;
		double m_offY;


};

#endif //__CANVAS_H__
