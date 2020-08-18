#include <iostream>

#include "color.h"
#include "dimension.h"
#include "window.h"
#include "renderer.h"
#include "point.h"

Color white(0xFF,0xFF,0xFF,0xFF);
Color black(0,0,0,0xFF);

int rsize = 10;
const int columns = 64;
const int lines = 64;

Point origin(0,0);
Dimension d(rsize * columns, rsize * lines);

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
			if (line_offset != 0 || column_offset != 0) {
				bool value = getValueAt(buffer, column + column_offset, line + line_offset);
				if (value) total_neighbour++;
			}
		}
	}
	return total_neighbour;
}

bool update(uint32_t elapsed) {
	if (elapsed > 40) {
		for (int column = 0 ; column < columns ; column++) {
			for (int line = 0 ; line < lines ; line++ ) {
				bool value = getValueAt(current_buffer, column, line);
				int neighbour = getNumberOfNeighbour(current_buffer, column, line);
				bool nextValue = (neighbour == 3) || (value && neighbour == 2);
				setValueAt(next_buffer, column, line, nextValue);
			}
		}
		swapBuffers();
		return true;
	}
	return false;
}

void paint(Renderer &renderer){
		for (int column = 0 ; column < columns ; column++) {
			for (int line = 0 ; line < lines ; line++ ) {
				Rectangle r(column * rsize, line * rsize , rsize, rsize);
				bool value = getValueAt(current_buffer, column, line);
				renderer.setColor(value ? white : black);
				renderer.fillRect(r);
			}
		}

}

void init() {
	memset(buffer1,0,(lines * columns) * sizeof(bool)); 
	memset(buffer2,0,(lines * columns) * sizeof(bool)); 

	current_buffer = buffer1;
	next_buffer = buffer2;
	
	setValueAt(current_buffer, 10+0,10+0,true);
	setValueAt(current_buffer, 10+3,10+0,true);
	setValueAt(current_buffer, 10+4,10+1,true);
	setValueAt(current_buffer, 10+0,10+2,true);
	setValueAt(current_buffer, 10+4,10+2,true);
	setValueAt(current_buffer, 10+1,10+3,true);
	setValueAt(current_buffer, 10+2,10+3,true);
	setValueAt(current_buffer, 10+3,10+3,true);
	setValueAt(current_buffer, 10+4,10+3,true);
}

int main() {
	init();

	Window w("Pokemon", origin, d);
	Renderer renderer(w.getWindow());

	uint32_t start = 0;
	uint32_t end = 0;
	uint32_t elapsed = 0;
	uint32_t total_elapsed = 0;


	while (end < 10000)
	{
		start = SDL_GetTicks();
		if (update(total_elapsed)) {
			renderer.setColor(Color(0,0,0,0xFF));
			renderer.clear();
			paint(renderer);
			renderer.show();
			total_elapsed = 0;
		}
		end = SDL_GetTicks();
		elapsed = end - start;
		total_elapsed += elapsed;
	}
	
	return 0;
}