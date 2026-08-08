#ifndef _FSTDCXX_BASE_FUNCTIONAL_REF_WRAPPER_HH_
#define _FSTDCXX_BASE_FUNCTIONAL_REF_WRAPPER_HH_

#include <_type_traits/is_void.hh>
#include <_utility/forward.hh>
#include <_utility/move.hh>
#include <memory>

namespace std {
	template <typename T>
	class reference_wrapper {
	private:
		T *_ptr;

	public:
		using type = T;

		template <typename U, typename = std::enable_if_t<!std::is_void_v<U>>>
		explicit reference_wrapper(U &ref) noexcept
			: _ptr(std::addressof(ref)) {}

		reference_wrapper(const reference_wrapper &) noexcept = default;
		reference_wrapper &operator=(const reference_wrapper &) noexcept = default;

		operator T &() const noexcept {
			return *_ptr;
		}

		T &get() const noexcept {
			return *_ptr;
		}

		template <typename... Args>
		decltype(auto) operator()(Args &&...args) const {
			return get()(std::forward<Args>(args)...);
		}
	};

	template <typename T>
	reference_wrapper<T> ref(T &t) noexcept {
		return reference_wrapper<T>(t);
	}

	template <typename T>
	reference_wrapper<const T> cref(const T &t) noexcept {
		return reference_wrapper<const T>(t);
	}

	template <typename T>
	void ref(const T &&) = delete;

	template <typename T>
	void cref(const T &&) = delete;
}

#endif
