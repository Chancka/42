#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <iostream>

class Span
{
	private:
		std::vector<int>    _v;
		unsigned int        _n;
	public:
		Span();
		Span(unsigned int n);
		Span(Span const & src);
		~Span();

		Span & operator=(Span const & rhs);

		void addNumber(int n); // add a number to the vector
		int shortestSpan(); // returns the shortest span between two elements in the container
		int longestSpan(); // returns the longest span between two elements in the container
		void addRange(int start, int end); // add a range of numbers
		void addRandomRange(int start, int end, int n); // add n random numbers
		
};

#endif
