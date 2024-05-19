#pragma once
#include"shape.h"
class transform
{
public:
	transform(const BasicShape& sh);
	BasicShape shift(int m, int n, int k);
	BasicShape scaleX(int a);
	BasicShape scaleY(int d);
	BasicShape scaleZ(int e);
	BasicShape scale(int s);

private:
	BasicShape shape;
};

