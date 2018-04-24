bin_tree:bin_tree.c seqqueue.c
	gcc -g $^ -o $@

.PHONY:clean
	clean:
		rm bin_tree
