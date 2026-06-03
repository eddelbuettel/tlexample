#include <Rcpp/Lighter>
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
