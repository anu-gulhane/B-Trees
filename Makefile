# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chandu/Desktop/DataSystems/phase-3-team-8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chandu/Desktop/DataSystems/phase-3-team-8

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/local/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/chandu/Desktop/DataSystems/phase-3-team-8/CMakeFiles /home/chandu/Desktop/DataSystems/phase-3-team-8//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/chandu/Desktop/DataSystems/phase-3-team-8/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named BPTree

# Build rule for target.
BPTree: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 BPTree
.PHONY : BPTree

# fast build rule for target.
BPTree/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/build
.PHONY : BPTree/fast

src/BPTree.o: src/BPTree.cpp.o
.PHONY : src/BPTree.o

# target to build an object file
src/BPTree.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/BPTree.cpp.o
.PHONY : src/BPTree.cpp.o

src/BPTree.i: src/BPTree.cpp.i
.PHONY : src/BPTree.i

# target to preprocess a source file
src/BPTree.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/BPTree.cpp.i
.PHONY : src/BPTree.cpp.i

src/BPTree.s: src/BPTree.cpp.s
.PHONY : src/BPTree.s

# target to generate assembly for a file
src/BPTree.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/BPTree.cpp.s
.PHONY : src/BPTree.cpp.s

src/Block.o: src/Block.cpp.o
.PHONY : src/Block.o

# target to build an object file
src/Block.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/Block.cpp.o
.PHONY : src/Block.cpp.o

src/Block.i: src/Block.cpp.i
.PHONY : src/Block.i

# target to preprocess a source file
src/Block.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/Block.cpp.i
.PHONY : src/Block.cpp.i

src/Block.s: src/Block.cpp.s
.PHONY : src/Block.s

# target to generate assembly for a file
src/Block.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/Block.cpp.s
.PHONY : src/Block.cpp.s

src/InternalNode.o: src/InternalNode.cpp.o
.PHONY : src/InternalNode.o

# target to build an object file
src/InternalNode.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/InternalNode.cpp.o
.PHONY : src/InternalNode.cpp.o

src/InternalNode.i: src/InternalNode.cpp.i
.PHONY : src/InternalNode.i

# target to preprocess a source file
src/InternalNode.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/InternalNode.cpp.i
.PHONY : src/InternalNode.cpp.i

src/InternalNode.s: src/InternalNode.cpp.s
.PHONY : src/InternalNode.s

# target to generate assembly for a file
src/InternalNode.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/InternalNode.cpp.s
.PHONY : src/InternalNode.cpp.s

src/LeafNode.o: src/LeafNode.cpp.o
.PHONY : src/LeafNode.o

# target to build an object file
src/LeafNode.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/LeafNode.cpp.o
.PHONY : src/LeafNode.cpp.o

src/LeafNode.i: src/LeafNode.cpp.i
.PHONY : src/LeafNode.i

# target to preprocess a source file
src/LeafNode.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/LeafNode.cpp.i
.PHONY : src/LeafNode.cpp.i

src/LeafNode.s: src/LeafNode.cpp.s
.PHONY : src/LeafNode.s

# target to generate assembly for a file
src/LeafNode.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/LeafNode.cpp.s
.PHONY : src/LeafNode.cpp.s

src/Logger.o: src/Logger.cpp.o
.PHONY : src/Logger.o

# target to build an object file
src/Logger.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/Logger.cpp.o
.PHONY : src/Logger.cpp.o

src/Logger.i: src/Logger.cpp.i
.PHONY : src/Logger.i

# target to preprocess a source file
src/Logger.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/Logger.cpp.i
.PHONY : src/Logger.cpp.i

src/Logger.s: src/Logger.cpp.s
.PHONY : src/Logger.s

# target to generate assembly for a file
src/Logger.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/Logger.cpp.s
.PHONY : src/Logger.cpp.s

src/Query.o: src/Query.cpp.o
.PHONY : src/Query.o

# target to build an object file
src/Query.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/Query.cpp.o
.PHONY : src/Query.cpp.o

src/Query.i: src/Query.cpp.i
.PHONY : src/Query.i

# target to preprocess a source file
src/Query.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/Query.cpp.i
.PHONY : src/Query.cpp.i

src/Query.s: src/Query.cpp.s
.PHONY : src/Query.s

# target to generate assembly for a file
src/Query.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/Query.cpp.s
.PHONY : src/Query.cpp.s

src/RecordPtr.o: src/RecordPtr.cpp.o
.PHONY : src/RecordPtr.o

# target to build an object file
src/RecordPtr.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/RecordPtr.cpp.o
.PHONY : src/RecordPtr.cpp.o

src/RecordPtr.i: src/RecordPtr.cpp.i
.PHONY : src/RecordPtr.i

# target to preprocess a source file
src/RecordPtr.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/RecordPtr.cpp.i
.PHONY : src/RecordPtr.cpp.i

src/RecordPtr.s: src/RecordPtr.cpp.s
.PHONY : src/RecordPtr.s

# target to generate assembly for a file
src/RecordPtr.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/RecordPtr.cpp.s
.PHONY : src/RecordPtr.cpp.s

src/TreeNode.o: src/TreeNode.cpp.o
.PHONY : src/TreeNode.o

# target to build an object file
src/TreeNode.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/TreeNode.cpp.o
.PHONY : src/TreeNode.cpp.o

src/TreeNode.i: src/TreeNode.cpp.i
.PHONY : src/TreeNode.i

# target to preprocess a source file
src/TreeNode.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/TreeNode.cpp.i
.PHONY : src/TreeNode.cpp.i

src/TreeNode.s: src/TreeNode.cpp.s
.PHONY : src/TreeNode.s

# target to generate assembly for a file
src/TreeNode.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/TreeNode.cpp.s
.PHONY : src/TreeNode.cpp.s

src/UnorderedHeap.o: src/UnorderedHeap.cpp.o
.PHONY : src/UnorderedHeap.o

# target to build an object file
src/UnorderedHeap.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/UnorderedHeap.cpp.o
.PHONY : src/UnorderedHeap.cpp.o

src/UnorderedHeap.i: src/UnorderedHeap.cpp.i
.PHONY : src/UnorderedHeap.i

# target to preprocess a source file
src/UnorderedHeap.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/UnorderedHeap.cpp.i
.PHONY : src/UnorderedHeap.cpp.i

src/UnorderedHeap.s: src/UnorderedHeap.cpp.s
.PHONY : src/UnorderedHeap.s

# target to generate assembly for a file
src/UnorderedHeap.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/UnorderedHeap.cpp.s
.PHONY : src/UnorderedHeap.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/utils.o: src/utils.cpp.o
.PHONY : src/utils.o

# target to build an object file
src/utils.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/utils.cpp.o
.PHONY : src/utils.cpp.o

src/utils.i: src/utils.cpp.i
.PHONY : src/utils.i

# target to preprocess a source file
src/utils.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/utils.cpp.i
.PHONY : src/utils.cpp.i

src/utils.s: src/utils.cpp.s
.PHONY : src/utils.s

# target to generate assembly for a file
src/utils.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/BPTree.dir/build.make CMakeFiles/BPTree.dir/src/utils.cpp.s
.PHONY : src/utils.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... BPTree"
	@echo "... src/BPTree.o"
	@echo "... src/BPTree.i"
	@echo "... src/BPTree.s"
	@echo "... src/Block.o"
	@echo "... src/Block.i"
	@echo "... src/Block.s"
	@echo "... src/InternalNode.o"
	@echo "... src/InternalNode.i"
	@echo "... src/InternalNode.s"
	@echo "... src/LeafNode.o"
	@echo "... src/LeafNode.i"
	@echo "... src/LeafNode.s"
	@echo "... src/Logger.o"
	@echo "... src/Logger.i"
	@echo "... src/Logger.s"
	@echo "... src/Query.o"
	@echo "... src/Query.i"
	@echo "... src/Query.s"
	@echo "... src/RecordPtr.o"
	@echo "... src/RecordPtr.i"
	@echo "... src/RecordPtr.s"
	@echo "... src/TreeNode.o"
	@echo "... src/TreeNode.i"
	@echo "... src/TreeNode.s"
	@echo "... src/UnorderedHeap.o"
	@echo "... src/UnorderedHeap.i"
	@echo "... src/UnorderedHeap.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/utils.o"
	@echo "... src/utils.i"
	@echo "... src/utils.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

