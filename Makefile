guide:
	@echo FIGURA
	@echo 1 = SPHERE
	@echo 2 = BLOCK
	@echo 3 = CYLINDER

build:
	@g++ -std=c++11 File/file.cpp -c
	@mv file.o obj
	@g++ -std=c++11 main.cpp obj/file.o -o out
	@mv out builds

run:
	@./run.sh $(FIGURA) $(XPOS) $(YPOS) $(ZPOS) $(XDIM) $(YDIM) $(ZDIM) $(RADIUS)