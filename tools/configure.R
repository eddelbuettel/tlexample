
cppstd <- tl:::cppstandard()
cxxstd <- if (cppstd >= 202002) "CXX20" else "CXX17"
infile <- file.path("src", "Makevars.in")
outfile <- file.path("src", "Makevars")
lines <- readLines(infile)
lines <- gsub("@CXXSTD@", cxxstd, lines)
writeLines(lines, outfile)
