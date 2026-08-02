#include <exception>

std::terminate_handler _g_terminate_handler = nullptr;

FSTDCXX_API std::exception::~exception() {
}

FSTDCXX_API const char *std::exception::what() {
	return "An exception without overriden what() is thrown";
}
