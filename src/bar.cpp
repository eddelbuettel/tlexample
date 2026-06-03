#include <Rcpp/Lighter>

// We need to guard against the systems which we know cannot cope
// This is approximative, and right now mostly for use at r-universe
// where all Linux and Windows builds work (or r-release or r-devel)
// but where macOS croaks on any x86_64 and on arm64-oldrel surviving
// only for arm64-release
#if (defined(__APPLE__) && defined(__MACH__) && (defined(__aarch64__) && R_VERSION >= R_Version(4,6,0))) || __cplusplus < 202002L

void bar(std::string) {
  Rcpp::Rcout << "Sorry, insufficient C++20 support on this platform.\n";
}

#else

#include <tl.h>

//' @title Simple example function
//'
//' @description The \pkg{tl} package provides a uniform interface to logging
//' from both R and C++ using the same namespaced \code{tl::debug()} (and alike
//' for differ logging verbs) interface. This package (and function)
//' demonstrates it.
//'
//' @param s A character string, defaults to \dQuote{baz}
//'
//' @return Nothing is returned as the function is invoked for its side-effect.
//'
// [[Rcpp::export]]
void bar(std::string s = "baz") {
  tl::error("error log from C++ {}", s);
  tl::warn("warn log from C++ {} {}", s, 1.23);
  tl::info("info log from C++ {} {} {}", s, 1.23, 42L);
  tl::info("setting name in C++ to {}", "frodo");
  tl::set_name("frodo");
  tl::info("info log from C++ {} {} {}", s, 1.23, 42L);
  tl::warn("warn log from C++ {} {}", s, 1.23);
  tl::debug("unseen as level is {}", tl::get_level());
  tl::set_level("debug");
  tl::debug("seen as level from C++ is now '{}'", tl::get_level());
}

#endif
