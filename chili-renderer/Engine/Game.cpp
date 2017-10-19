#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd ) : wnd( wnd ), gfx( wnd )
{}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

int shipXPos = 400;
int shipYPos = 300;
int shipSpeed = 8;
int shipLenght = 20;
int shotYLenght = 10;

bool isShoting = false;
int shotYPos = shipYPos;
int shotXPos = shipXPos + shipLenght / 2;
int shotSpeed = 30;
int shotLenght = 10;

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		int nextPos = shipYPos - shipSpeed;
		if (nextPos < 0)
		{
			return;
		}
		shipYPos = nextPos;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		int nextPos = shipYPos + shipSpeed;
		if (nextPos + shipLenght >= 600)
		{
			return;
		}
		shipYPos = nextPos;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{

		int nextPos = shipXPos - shipSpeed;
		if (nextPos < 0)
		{
			return;
		}
		shipXPos = nextPos;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		int nextPos = shipXPos + shipSpeed;
		if (nextPos + shipLenght >= 800)
		{
			return;
		}
		shipXPos = nextPos;
	}

	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		isShoting = true;
	}
}
void Game::ComposeFrame()
{
	int scopedXPos = shipXPos;
	int scopedYPos = shipYPos;
	for (int i = 0; i < shipLenght; i++) {
		gfx.PutPixel(shipXPos + i, shipYPos, 255, 255, 255);
		gfx.PutPixel(scopedXPos, shipYPos + i, 255, 255, 255);
		gfx.PutPixel(shipXPos + i, scopedYPos + shipLenght, 255, 255, 255);
		gfx.PutPixel(scopedXPos + shipLenght, shipYPos + i, 255, 255, 255);
	}

	if (isShoting)
	{
		for (int i = 0; i < shotLenght; i++) {
			gfx.PutPixel(shotXPos, shotYPos - i, 255, 0, 0);
		}
		int nextPosition = shotYPos - shotSpeed;
		if (nextPosition > 1)
		{ 
			shotYPos = nextPosition;
		}
	}

}


