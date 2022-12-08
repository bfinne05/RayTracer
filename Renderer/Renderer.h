#pragma once
#include "Canvas.h"
#include<SDL.h>
#include "../Math/Ray.h"
#include "../Objects/Sphere.h"
#include "Camera.h"

class Objects;
class Scene;
class Renderer
{ 

public:
	Renderer() = default; 
	void Render(Canvas& canvas, Scene& scene, Camera& camera);

	bool Initialize(); 
	void Shutdown(); 
	bool CreateWindow(int width,int height); 

	void CopyCanvas(const Canvas& canvas);
	void Present();

	friend class Canvas;
private:
	SDL_Window * m_window{nullptr}; 
	SDL_Renderer * m_renderer{nullptr}; 

private:
	color3 GetBackgroundFromRay(const Ray& ray);
};