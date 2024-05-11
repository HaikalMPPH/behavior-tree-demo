# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/haikal-mpph/Documents/personal/projects/cpp/behavior-tree-demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/haikal-mpph/Documents/personal/projects/cpp/behavior-tree-demo

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/haikal-mpph/Documents/personal/projects/cpp/behavior-tree-demo/CMakeFiles /home/haikal-mpph/Documents/personal/projects/cpp/behavior-tree-demo//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/haikal-mpph/Documents/personal/projects/cpp/behavior-tree-demo/CMakeFiles 0
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
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

src/ai/behavior.o: src/ai/behavior.cpp.o
.PHONY : src/ai/behavior.o

# target to build an object file
src/ai/behavior.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/behavior.cpp.o
.PHONY : src/ai/behavior.cpp.o

src/ai/behavior.i: src/ai/behavior.cpp.i
.PHONY : src/ai/behavior.i

# target to preprocess a source file
src/ai/behavior.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/behavior.cpp.i
.PHONY : src/ai/behavior.cpp.i

src/ai/behavior.s: src/ai/behavior.cpp.s
.PHONY : src/ai/behavior.s

# target to generate assembly for a file
src/ai/behavior.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/behavior.cpp.s
.PHONY : src/ai/behavior.cpp.s

src/ai/behavior_tree.o: src/ai/behavior_tree.cpp.o
.PHONY : src/ai/behavior_tree.o

# target to build an object file
src/ai/behavior_tree.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/behavior_tree.cpp.o
.PHONY : src/ai/behavior_tree.cpp.o

src/ai/behavior_tree.i: src/ai/behavior_tree.cpp.i
.PHONY : src/ai/behavior_tree.i

# target to preprocess a source file
src/ai/behavior_tree.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/behavior_tree.cpp.i
.PHONY : src/ai/behavior_tree.cpp.i

src/ai/behavior_tree.s: src/ai/behavior_tree.cpp.s
.PHONY : src/ai/behavior_tree.s

# target to generate assembly for a file
src/ai/behavior_tree.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/behavior_tree.cpp.s
.PHONY : src/ai/behavior_tree.cpp.s

src/ai/behavior_tree_builder.o: src/ai/behavior_tree_builder.cpp.o
.PHONY : src/ai/behavior_tree_builder.o

# target to build an object file
src/ai/behavior_tree_builder.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/behavior_tree_builder.cpp.o
.PHONY : src/ai/behavior_tree_builder.cpp.o

src/ai/behavior_tree_builder.i: src/ai/behavior_tree_builder.cpp.i
.PHONY : src/ai/behavior_tree_builder.i

# target to preprocess a source file
src/ai/behavior_tree_builder.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/behavior_tree_builder.cpp.i
.PHONY : src/ai/behavior_tree_builder.cpp.i

src/ai/behavior_tree_builder.s: src/ai/behavior_tree_builder.cpp.s
.PHONY : src/ai/behavior_tree_builder.s

# target to generate assembly for a file
src/ai/behavior_tree_builder.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/behavior_tree_builder.cpp.s
.PHONY : src/ai/behavior_tree_builder.cpp.s

src/ai/composite/composite.o: src/ai/composite/composite.cpp.o
.PHONY : src/ai/composite/composite.o

# target to build an object file
src/ai/composite/composite.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/composite/composite.cpp.o
.PHONY : src/ai/composite/composite.cpp.o

src/ai/composite/composite.i: src/ai/composite/composite.cpp.i
.PHONY : src/ai/composite/composite.i

# target to preprocess a source file
src/ai/composite/composite.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/composite/composite.cpp.i
.PHONY : src/ai/composite/composite.cpp.i

src/ai/composite/composite.s: src/ai/composite/composite.cpp.s
.PHONY : src/ai/composite/composite.s

# target to generate assembly for a file
src/ai/composite/composite.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/composite/composite.cpp.s
.PHONY : src/ai/composite/composite.cpp.s

src/ai/composite/random.o: src/ai/composite/random.cpp.o
.PHONY : src/ai/composite/random.o

# target to build an object file
src/ai/composite/random.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/composite/random.cpp.o
.PHONY : src/ai/composite/random.cpp.o

src/ai/composite/random.i: src/ai/composite/random.cpp.i
.PHONY : src/ai/composite/random.i

# target to preprocess a source file
src/ai/composite/random.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/composite/random.cpp.i
.PHONY : src/ai/composite/random.cpp.i

src/ai/composite/random.s: src/ai/composite/random.cpp.s
.PHONY : src/ai/composite/random.s

# target to generate assembly for a file
src/ai/composite/random.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/composite/random.cpp.s
.PHONY : src/ai/composite/random.cpp.s

src/ai/composite/selector.o: src/ai/composite/selector.cpp.o
.PHONY : src/ai/composite/selector.o

# target to build an object file
src/ai/composite/selector.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/composite/selector.cpp.o
.PHONY : src/ai/composite/selector.cpp.o

src/ai/composite/selector.i: src/ai/composite/selector.cpp.i
.PHONY : src/ai/composite/selector.i

# target to preprocess a source file
src/ai/composite/selector.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/composite/selector.cpp.i
.PHONY : src/ai/composite/selector.cpp.i

src/ai/composite/selector.s: src/ai/composite/selector.cpp.s
.PHONY : src/ai/composite/selector.s

# target to generate assembly for a file
src/ai/composite/selector.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/composite/selector.cpp.s
.PHONY : src/ai/composite/selector.cpp.s

src/ai/composite/sequence.o: src/ai/composite/sequence.cpp.o
.PHONY : src/ai/composite/sequence.o

# target to build an object file
src/ai/composite/sequence.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/composite/sequence.cpp.o
.PHONY : src/ai/composite/sequence.cpp.o

src/ai/composite/sequence.i: src/ai/composite/sequence.cpp.i
.PHONY : src/ai/composite/sequence.i

# target to preprocess a source file
src/ai/composite/sequence.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/composite/sequence.cpp.i
.PHONY : src/ai/composite/sequence.cpp.i

src/ai/composite/sequence.s: src/ai/composite/sequence.cpp.s
.PHONY : src/ai/composite/sequence.s

# target to generate assembly for a file
src/ai/composite/sequence.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/composite/sequence.cpp.s
.PHONY : src/ai/composite/sequence.cpp.s

src/ai/decorator/decorator.o: src/ai/decorator/decorator.cpp.o
.PHONY : src/ai/decorator/decorator.o

# target to build an object file
src/ai/decorator/decorator.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/decorator/decorator.cpp.o
.PHONY : src/ai/decorator/decorator.cpp.o

src/ai/decorator/decorator.i: src/ai/decorator/decorator.cpp.i
.PHONY : src/ai/decorator/decorator.i

# target to preprocess a source file
src/ai/decorator/decorator.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/decorator/decorator.cpp.i
.PHONY : src/ai/decorator/decorator.cpp.i

src/ai/decorator/decorator.s: src/ai/decorator/decorator.cpp.s
.PHONY : src/ai/decorator/decorator.s

# target to generate assembly for a file
src/ai/decorator/decorator.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/decorator/decorator.cpp.s
.PHONY : src/ai/decorator/decorator.cpp.s

src/ai/decorator/invert.o: src/ai/decorator/invert.cpp.o
.PHONY : src/ai/decorator/invert.o

# target to build an object file
src/ai/decorator/invert.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/decorator/invert.cpp.o
.PHONY : src/ai/decorator/invert.cpp.o

src/ai/decorator/invert.i: src/ai/decorator/invert.cpp.i
.PHONY : src/ai/decorator/invert.i

# target to preprocess a source file
src/ai/decorator/invert.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/decorator/invert.cpp.i
.PHONY : src/ai/decorator/invert.cpp.i

src/ai/decorator/invert.s: src/ai/decorator/invert.cpp.s
.PHONY : src/ai/decorator/invert.s

# target to generate assembly for a file
src/ai/decorator/invert.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/decorator/invert.cpp.s
.PHONY : src/ai/decorator/invert.cpp.s

src/ai/decorator/repeat.o: src/ai/decorator/repeat.cpp.o
.PHONY : src/ai/decorator/repeat.o

# target to build an object file
src/ai/decorator/repeat.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/decorator/repeat.cpp.o
.PHONY : src/ai/decorator/repeat.cpp.o

src/ai/decorator/repeat.i: src/ai/decorator/repeat.cpp.i
.PHONY : src/ai/decorator/repeat.i

# target to preprocess a source file
src/ai/decorator/repeat.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/decorator/repeat.cpp.i
.PHONY : src/ai/decorator/repeat.cpp.i

src/ai/decorator/repeat.s: src/ai/decorator/repeat.cpp.s
.PHONY : src/ai/decorator/repeat.s

# target to generate assembly for a file
src/ai/decorator/repeat.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/decorator/repeat.cpp.s
.PHONY : src/ai/decorator/repeat.cpp.s

src/ai/leaf/action.o: src/ai/leaf/action.cpp.o
.PHONY : src/ai/leaf/action.o

# target to build an object file
src/ai/leaf/action.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/leaf/action.cpp.o
.PHONY : src/ai/leaf/action.cpp.o

src/ai/leaf/action.i: src/ai/leaf/action.cpp.i
.PHONY : src/ai/leaf/action.i

# target to preprocess a source file
src/ai/leaf/action.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/leaf/action.cpp.i
.PHONY : src/ai/leaf/action.cpp.i

src/ai/leaf/action.s: src/ai/leaf/action.cpp.s
.PHONY : src/ai/leaf/action.s

# target to generate assembly for a file
src/ai/leaf/action.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/leaf/action.cpp.s
.PHONY : src/ai/leaf/action.cpp.s

src/ai/leaf/condition.o: src/ai/leaf/condition.cpp.o
.PHONY : src/ai/leaf/condition.o

# target to build an object file
src/ai/leaf/condition.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/leaf/condition.cpp.o
.PHONY : src/ai/leaf/condition.cpp.o

src/ai/leaf/condition.i: src/ai/leaf/condition.cpp.i
.PHONY : src/ai/leaf/condition.i

# target to preprocess a source file
src/ai/leaf/condition.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/leaf/condition.cpp.i
.PHONY : src/ai/leaf/condition.cpp.i

src/ai/leaf/condition.s: src/ai/leaf/condition.cpp.s
.PHONY : src/ai/leaf/condition.s

# target to generate assembly for a file
src/ai/leaf/condition.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ai/leaf/condition.cpp.s
.PHONY : src/ai/leaf/condition.cpp.s

src/engine/actor.o: src/engine/actor.cpp.o
.PHONY : src/engine/actor.o

# target to build an object file
src/engine/actor.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/engine/actor.cpp.o
.PHONY : src/engine/actor.cpp.o

src/engine/actor.i: src/engine/actor.cpp.i
.PHONY : src/engine/actor.i

# target to preprocess a source file
src/engine/actor.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/engine/actor.cpp.i
.PHONY : src/engine/actor.cpp.i

src/engine/actor.s: src/engine/actor.cpp.s
.PHONY : src/engine/actor.s

# target to generate assembly for a file
src/engine/actor.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/engine/actor.cpp.s
.PHONY : src/engine/actor.cpp.s

src/engine/agent.o: src/engine/agent.cpp.o
.PHONY : src/engine/agent.o

# target to build an object file
src/engine/agent.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/engine/agent.cpp.o
.PHONY : src/engine/agent.cpp.o

src/engine/agent.i: src/engine/agent.cpp.i
.PHONY : src/engine/agent.i

# target to preprocess a source file
src/engine/agent.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/engine/agent.cpp.i
.PHONY : src/engine/agent.cpp.i

src/engine/agent.s: src/engine/agent.cpp.s
.PHONY : src/engine/agent.s

# target to generate assembly for a file
src/engine/agent.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/engine/agent.cpp.s
.PHONY : src/engine/agent.cpp.s

src/game/game.o: src/game/game.cpp.o
.PHONY : src/game/game.o

# target to build an object file
src/game/game.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/game/game.cpp.o
.PHONY : src/game/game.cpp.o

src/game/game.i: src/game/game.cpp.i
.PHONY : src/game/game.i

# target to preprocess a source file
src/game/game.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/game/game.cpp.i
.PHONY : src/game/game.cpp.i

src/game/game.s: src/game/game.cpp.s
.PHONY : src/game/game.s

# target to generate assembly for a file
src/game/game.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/game/game.cpp.s
.PHONY : src/game/game.cpp.s

src/game/herbivore.o: src/game/herbivore.cpp.o
.PHONY : src/game/herbivore.o

# target to build an object file
src/game/herbivore.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/game/herbivore.cpp.o
.PHONY : src/game/herbivore.cpp.o

src/game/herbivore.i: src/game/herbivore.cpp.i
.PHONY : src/game/herbivore.i

# target to preprocess a source file
src/game/herbivore.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/game/herbivore.cpp.i
.PHONY : src/game/herbivore.cpp.i

src/game/herbivore.s: src/game/herbivore.cpp.s
.PHONY : src/game/herbivore.s

# target to generate assembly for a file
src/game/herbivore.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/game/herbivore.cpp.s
.PHONY : src/game/herbivore.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... main"
	@echo "... src/ai/behavior.o"
	@echo "... src/ai/behavior.i"
	@echo "... src/ai/behavior.s"
	@echo "... src/ai/behavior_tree.o"
	@echo "... src/ai/behavior_tree.i"
	@echo "... src/ai/behavior_tree.s"
	@echo "... src/ai/behavior_tree_builder.o"
	@echo "... src/ai/behavior_tree_builder.i"
	@echo "... src/ai/behavior_tree_builder.s"
	@echo "... src/ai/composite/composite.o"
	@echo "... src/ai/composite/composite.i"
	@echo "... src/ai/composite/composite.s"
	@echo "... src/ai/composite/random.o"
	@echo "... src/ai/composite/random.i"
	@echo "... src/ai/composite/random.s"
	@echo "... src/ai/composite/selector.o"
	@echo "... src/ai/composite/selector.i"
	@echo "... src/ai/composite/selector.s"
	@echo "... src/ai/composite/sequence.o"
	@echo "... src/ai/composite/sequence.i"
	@echo "... src/ai/composite/sequence.s"
	@echo "... src/ai/decorator/decorator.o"
	@echo "... src/ai/decorator/decorator.i"
	@echo "... src/ai/decorator/decorator.s"
	@echo "... src/ai/decorator/invert.o"
	@echo "... src/ai/decorator/invert.i"
	@echo "... src/ai/decorator/invert.s"
	@echo "... src/ai/decorator/repeat.o"
	@echo "... src/ai/decorator/repeat.i"
	@echo "... src/ai/decorator/repeat.s"
	@echo "... src/ai/leaf/action.o"
	@echo "... src/ai/leaf/action.i"
	@echo "... src/ai/leaf/action.s"
	@echo "... src/ai/leaf/condition.o"
	@echo "... src/ai/leaf/condition.i"
	@echo "... src/ai/leaf/condition.s"
	@echo "... src/engine/actor.o"
	@echo "... src/engine/actor.i"
	@echo "... src/engine/actor.s"
	@echo "... src/engine/agent.o"
	@echo "... src/engine/agent.i"
	@echo "... src/engine/agent.s"
	@echo "... src/game/game.o"
	@echo "... src/game/game.i"
	@echo "... src/game/game.s"
	@echo "... src/game/herbivore.o"
	@echo "... src/game/herbivore.i"
	@echo "... src/game/herbivore.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

