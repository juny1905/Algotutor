.PHONY: all clean info
DIRS = lib/code_r lib/code_v src/code_view_side src/ src/ui

all:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d; \
	done
	@$(MAKE) -C ./src/

clean:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d clean; \
	done
	@$(MAKE) -C ./src/ clean;

info:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d info; \
	done
