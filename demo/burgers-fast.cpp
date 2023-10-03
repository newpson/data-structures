#include <iostream>

static
void read(int &to, int count)
{
	char in;
	while (count--)
	{
		std::cin >> in;
		to += (in-'0')%2;
	}
}

int main(void)
{
	int count, burgers = 0, students = 0;
	std::cin >> count;

	/* preferences */
	read(students, count);
	/* available burgers */
	read(burgers, count);

	std::cout << abs(students-burgers) << std::endl;
	return 0;
}
