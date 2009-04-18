include common.mk
.PHONY: copy
.PHONY: clean

all: copy $(X_OBJS)
	mkdir -p ./mingw.org
	"./lc_test.sh" "$(X_OBJS)"

clean:
	@rm -f *.o *.exe
	@rm -f *.c
	@rm -rf ./mingw.org

copy:
	cp $(C_OBJS) .
	
$(X_OBJS): $(C_OBJS)
	gcc $< -o $@


