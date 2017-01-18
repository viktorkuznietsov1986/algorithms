#pragma once

#include <vector>

class Rectangle
{
	struct Line {
		int xmin;
		int xmax;
		int ymin;
		int ymax;

		Line(int x1, int x2, int y1, int y2) : xmin(x1), xmax(x2), ymin(y1), ymax(y2) {}

		bool isHorizontal() const { return ymin == ymax; }
		bool isVertical() const { return xmin == xmax; }

		bool intersects(const Line& l) const {
			if (this == &l)
				return true;

			if ((isHorizontal() && l.isHorizontal()) || (isVertical() && l.isVertical()))
				return false;

			if (isHorizontal()) {
				if (l.xmin >= xmin && l.xmin <= xmax)
					return true;
			}
			else {
				if (l.ymin >= ymin && l.ymin <= ymax)
					return true;
			}

			return false;
		}
	};

public:
	Rectangle(int xcoord, int ycoord, int w, int h) : x(xcoord), y(ycoord), width(w), height(h) {}
	~Rectangle() { }

	bool intersects(const Rectangle& r) const;

private:
	std::vector<Line> buildLinesFromRectangle() const;

private:
	int x;
	int y;
	int height;
	int width;
};

