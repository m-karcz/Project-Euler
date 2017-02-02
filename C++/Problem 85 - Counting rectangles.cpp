#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <chrono>

const int two_m=2000000;

struct Rectangle
{
	Rectangle(int x, int y, int height) : x(x), y(y), height(height), amount(height-y+1) {};
	int x;
	int y;
	int height;
	int amount;
	void expand_right()
	{
		amount+=(height-y+1);
	}
};

class Grid
{
public:
	Grid(int yy) : height(yy)
	{
		for(int y=1; y<=height; y++)
		{
			rectangles.emplace_back(1, y, height);
		}
	}
	int height;
	int width=1;
	int get_diff()
	{
		while(true)
		{
			int next_amount=0;
			for(auto& rectangle : rectangles)
			{
				rectangle.expand_right();
			}
			for(int y=1; y<=height; y++)
			{
				rectangles.emplace_back(width+1, y, height);
			}
			for(auto& rectangle : rectangles)
			{
				next_amount+=rectangle.amount;
			}
			if(next_amount>two_m)
			{
				if(next_amount-two_m<two_m-amount)
				{
					width++;
					amount=next_amount;
				}
				return std::abs(amount-two_m);
			}
			else
			{
				width++;
				amount=next_amount;
			}
		}
		
	}
	int get_area()
	{
		return height*width;
	}
private:
	int last_size=0;
	int amount=0;
	std::vector<Rectangle> rectangles;
};

int main()
{
	int last_width=-1;
	int last_height=0;
	int area=0;
	int diff=std::numeric_limits<int>::max();
	int height=1;
	while(true)
	{
		Grid grid(height++);
		int grid_diff=grid.get_diff();
		if(grid_diff<diff)
		{
			area=grid.get_area();
			diff=grid_diff;
		}
		if(grid.width==grid.height || (last_width==grid.height && last_height==grid.width) || grid.width==1)
			break;
		last_width=grid.width;
		last_height=grid.height;
	}
	std::cout << area << std::endl;
	return 0;
}
