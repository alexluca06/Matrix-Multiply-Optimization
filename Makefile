build:
		gcc classic_method.c -o classic_method
		gcc cache_optimization++.c -o cache_optimization++
		gcc reorder_loops.c -o reorder_loops

run:
		./classic_method
		./cache_optimization++
		./reorder_loops

clean:
		rm classic_method 
		rm cache_optimization++
		rm reorder_loops				