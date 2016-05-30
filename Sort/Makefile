.PHONY:all
all:
	:

.PHONY:clean
clean:
	for dir in `ls -F | grep '/'`;\
    do\
        cd ./$$dir;\
        make clean;\
		cd ..;\
    done
