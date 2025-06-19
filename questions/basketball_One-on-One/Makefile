CC = g++
CFLAGS = -std=c++20 -lm -I.
CFLAGS_DEBUG = -std=c++20 -Og -g3 -Wall -I. -fsanitize=address -fsanitize=leak -fsanitize=undefined

# Default target
help:
	@echo "Usage:"
	@echo "  make <letter>        - Compiles letter.cpp to executable 'letter'"
	@echo "  make debug <letter>  - Compiles letter.cpp with debug flags to 'letter-debug'"
	@echo "  make clean           - Removes all generated executables"

# Pattern rule for normal compilation
%: %.cpp
	$(CC) $(CFLAGS) $< -o $@

# Pattern rule for debug compilation
%-debug: %.cpp
	$(CC) $(CFLAGS_DEBUG) $< -o $@

# Handle debug target with arguments
ifneq (,$(filter debug,$(MAKECMDGOALS)))
# Get the arguments after debug
DEBUG_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
# Mark them as phony
.PHONY: $(DEBUG_ARGS)
# Don't try to build them as targets
$(DEBUG_ARGS):
	@true
# The actual debug target depends on the debug versions
debug: $(addsuffix -debug,$(DEBUG_ARGS))
endif

# Clean rule
clean:
	rm -f *-debug
	rm -f *-combined*
	find . -maxdepth 1 -type f -executable ! -name 'atcoder*' ! -name 'build.sh' ! -name 'expander.py' -exec rm -f {} +

.PHONY: help clean debug
