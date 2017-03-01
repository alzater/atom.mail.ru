// Problem 2
// print points of ellipse visible on canvas

#include <iostream>
#include <cmath>
#include <vector>

struct Point
{
	Point(double _x, double _y)
		: x(_x)
		, y(_y)
	{}

	double x;
	double y;
};

class Ellipse
{
public:
	Ellipse(double x, double y, double a, double b)
		: _x(x)
		, _y(y)
	{
		double ratio;
		if ( a > b )
		{
			ratio = (b*b) / (a*a);
			_b = b;
			_isVertical = false;
		}
		else
		{
			ratio = (a*a) / (b*b);
			_b = a;
			_isVertical = true;
		}
			
		if (ratio < 1)
			_eccentricity = std::sqrt(1 - ratio);
		else
			_eccentricity = 1;
	}
	
	void setQPoints(int q)
	{
		_qPoints = q;
	}
	
	std::vector<Point> getPoints() const
	{
		const double deltaAngle = 2*M_PI / _qPoints;
		const double maxAngle = 2*M_PI - deltaAngle/2;
		
		std::vector<Point> res;
		for (double angle = 0; angle < maxAngle; angle += deltaAngle)
		{
			const double squareEccentricity = _eccentricity * _eccentricity;
			const double cosAngle = std::cos(angle);
			const double squareCosAngle = cosAngle * cosAngle;
			const double radius = _b / std::sqrt(1 -  squareEccentricity * squareCosAngle);
			
			double relativeX = radius * cosAngle;
			double relativeY = radius * std::sin(angle);
			if (_isVertical)
				std::swap(relativeX, relativeY);
			
			res.emplace_back(relativeX + _x, relativeY + _y);
		}
		
		return res;
	}
	

private:	
	double _x;
	double _y;
	double _b;
	double _eccentricity;
	bool _isVertical;
	double _qPoints = 4;
};

class Canvas
{
public:
	Canvas(double w, double h, const Ellipse& ellipse)
		: _w(w)
		, _h(h)
		, _ellipse(ellipse)
	{}
	
	std::vector<Point> getPoints() const
	{
		const auto allPoints = _ellipse.getPoints();
		
		std::vector<Point> visiblePoints;
		for (const auto& point : allPoints)
		{
			if ( isPointVisible(point) )
				visiblePoints.emplace_back(point);
		}
		
		return visiblePoints;
	}
	
private:
	bool isPointVisible(const Point& point) const
	{
		const double e = 1e-10;
		if ( point.x <= _w + e && point.x >= 0 - e &&
			 point.y <= _h + e && point.y >= 0 - e
		)
			return true;
		else
			return false;
	}

private:
	double _w;
	double _h;
	const Ellipse& _ellipse;
};

void setPoint(long x, long y)
{
	std::cout << x << ' ' << y << std::endl;
}

int main() {
	int width, height, x0, y0, rX, rY;
	std::cin >> width >> height >> x0 >> y0 >> rX >> rY;
	const int Q_POINTS = 16;
	
	Ellipse ellipse(x0, y0, rX, rY);
	ellipse.setQPoints(Q_POINTS);
	Canvas canvas(width, height, ellipse);
	
	const auto points = canvas.getPoints();
	for (const auto& point : points)
		setPoint(std::lround(point.x), std::lround(point.y));
	
	return 0;
}
