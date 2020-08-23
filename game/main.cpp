#include <iostream>
#include <SDL.h>

#include "color.h"
#include "dimension.h"
#include "window.h"
#include "renderer.h"
#include "point.h"

const Color white(0xFF,0xFF,0xFF,0xFF);
const Color black(0,0,0,0xFF);

const int rsize = 10;
const int columns = 100;
const int lines = 100;
int tickRate = 300;
int refreshRate = 33;
bool quit = false;
bool pause = false;

const Point origin(0,0);
const Dimension d(rsize * columns, rsize * lines);

bool buffer1[columns * lines];
bool buffer2[columns * lines];
bool *current_buffer;
bool *next_buffer;

void swapBuffers() {
	bool *temp = current_buffer;
	current_buffer = next_buffer;
	next_buffer = temp;
}

bool getValueAt(bool *buffer,int column, int line) {
	if (column >= 0 && column < columns && line >= 0 && line < lines) {
		return buffer[line * columns + column];
	} else {
		return false;
	}
}

void setValueAt(bool *buffer,int column, int line, bool value) {
	if (column >= 0 && column < columns && line >= 0 && line < lines) {
		buffer[line * columns + column] = value;
	}
}

uint32_t getNumberOfNeighbour(bool *buffer,int column, int line) {
	int total_neighbour = 0;
	for (int column_offset = -1; column_offset <=1 ; column_offset++) {
		for (int line_offset = -1; line_offset <=1 ; line_offset++) {
				bool value = getValueAt(buffer, column + column_offset, line + line_offset) && (line_offset != 0 || column_offset != 0);
				if (value) total_neighbour++;
		}
	}
	return total_neighbour;
}


void update(uint32_t elapsed) {	
	for (int column = 0 ; column < columns ; column++) {
		for (int line = 0 ; line < lines ; line++ ) {
			bool value = getValueAt(current_buffer, column, line);
			int neighbour = getNumberOfNeighbour(current_buffer, column, line);
			bool nextValue = (neighbour == 3) || (value && neighbour == 2);
			setValueAt(next_buffer, column, line, nextValue);
		}
	}
	swapBuffers();
}

void paint(Renderer &renderer){
	Rectangle r(0,0,rsize,rsize);
	for (int column = 0 ; column < columns ; column++) {
		for (int line = 0 ; line < lines ;line++ ) {
			r.move(column * rsize, line* rsize);
			bool value = getValueAt(current_buffer, column, line);
			renderer.setColor(value ? white : black);
			renderer.fillRect(r);
		}
	}
}


void processInput() {
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT) {
			quit = true;
		} else if (e.type == SDL_KEYDOWN) {
			switch (e.key.keysym.sym)
			{
			case SDLK_p:
				pause = !pause;
				break;
			
			case SDLK_KP_PLUS:
				if (tickRate > 20) tickRate -= 20;
				break;
			
			case SDLK_KP_MINUS:
				tickRate += 20;
				break;
			
			case SDLK_u:
				if (pause) update(0);
				break;

			default:
				break;
			}
		} else if (e.type == SDL_MOUSEBUTTONDOWN) {
			int x, y;
			SDL_GetMouseState(&x, &y);

			int column = x / rsize;
			int line = y / rsize;

			bool value = getValueAt(current_buffer, column, line);
			setValueAt(current_buffer, column, line, !value);
		}
	}
	
}

void init() {
	memset(buffer1,0,(lines * columns) * sizeof(bool)); 
	memset(buffer2,0,(lines * columns) * sizeof(bool)); 

	current_buffer = buffer1;
	next_buffer = buffer2;
}

int main() {
	srand( (unsigned)time( NULL ) );
	init();

	Window w("Pokemon", origin, d);
	Renderer renderer(w.getWindow());

	uint32_t current = SDL_GetTicks();
	uint32_t elapsed = 0;

	uint32_t currentRR = SDL_GetTicks();
	uint32_t elapsedRR = 0;
	

	while (!quit)
	{
		processInput();
		if (elapsed > tickRate && !pause) {
			update(elapsed);
			current = SDL_GetTicks();
		}

		if (elapsedRR > refreshRate) {
			currentRR = SDL_GetTicks();
			renderer.setColor(black);
			renderer.clear();
			paint(renderer);
			renderer.show();
		}
		elapsed = SDL_GetTicks() - current;
		elapsedRR = SDL_GetTicks() - currentRR;
	}
	
	return 0;
}