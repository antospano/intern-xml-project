guide:
	@echo ARG 1 - FIGURE:
	@echo 1 = SPHERE
	@echo 2 = BLOCK
	@echo 3 = CYLINDER
	@echo ARG 2, 3, 4:
	@echo POS X, Y, Z
	@echo ARG 5, 6, 7:
	@echo DIM X, Y, Z
	@echo OTHER ARGS:
	@echo RADIUS, COLOR

build:
	@g++ -std=c++11 File/file.cpp -c
	@mv file.o obj
	@g++ -std=c++11 main.cpp obj/file.o libtinyxml2.a -o out
	@mv out builds

run:
	@./builds/out $(FIGURA) $(XPOS) $(YPOS) $(ZPOS) $(RADIUS) $(XDIM) $(YDIM) $(ZDIM) $(COLOR)