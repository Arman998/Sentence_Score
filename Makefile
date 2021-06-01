CC=g++
CFLAGS=-Wall -std=c++14
INCLUDE:=./include
SRCDIR:=./src
DEPDIR:=./obj
OBJDIR:=./obj
SRCS:=$(wildcard $(SRCDIR)/*.cpp)
DEPFILES:=$(SRCS:$(SRCDIR)/%.cpp=$(DEPDIR)/%.dep)
OBJFILES:=$(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.obj)
DEPFLAGS = -MT $@ -MMD -MF $(DEPDIR)/$*.dep
COMPILE = $(CC) $(DEPFLAGS) $(CFLAGS) -I $(INCLUDE) -c

all: run
run: $(OBJFILES)	
	$(CC) $^ -o $@

$(OBJDIR)/%.obj: $(SRCDIR)/%.cpp $(DEPDIR)/%.dep | $(DEPDIR)
	$(COMPILE) $< -o $@

$(DEPDIR):
	mkdir -p $@

$(DEPFILES):
include $(wildcard $(DEPFILES))
clean:
	rm -rf $(OBJDIR) run
