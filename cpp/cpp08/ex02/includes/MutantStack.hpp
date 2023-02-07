#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(MutantStack const &src) : std::stack<T>(src) {}
		virtual ~MutantStack() {}

		MutantStack &operator=(MutantStack const &rhs)
		{
			std::stack<T>::operator=(rhs);
			return *this;
		}

		typedef typename std::deque<T>::iterator iterator;

		iterator begin()
		{
			return std::stack<T>::c.begin();
		}

		iterator end()
		{
			return std::stack<T>::c.end();
		}

};

#endif
