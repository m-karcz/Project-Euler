#include <stdio.h>
#include <math.h>
#include <stdbool.h>

const double eps = 0.00001f;

typedef struct Point_
{
	double x;
	double y;
} Point;

typedef struct Vector_
{
	double x;
	double y;
} Vector;

typedef struct Line_ //Ax + By + C = 0
{
	double A;
	double B;
	double C;
} Line;

typedef struct Ellipse_ //Ax^2 + By^2 - C = 0
{
	double A;
	double B;
	double C;
} Ellipse;

bool cmp(const Point* a, const Point* b)
{
	return fabs(a->x - b->x) < eps && fabs(a->y - b->y) < eps;
}

void intersect(const Line* line, const Ellipse* ellipse, Point* p1, Point* p2)
{
	double B2 = line->B * line->B;
	double a = ellipse->A + (line->A * line->A) / B2;
	double b = 2.0 * line->A * line->C / B2;
	double c = line->C * line->C / B2 + ellipse->C;
	double deltasqrt = sqrt(b * b - 4 * a * c);
	p1->x = (-b + deltasqrt) / (2.0 * a);
	p2->x = (-b - deltasqrt) / (2.0 * a);
	p1->y = (-line->A * p1->x - line->C) / line->B;
	p2->y = (-line->A * p2->x - line->C) / line->B;
	return;
}

Point intersect_lines(const Line* line1, const Line* line2)
{
	double det = line1->A * line2->B - line2->A * line1->B;
	Point point = {
		.x = -(line1->C * line2->B - line2->C * line1->B) / det,
		.y = -(line2->C * line1->A - line1->C * line2->A) / det
	};
	return point;
}

Line points2line(const Point* p1, const Point* p2)
{
	Line line;
	double det = p1->x * p2->y - p1->y * p2->x;
	line.A = (p2->y - p1->y) / det;
	line.B = (p1->x - p2->x) / det;
	line.C = - (line.A * p1->x + line.B * p1->y);
	return line;
}

Line vect2line_par(const Vector* vect, const Point* point)
{
	Line line = {
		.A = vect->y,
		.B = vect->x,
		.C = -(vect->y * point->x + vect->x * point->y)
	};
	return line;
}

Vector get_ort(const Line* line)
{
	Vector vect = {
		.x = line->A,
		.y = - line->B
	};
	return vect;
}


Line rotate_line(const Line* line, const Point* point)
{
	Vector ort_vect = get_ort(line);
	return vect2line_par(&ort_vect, point);
}

Point flip_by_line(const Point* point, const Line* line)
{
	Point result;
	Line ort_line = rotate_line(line, point);
	Point intersection = intersect_lines(line, &ort_line);
	result.x = point->x + 2.0 * (intersection.x - point->x);
	result.y = point->y + 2.0 * (intersection.y - point->y);
	return result;
}

Line get_mirror(const Ellipse* ellipse, const Point* point)
{
	Vector ort_vect = {
		.x = - ellipse->A * point->x,
		.y = ellipse->B * point->y
	};
	return vect2line_par(&ort_vect, point);
}

int main()
{
	Ellipse cell = {
		.A = 4.0,
		.B = 1.0,
		.C = -100.0
	};
	Point beam_start = {
		.x = 0,
		.y = 10.1
	};
	Point beam_end = {
		.x = 1.4,
		.y = -9.6
	};
	Line beam = points2line(&beam_start, &beam_end);
	int beams = 0;
	while(fabs(beam_end.x) > 0.01 || beam_end.y < 0.0)
	{
		Line mirror = get_mirror(&cell, &beam_end);
		Point mirrored_beam_start = flip_by_line(&beam_start, &mirror);
		beam = points2line(&beam_end, &mirrored_beam_start);
		beam_start = beam_end;
		Point p1, p2;
		intersect(&beam, &cell, &p1, &p2);
		if(cmp(&p1,&beam_start))
			beam_end = p2;
		else if(cmp(&p2,&beam_start))
			beam_end = p1;
		else
		{
			printf("error after intersection");
			return 0;
		}
		beams++;
	}
	printf("beams: %i\n", beams);
}
