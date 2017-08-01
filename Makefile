CFLAGS=-std=c11 -ggdb -O2 -Weverything -Wno-missing-field-initializers
LDFLAGS=-lvulkan
OUT=vk

all: $(OUT)

.PHONY: clean

clean:
	$(RM) $(OUT)
	$(RM) *.o

$(OUT): vk.c Makefile
	clang $(CFLAGS) $< -o $@ $(LDFLAGS)

