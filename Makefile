CXX = g++
CXXFLAGS_DEBUG = -Wall -g
CXXFLAGS_OPTIMIZE = -O2

# Source files
SOURCES = LMS.cpp functions.cpp classes.cpp

# Header files
HEADERS = functions.h classes.h

# Output directories
OUTPUT_DIR_DEBUG = debug
OUTPUT_DIR_OPTIMIZE = optimize

# Output filenames
OUTPUT_DEBUG = $(OUTPUT_DIR_DEBUG)/LMS_debug
OUTPUT_OPTIMIZE = $(OUTPUT_DIR_OPTIMIZE)/LMS_optimized

.PHONY: all debug optimize clean

all: debug optimize

debug: $(OUTPUT_DEBUG)

optimize: $(OUTPUT_OPTIMIZE)

# Debug target
$(OUTPUT_DEBUG): $(SOURCES) $(HEADERS)
	@if not exist $(OUTPUT_DIR_DEBUG) mkdir $(OUTPUT_DIR_DEBUG)
	$(CXX) $(CXXFLAGS_DEBUG) $(SOURCES) -o $@

# Optimized target
$(OUTPUT_OPTIMIZE): $(SOURCES) $(HEADERS)
	@if not exist $(OUTPUT_DIR_OPTIMIZE) mkdir $(OUTPUT_DIR_OPTIMIZE)
	$(CXX) $(CXXFLAGS_OPTIMIZE) $(SOURCES) -o $@

clean:
	rm -rf $(OUTPUT_DIR_DEBUG) $(OUTPUT_DIR_OPTIMIZE)

.PHONY: clean