#pragma once
#include <QColor>

struct TreeData
{
	int x;
	int y;
	int value;
	QColor color;

	TreeData(int value = 0, int x = 0, int y = 0):
		x(x), y(y), value(value)
	{}

	bool operator<(const TreeData &data) const
	{
		return value < data.value;
	}

	bool operator>(const TreeData &data) const
	{
		return value > data.value;
	}

	bool operator==(const TreeData &data) const
	{
		return value == data.value;
	}
};
