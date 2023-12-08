CXX   	= g++
CCFLAGS = -std=c++17 -Wall -Wextra -Werror -g -Wno-deprecated-declarations

MACINC =  -I/opt/homebrew/include

LINKFLAGS = -L/opt/homebrew/lib -lGL -lglut


# Build directory must be created before running make.
BUILDDIR = build

# Put test executables and main executable here
EXEC = blob_game

RUN = blob_game

# Put dependent object builds here.
OBJS = 	$(BUILDDIR)/npc.o	\
		$(BUILDDIR)/player.o\
		$(BUILDDIR)/Vec2.o  \
		$(BUILDDIR)/Game.o  \
		$(BUILDDIR)/Basics.o

.PHONY: clean

all: $(EXEC) $(OBJS)

mac-run:
	@Xquartz &
	@sleep 1
	@DISPLAY=:0 ./build/$(RUN)

csil-run:
	./build/$(RUN)

ifeq "$(SYS)" "mac"
%: src/%.cpp $(OBJS)
	${CXX} $(CCFLAGS) $(MACINC) $(LINKFLAGS) -o $(BUILDDIR)/$@ $^

$(BUILDDIR)/%.o: src/lib/%.cpp
	$(CXX) $(CCFLAGS) $(MACINC) -c $< -o $@
endif

ifeq "$(SYS)" "csil"
%: src/%.cpp $(OBJS)
	${CXX} $(CCFLAGS) $(LINKFLAGS) -o $(BUILDDIR)/$@ $^

$(BUILDDIR)/%.o: src/lib/%.cpp
	$(CXX) $(CCFLAGS) -c $< -o $@
endif

clean:
	rm -r $(BUILDDIR)/*
