#ifndef IWINDOW_H
#define IWINDOW_H

class IWindow {
	public:
		virtual IRenderer createRenderer(int index, uint32_t flags) = 0;
		virtual bool isTargetSupported(IRenderer &renderer) = 0;
}

#endif
