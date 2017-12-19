/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		gb = 0;
	}
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (InhibitUp)
		{ }
		else
		{
			vy = vy - 1;
			InhibitUp = true;
		}
	}
	else
	{
		InhibitUp = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (InhibitDown)
		{
		}
		else
		{
			vy = vy + 1;
			InhibitDown = true;
		}
	}
	else
	{
		InhibitDown = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (InhibitRight)
		{
		}
		else
		{
			vx = vx + 1;
			InhibitRight = true;
		}
	}
	else
	{
		InhibitRight = false;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (InhibitLeft)
		{
		}
		else
		{
			vx = vx - 1;
			InhibitLeft = true;
		}
	}
	else
	{
		InhibitLeft = false;
	}
	x = x + vx;
	y = y + vy;
	if (x < 6)
	{
		x = 6;
		vx = 0;
	}
	if (x > gfx.ScreenWidth - 7)
	{
		x = gfx.ScreenWidth - 7;
		vx = 0;
	}
	if (y < 6)
	{
		y = 6;
		vy = 0;
	}
	if (y > gfx.ScreenHeight - 7)
	{
		y = gfx.ScreenHeight - 7;
		vy = 0;
	}
	
	Shape_Is_Changed = (wnd.kbd.KeyIsPressed( VK_SHIFT ));

	if (x > a - 10 && x < a + 10 && y > b - 10 && y < b + 10)
	{
		gb = 0;
		rb = 0;
	}
	else
	{
		gb = 255;
		rb = 255;
	}
	if (wnd.kbd.KeyIsPressed( 'W' ))
	{
		if (InhibitW)
		{
		}
		else
		{
			vb = vb - 1;
			InhibitW = true;
		}
	}
	else
	{
		InhibitW = false;
	}
	if (wnd.kbd.KeyIsPressed( 'S' ))
	{
		if (InhibitS)
		{
		}
		else
		{
			vb = vb + 1;
			InhibitS = true;
		}
	}
	else
	{
		InhibitS = false;
	}
	if (wnd.kbd.KeyIsPressed( 'D' ))
	{
		if (InhibitD)
		{
		}
		else
		{
			va = va + 1;
			InhibitD = true;
		}
	}
	else
	{
		InhibitD = false;
	}
	if (wnd.kbd.KeyIsPressed( 'A' ))
	{
		if (InhibitA)
		{
		}
		else
		{
			va = va - 1;
			InhibitA = true;
		}
	}
	else
	{
		InhibitA = false;
	}
	a = a + va;
	b = b + vb;
	if (a < 6)
	{
		a = 6;
		va = 0;
	}
	if (a > gfx.ScreenWidth - 7)
	{
		a = gfx.ScreenWidth - 7;
		va = 0;
	}
	if (b < 6)
	{
		b = 6;
		vb = 0;
	}
	if (b > gfx.ScreenHeight - 7)
	{
		b = gfx.ScreenHeight - 7;
		vb = 0;
	}
	ShapeIsChanged = (wnd.kbd.KeyIsPressed( 'Z' ));

}

void Game::ComposeFrame()
{
	if (Shape_Is_Changed)
	{
		gfx.DrawRTri(x-5, y-5, 11, 255, gb, gb);
	}
	else
	{
		gfx.DrawRecticle(x, y, 255, gb, gb);
	}
	
	if (ShapeIsChanged)
	{
		gfx.DrawRTri(a - 5, b - 5, 11, rb, 255, rb);
	}
	else
	{
		gfx.DrawBox(a, b, rb, 255, rb);
	}
}
