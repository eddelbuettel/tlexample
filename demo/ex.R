#!/usr/bin/env Rscript


tl::info("hello from R, setting name")
tl::set_name("bob")
tl::info("name set in R, calling C++ with '{}'", "fifi")
tlexample::bar("fifi")

cat("\n\n")

tl::info("foofoo info")
tl::debug("foofoo debug")
tl::info("level setting from R to '{}'", "error")
tl::set_level("error")
tlexample::bar("fifi2")

cat("\n\n")
tl::info("level setting from R to '{}'", "warn")
tl::set_level("warn")
tlexample::bar("fifi3")
