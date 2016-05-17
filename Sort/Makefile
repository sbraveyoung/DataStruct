.PHONY:all
all:
	for dir in `ls -F | grep '/$$'`;\
	do\
		cd ./$$dir;\
		make;\
		cd ..;\
	done


.PHONY:clean
clean:
	for dir in `ls -F | grep '/$$'`;\
	do\
		cd ./$$dir;\
		make clean;\
		cd ..;\
	done
