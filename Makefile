dirs:=sample1 sample2
SUBDIRS:=$(dirs)
clean_dirs:=$(addprefix _clean_,$(SUBDIRS) )

.PHONY: subdirs clean test $(SUBDIRS) 


$(SUBDIRS):
	$(MAKE) -C $@

$(clean_dirs):
	$(MAKE) -C $(patsubst _clean_%,%,$@) clean


subdirs: $(SUBDIRS)

clean: $(clean_dirs)

test:
	@echo $(SUBDIRS)
	@echo $(clean_dirs)
