#pragma once
class Edge
{
public:
	Edge() : Edge(0,0,0.0) {};
	Edge(int v, int w, double weight);
	~Edge() noexcept;
	double weight() const noexcept { return _weight; }
	int either() const noexcept;
	int other(int v) const;

	bool operator<(const Edge& other) const;
	bool operator>(const Edge& other) const;
	bool operator==(const Edge& other) const;
	bool operator<=(const Edge& other) const { return *this < other || *this == other; }
	bool operator>=(const Edge& other) const { return *this > other || *this == other; }

private:
	int _v;
	int _w;
	double _weight;
};

