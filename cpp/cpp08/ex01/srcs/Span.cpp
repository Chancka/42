#include "../includes/Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(Span const & src) : _n(src._n) {}

Span::~Span() {}

Span & Span::operator=(Span const & rhs)
{
	if (this != &rhs)
		_n = rhs._n;
	return *this;
}

void Span::addNumber(int n)
{
	if (_v.size() < _n)
		_v.push_back(n);
	else
		throw std::exception();
}

int Span::shortestSpan()
{
	if (_v.size() < 2)
		throw std::exception();
	std::vector<int> v(_v);
	std::sort(v.begin(), v.end());
	int min = v[1] - v[0];
	for (unsigned int i = 2; i < v.size(); i++)
	{
		if (v[i] - v[i - 1] < min)
			min = v[i] - v[i - 1];
	}
	return min;
}

int Span::longestSpan()
{
	if (_v.size() < 2)
		throw std::exception();
	std::vector<int> v(_v);
	std::sort(v.begin(), v.end());
	return v[v.size() - 1] - v[0];
}

void Span::addRange(int start, int end)
{
	if (start > end)
		throw std::exception();
	for (int i = start; i <= end; i++)
		addNumber(i);
}

void Span::addRandomRange(int start, int end, int n)
{
	if (start > end)
		throw std::exception();
	for (int i = 0; i < n; i++)
		addNumber(rand() % (end - start + 1) + start);
}
