.PHONY: all clean info
DIRS = lib/code_r lib/code_v src/code_view_side

all:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d; \
	done

clean:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d clean; \
	done

info:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d info; \
	done
