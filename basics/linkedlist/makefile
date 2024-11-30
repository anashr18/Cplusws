# Variables
BUILD_DIR = build
EXECUTABLE = exec

# Default target
all: clean configure build run

# Clean target
clean:
	rm -rf $(BUILD_DIR)

# Configure target
configure:
	mkdir $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake ..

# Build target
build:
	cd $(BUILD_DIR) && cmake --build .

# Run target
run:
	@echo "Running executable: $(EXECUTABLE)"
	@cd $(BUILD_DIR) && ./$(EXECUTABLE)

# Phony targets
.PHONY: all clean configure build run
