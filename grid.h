#ifndef __GRID_H__
#define __GRID_H__


class Grid
{
	public:
		Grid();
		double m_x, m_w;
		double m_y, m_h;
		int m_divX;
		int m_divY;

		void MakeInside()
		{
			if (m_x < 0.0)
			{
				m_x = 0.0;
			}
			if (m_x > .9)
			{
				m_x = .9;
			}

			if (m_w < .05)
			{
				m_w = .05;
			}

			if (m_x + m_w > 1.0)
			{
				m_w = 1.0 - m_x;
			}

			if (m_y < 0.0)
			{
				m_y = 0.0;
			}
			if (m_y > .9)
			{
				m_y = .9;
			}

			if (m_h < .05)
			{
				m_h = .05;
			}

			if (m_h + m_y > 1.0)
			{
				m_h = 1.0 - m_y;
			}

		}

};

#endif //__GRID_H__
