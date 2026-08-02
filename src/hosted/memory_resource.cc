#include <memory_resource>

class _null_memory_resource final : public std::pmr::memory_resource {
protected:
	virtual void *do_allocate(std::size_t bytes, std::size_t alignment) override {
		return nullptr;
	}

	virtual void do_deallocate(void *p, std::size_t bytes, std::size_t alignment) override {
		return;
	}

	virtual bool do_is_equal(const std::pmr::memory_resource &other) const noexcept override {
		return &other == this;
	}
};

static _null_memory_resource _g_null_memory_resource;

FSTDCXX_API std::pmr::memory_resource *new_delete_resource() noexcept {
	return &_g_null_memory_resource;
}
