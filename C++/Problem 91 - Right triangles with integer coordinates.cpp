#include <iostream>

struct Point
{
	Point(int x, int y) : x(x), y(y) {}
	int x;
	int y;
	bool operator<(const Point& other)
	{
		return this->y < other.y || (this->y==other.y && this->x < other.x);
	}
	void move_to_next(int bound)
	{
		if(++y>bound)
		{
			y=0;
			x++;
		}
	}
	Point get_prev(int bound)
	{
		Point p(x-1, y);
		if(p.x<0)
		{
			p.x=bound;
			p.y--;	
		}
		return p;
	}
};


bool is_right_angled(const Point& p0, const Point& p1, const Point& p2)
{
	auto sqr_len=[](auto p1, auto p2) -> int { return (p1.y-p2.y)*(p1.y-p2.y)+(p1.x-p2.x)*(p1.x-p2.x); };
	int a=sqr_len(p0, p1);
	int b=sqr_len(p1, p2);
	int c=sqr_len(p2, p0);
	return a+b==c || b+c==a || c+a==b;
}

int main()
{
	int bound=50;
	int sum=0;
	Point p0(0,0);
	Point p2(bound, bound);
	while(p0<p2)
	{
		Point p1=p2.get_prev(bound);
		while(p0<p1)
		{
			if(is_right_angled(p0, p1, p2))
			{
				sum++;
			}
			p1=p1.get_prev(bound);
		}
		p2=p2.get_prev(bound);
	}
	std::cout << sum << std::endl;
	return 0;
}
