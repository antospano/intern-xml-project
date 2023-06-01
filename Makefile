CC = g++
CFLAGS = -std=c++11 -Wall
LDFLAGS = src/XML/libtinyxml2.a

SRCDIR = src
OBJDIR = obj

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))
EXECUTABLE = builds/out

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(EXECUTABLE)

.PHONY: all clean

# Include the dependency files
-include $(OBJECTS:.o=.d)

# Generate dependency files
$(OBJDIR)/%.d: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MM -MT $(@:.d=.o) $< -MF $@

run:
	$(EXECUTABLE) $(FIGURA) $(XPOS) $(YPOS) $(ZPOS) $(RADIUS) $(XDIM) $(YDIM) $(ZDIM) $(COLOR)

guide:
	@echo ARG 1 - FIGURE:
	@echo 1 = SPHERE
	@echo 2 = BLOCK
	@echo 3 = CYLINDER
	@echo ARG 2, 3, 4:
	@echo POS X, Y, Z
	@echo ARG 5, 6, 7:
	@echo DIM X, Y, Z
	@echo OTHER ARGS:
	@echo RADIUS, COLOR