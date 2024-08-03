CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -I./src
SRCDIR = src
OBJDIR = obj
TARGETDIR = build

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))
TARGET = clox
TARGET_PATH = $(TARGETDIR)/$(TARGET)

$(TARGET_PATH): $(OBJECTS) | $(TARGETDIR)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir -p $@

$(TARGETDIR):
	mkdir -p $@

clean:
	rm -rf $(OBJDIR) $(TARGETDIR)

.PHONY: clean
