#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T *array, int length, void (*f)(T const &)) {
	if (!array || !f)
		return ;
	for (int i = 0; i < length; i++) {
		f(array[i]);
	}
}

#endif