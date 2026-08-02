#ifndef _FSTDCXX_BASE_ITERATOR_ITER_TAGS_
#define _FSTDCXX_BASE_ITERATOR_ITER_TAGS_

#include <type_traits>

namespace std {
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};
	struct contiguous_iterator_tag : public random_access_iterator_tag {};
}

#endif
