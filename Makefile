#CC=g++
#CFLAGS=-Wall -std=c++11
#FPIC=-fPIC
#LDFLAGS=-shared 
#INCLUDE:=./include
#SRCDIR:=./src
#DEPDIR:=./obj
#OBJDIR:=./obj
#SRCS:=$(wildcard $(SRCDIR)/*.cpp)
#DEPFILES:=$(SRCS:$(SRCDIR)/%.cpp=$(DEPDIR)/%.dep)
#OBJFILES:=$(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.obj)
#OBJFILES_FOR_SO:=$(filter-out ./obj/main.obj, $(OBJFILES))
#DEPFLAGS = -MT $@ -MMD -MF $(DEPDIR)/$*.dep
#COMPILE = $(CC) $(DEPFLAGS) $(CFLAGS) -I $(INCLUDE) -c
#TESTPATH = ./Tests/TestStopWord/Tmp/
#SO = libSentanceScore.so
#EXE = sentence-score 
#.PHONY: all
#all: $(EXE)

#$(EXE): $(OBJDIR)/main.obj $(SO)
#	$(CC) $< -o $@ -lSentanceScore -L./

#$(SO): $(OBJFILES_FOR_SO)
#	$(CC) $(LDFLAGS) $^ -o $(SO) $(OBJDIR/*.o)

#$(OBJDIR)/%.obj: $(SRCDIR)/%.cpp $(DEPDIR)/%.dep | $(DEPDIR)
#	$(COMPILE) $(FPIC) $< -o $@


#$(DEPDIR):
#	mkdir -p $@

#.PHONY: test1
#test1: $(EXE)


#	make -C $(tests)
#
#$(DEPFILES):
#include $(wildcard $(DEPFILES))
#clean:
#	rm -rf $(OBJDIR) $(SO) sentence-score

export LD_LIBRARY_PATH=./
CC=LD_LIBRARY_PATH=./ g++
CFLAGS=-Wall -std=c++11
FPIC=-fPIC
LDFLAGS=-shared  
INCLUDE:=./include
SRCDIR:=./src
DEPDIR:=./obj
OBJDIR:=./obj
SRCS:=$(wildcard $(SRCDIR)/*.cpp)
DEPFILES:=$(SRCS:$(SRCDIR)/%.cpp=$(DEPDIR)/%.dep)
OBJFILES:=$(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.obj)
OBJFILES_FOR_SO:=$(filter-out ./obj/main.obj, $(OBJFILES))
DEPFLAGS = -MT $@ -MMD -MF $(DEPDIR)/$*.dep
COMPILE = $(CC) $(DEPFLAGS) $(CFLAGS) -I $(INCLUDE) -c
SO = libSentanceScore.so
EXE = sentence-score 
TESTPATH:=./Test/TestStopWord
.PHONY: all
all: $(EXE)

$(EXE): $(OBJDIR)/main.obj $(SO) 
	$(CC) $< -o $@ -lSentanceScore -L./

$(SO): $(OBJFILES_FOR_SO)
	$(CC) $(LDFLAGS) $^ -o  $(SO) $(OBJDIR/*.o)

$(OBJDIR)/%.obj: $(SRCDIR)/%.cpp $(DEPDIR)/%.dep | $(DEPDIR)
	$(COMPILE) $(FPIC) $< -o $@

$(DEPDIR):
	mkdir -p $@

.PHONY: Test

Test: TestStopWord
TestStopWord: $(SO)
	
	$(CC) ./Tests/TestStopWord/*.cpp -lSentanceScore -L./ -I./Tests/TestStopWord/ -I $(INCLUDE) $(CFLAGS) -o $@ 

	#+$(MAKE) -C

$(DEPFILES):
include $(wildcard $(DEPFILES))
clean:
	rm -rf $(OBJDIR) $(SO) TestStopWord  sentence-score
