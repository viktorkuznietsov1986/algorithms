#include "Rectangle.h"

std::vector<Rectangle::Line> Rectangle::buildLinesFromRectangle() const {
	std::vector<Line> lines;
	lines.push_back(Line(x, x, y, y + height));
	lines.push_back(Line(x + width, x + width, y, y + height));
	lines.push_back(Line(x, x + width, y, y));
	lines.push_back(Line(x, x + width, y + height, y + height));

	return lines;
}


bool Rectangle::intersects(const Rectangle& r) const {
	if (this == &r)
		return true;

	auto firstLines = buildLinesFromRectangle();
	auto secondLines = r.buildLinesFromRectangle();

	for (std::vector<Line>::const_iterator firstLine = firstLines.begin(); firstLine != firstLines.end(); ++firstLine) {
		for (std::vector<Line>::const_iterator secondLine = secondLines.begin(); secondLine != secondLines.end(); ++secondLine) {
			if (firstLine->intersects(*secondLine))
				return true;
		}
	}

	return false;
}
