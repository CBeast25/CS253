# This is a Makefile.  Its purpose is to create the program “small”.
#
#
# The rules, below, indicate what depends on what, and how to build
# things when they get out-of-date.  It is VERY important to know that
# what looks like eight leading spaces is really a leading tab
# character.  Leading spaces won’t work--it MUST be a tab character.
#
# For the following questions, do the command if there is one,
# and then answer the question.  If you need another line for you
# answer, continue it on the next line, indented.
#
# As an example, I’ve already answered (1), which has nothing to do
# with anything else in this lab.
#
# Question 1 is worth 0.09 points; questions 2–14 are worth 0.07
# points each.
#
#  1) Command:  date +%A
#     Question: Describe the output of that command.
#     Answer:   It’s today’s day of the week.
#
#  2) Command:  make
#     Question: Describe what happens.  Don’t just write the commands;
#     		describe what each command does.
#     Answer:   It compiles main.cc and foo.cc and then it compiles both of 
#     		their ".o" files into the file small
#
#  3) Command:  ./small
#     Question: What is the output?  Reproduce the output exactly.
#     Answer:   Hi from main at main.cc:15
#     		Hi from foo at foo.cc:14
#
#  4) Command:  make
#     Question: Why did nothing much happen?
#     Answer:   main.cc and foo.cc were not updated since the last make
#     		therefore nothing needed to happen
#
#  5) Command:  rm small; make
#     Question: What got remade, and why?
#     Answer:   Only small got remade because main.o and foo.o already existed
#
#  6) Command:  rm foo.o; make
#     Question: What got remade, and why?
#     Answer:   foo.o and small got remade because foo.o didn't exist and
#     		small got remade because the foo.o file was updated
#
#  7) Command:  make clean
#     Question: What did that do?
#     Answer:   Removed main.o, foo.o, and small
#
#  8) Command:  make
#     Question: What got remade, and why?
#     Answer:   main.o, foo.o, and small got remade because their files were removed
#
#  9) Question: Why does main.o depend on foo.h?
#		I know that it’s because the Makefile says so.
#		Why was that dependency put into the Makefile?
#     Answer:   It was put into the make file because main.cc includes foo.h
#
# 10) Command:  Create a new function bar() in bar.cc & bar.h,
# 		similar to foo.cc.  Change main.cc to call the new
# 		bar() function, make sure to #include the proper .h
# 		files everywhere, and type “make”.  Don’t alter Makefile.
#     Question: Why did it fail?
#     Answer:   The make file doesn't compile main.cc with bar.cc, bar.h, and bar.o 
#     		but foo.cc, foo.h, and foo.o
#
# 11) Command:  Fix the Makefile; verify with “make” until it compiles.
#     Question: Describe your changes.  Don’t just show the changed
#     		lines--describe the purpose of each change.
#     Answer:   Replace all foo references in the file to bar in order to compile with
#     		the correct files
#
# 12) Command:  Uncomment the CXXFLAGS= line, and type “make”.
#     Question: Why didn't anything happen?
#     Answer:   Small is up to date with the .o files
#
# 13) Command:  Force a rebuild with: make clean; make
#     Question: What’s new about the commands executed?
#     Answer:   The commands show all the CXXFLAGS
#
# 14) Command: 	make clean; ls -l clean
#     Question: The target is “clean”, but no file “clean” got created.
#     		Why not?
#     Answer:   make clean is a make command declared in the file
#     		not a command to make a file named clean
#
# For extra fame & glory (but no extra points):
#
# 15) Command:  Consult the make manual at
# 		https://www.gnu.org/software/make/manual/make.html
#		and improve this Makefile by using $@ in the rule
#		that creates “small” itself.

# The CXX variable contains the name of the C++ compiler.  You can’t
# have plus signs in a Make variable, so X is a rotated plus sign.
CXX=g++

CXXFLAGS=-std=c++17 -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -Winit-self -Wshadow -Wlogical-op -Wcomment -Wctor-dtor-privacy -Wold-style-cast -D_GLIBCXX_DEBUG -fno-diagnostics-show-option

small: main.o bar.o
	$(CXX) $(CXXFLAGS) main.o bar.o -o small

main.o: main.cc bar.h
	$(CXX) $(CXXFLAGS) -c main.cc

foo.o: bar.cc bar.h
	$(CXX) $(CXXFLAGS) -c bar.cc

clean:
	-rm -f small *.o
