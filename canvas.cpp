#include "canvas.h"
#include <wx/graphics.h>


void ImageCanvas::SetImage(wxImage *image)
{
	m_bitmap = wxBitmap(*image);

	Render(true);
	Refresh();
}


void ImageCanvas::FitImageToWindow()
{
	if (!m_bitmap.IsOk())
	{
		return;
	}

	wxSize s = GetClientSize();

	double zx = ((double)(s.x))/m_bitmap.GetWidth();
	double zy = ((double)(s.y))/m_bitmap.GetHeight();

	m_zoom = zx < zy ? zx : zy;

}

void ImageCanvas::Render(bool WXUNUSED(force))
{

	wxMemoryDC dc(m_backBuffer);
	wxGraphicsContext *gc = wxGraphicsContext::Create(dc);

	dc.Clear();

	if (m_bitmap.IsOk())
	{
		FitImageToWindow();
		wxGraphicsBitmap gbm = gc->CreateBitmap(m_bitmap);
		int w = m_bitmap.GetWidth();
		int h = m_bitmap.GetHeight();
		gc->DrawBitmap(gbm, m_offX, m_offY, w * m_zoom, h * m_zoom);

		gc->SetPen(*wxRED_PEN);
		wxGraphicsPath path = gc->CreatePath();

		for (int i = 0; i <= m_grid.m_divX; i++)
		{
			path.MoveToPoint(m_offX + m_zoom * w * m_grid.m_x + m_zoom * w * m_grid.m_w * i / m_grid.m_divX, m_offY + m_zoom * h * m_grid.m_y);
			path.AddLineToPoint(m_offX + m_zoom * w * m_grid.m_x + m_zoom * w * m_grid.m_w * i / m_grid.m_divX, m_offY + m_zoom * h * m_grid.m_y + m_zoom * h * m_grid.m_h);
		}
		for (int i = 0; i <= m_grid.m_divY; i++)
		{
			path.MoveToPoint(m_offX + m_zoom * w * m_grid.m_x, m_offY + m_zoom * h * m_grid.m_y + m_zoom * h * m_grid.m_h * i /m_grid.m_divY);
			path.AddLineToPoint(m_offX + m_zoom * w * m_grid.m_x + m_zoom * w * m_grid.m_w , m_offY + m_zoom * h * m_grid.m_y + m_zoom * h * m_grid.m_h * i /m_grid.m_divY);
		}

		gc->StrokePath(path);

	}


	delete gc;

}


void ImageCanvas::WindowToGrid(int x, int y, double *xx, double *yy)
{
	if (!m_bitmap.IsOk())
	{
		*xx = *yy = 0.0;
		return;
	}

	*xx = x - m_offX;
	*yy = y - m_offY;

	*xx /= m_zoom * m_bitmap.GetWidth();
	*yy /= m_zoom * m_bitmap.GetHeight();

}
