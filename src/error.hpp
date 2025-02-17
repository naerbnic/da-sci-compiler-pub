//	error.hpp

#ifndef ERROR_HPP
#define ERROR_HPP

#include "absl/strings/str_format.h"
#include "sc.hpp"

void EarlyEnd();

template <class... Args>
void Error(absl::FormatSpec<Args...> const&, Args const&... args);

template <class... Args>
[[noreturn]] void Fatal(absl::FormatSpec<Args...> const&, Args const&... args);

template <class... Args>
void Info(absl::FormatSpec<Args...> const&, Args const&... args);

template <class... Args>
void output(absl::FormatSpec<Args...> const&, Args const&... args);

template <class... Args>
void Severe(absl::FormatSpec<Args...> const&, Args const&... args);

template <class... Args>
void Warning(absl::FormatSpec<Args...> const&, Args const&... args);

template <class... Args>
[[noreturn]] void Panic(absl::FormatSpec<Args...> const&, Args const&... args);

extern int errors;
extern int warnings;

// Implementation Below

namespace error_impl {

void WriteError(std::string_view text);
[[noreturn]] void WriteFatal(std::string_view text);
void WriteInfo(std::string_view text);
void WriteOutput(std::string_view text);
void WriteSevere(std::string_view text);
void WriteWarning(std::string_view text);
[[noreturn]] void WritePanic(std::string_view text);

}  // namespace error_impl

template <class... Args>
void Error(absl::FormatSpec<Args...> const& spec, Args const&... args) {
  error_impl::WriteError(absl::StrFormat(spec, args...));
}

template <class... Args>
[[noreturn]] void Fatal(absl::FormatSpec<Args...> const& spec,
                        Args const&... args) {
  error_impl::WriteFatal(absl::StrFormat(spec, args...));
}

template <class... Args>
void Info(absl::FormatSpec<Args...> const& spec, Args const&... args) {
  error_impl::WriteInfo(absl::StrFormat(spec, args...));
}

template <class... Args>
void output(absl::FormatSpec<Args...> const& spec, Args const&... args) {
  error_impl::WriteOutput(absl::StrFormat(spec, args...));
}

template <class... Args>
void Severe(absl::FormatSpec<Args...> const& spec, Args const&... args) {
  error_impl::WriteSevere(absl::StrFormat(spec, args...));
}

template <class... Args>
void Warning(absl::FormatSpec<Args...> const& spec, Args const&... args) {
  error_impl::WriteWarning(absl::StrFormat(spec, args...));
}

template <class... Args>
[[noreturn]] void Panic(absl::FormatSpec<Args...> const& spec,
                        Args const&... args) {
  error_impl::WritePanic(absl::StrFormat(spec, args...));
}

#endif
