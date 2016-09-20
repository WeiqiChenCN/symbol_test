.PHONY: all
all: subdirs

.PHONY: subdirs clean

dirs:=sample1 sample2
make_dirs:=$(addprefix _make_,$(dirs) )
clean_dirs:=$(addprefix _clean_,$(dirs) )


$(make_dirs):
	$(MAKE) -C $(patsubst _make_%,%,$@)

$(clean_dirs):
	$(MAKE) -C $(patsubst _clean_%,%,$@) clean


subdirs: $(make_dirs)

clean: $(clean_dirs)

test:
	@echo $(make_dirs)
	@echo $(clean_dirs)
