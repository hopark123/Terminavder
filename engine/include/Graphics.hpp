#pragma once

# include <SDL2/SDL.h>

namespace Tvdr{
	
	class Graphics {
	public :
		static const int SCREEN_WIDTH = 800;
		static const int SCREEN_HEIGHT = 600;
	private :
		static Graphics *sInstance;
		static bool sInitialized;

		SDL_Window *mWindow;
		SDL_Renderer* _renderer;

	public :
		static Graphics *Instance();
		static void Realase();
		static bool Initialized();
		void ClearRenderer();
		void Render();

		static SDL_Texture* GetTextureFromSurface(SDL_Surface* surface);
		static void RenderTexture(SDL_Texture* texture, SDL_Rect* drect, float rotate); 
	private :
		Graphics();
		~Graphics();

		bool Init();
	};
}
