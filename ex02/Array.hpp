#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <cstddef>

template <typename T>
class Array {
	public:
		Array( void ): _array(NULL), _len(0) {};
		Array( unsigned int n): _array(new T[n]), _len(n) {};
		Array( const Array &obj) {
			if (this != &obj) {
				_array = new T[obj._len];
				_len = obj._len;
				for (int i = 0; i < _len; i++) {
					_array[i] = obj._array[i];
				}
			}
		}
		Array	&operator=(const Array &obj) {
			if (this != &obj) {
				delete[] _array;
				_array = new T[obj._len];
				_len = obj._len;
				for (int i = 0; i < _len; i++) {
					_array[i] = obj._array[i];
				}
			}
			return (*this);
		}
		~Array( void ) {
			delete[] _array;
		}

		T	&operator[]( int pos ) {
			if (pos >= _len || pos < 0 || !_array)
				throw ArrayOutOfBoundsException();
			return (_array[pos]);
		}

		int	size( void ) {
			return (_len);
		}

	private:
		T	*_array;
		int	_len;
	
	class	ArrayOutOfBoundsException: public std::exception {
		public:
			const char  *what( void ) const throw() {
				return ("Error: accessing element out of bounds of the Array");
			}
	};
};

#endif